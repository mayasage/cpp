#include <iostream>

#include "print.hpp"

// enum class Month
// {
//   Jan, // 0
//   Feb, // 1
//   Mar,
//   Apr,
//   May,
//   Jun,
//   Jul,
//   Aug,
//   Sep,
//   Oct,
//   Nov,
//   Dec // 11
// };

enum class Month
{
  Jan = -1,     // -1
  January = -1, // -1
  Feb,          // 0
  Mar,          // 1
  Apr,
  May, // 3
  // June = Jun, // error: Jun is undefined.
  Jun = 18, // 18
  June = Jun,
  Jul, // 19
  Aug,
  Sep,
  Oct,
  Nov,
  Dec, // 24
  // Dec = 69, // error: redeclaration of ‘Dec’
  // Dec = 9'999'999'999'999'999
  /**
   * error: enumerator value ‘9999999999999999’ is outside the range of
   * underlying type ‘int’
   */
};

enum class Month1
{
  Jan,
  Feb,
  Mar,
  Apr,
  May,
  Jun,
  Jul,
  Aug,
  Sep,
  Oct,
  Nov,
  Dec
};

/* Change enum data type */

// enum class Month : unsigned char
// error: multiple definition of ‘enum class Month’

// enum class Month_String : std::string
/**
 * error: underlying type ‘std::string’
 * {aka ‘std::__cxx11::basic_string<char>’} of ‘Month_String’ must be an
 * integral type
 */
enum class Month_Char : unsigned char
{
  Jan,           // 0
  January = Jan, // 1
  Feb,
  Mar,
  Apr,
  May,
  Jun,
  June = Jun,
  Jul,
  Aug,
  Sep,
  Oct,
  Nov,
  Dec, // 11
  // Dec = 300,
  /**
   * error: enumerator value ‘300’ is outside the range of underlying type
   * ‘unsigned char’
   *
   * error: redeclaration of ‘Dec’
   */
};

enum class DayOfWeek
{
  Monday = 1,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

enum class Gender
{
  Female,
  Male
};

void print_day(DayOfWeek day)
{
  switch (day)
  {
  case DayOfWeek::Monday:
    std::cout << "Today is Monday";
    break;

  case DayOfWeek::Tuesday:
    std::cout << "Today is Tuesday";
    break;

  case DayOfWeek::Wednesday:
    std::cout << "Today is Wednesday";
    break;

  case DayOfWeek::Thursday:
    std::cout << "Today is Thursday";
    break;

  case DayOfWeek::Friday:
    std::cout << "Today is Friday";
    break;

  case DayOfWeek::Saturday:
    std::cout << "Today is Saturday";

  case DayOfWeek::Sunday:
    std::cout << "Today is Sunday";
    break;

  default:
    std::cout << "No day";
  }
}

/* Using enum */

std::string_view month_to_string(Month1 month)
{
  switch (month)
  {
  // Works
  case Month1::Jan:
    return "January";

  case Month1::Feb:
    return "February";

  case Month1::Mar:
    return "March";

  case Month1::Apr:
    return "April";

  case Month1::May:
    return "May";

  case Month1::Jun:
    return "June";

  case Month1::Jul:
    return "July";

  case Month1::Aug:
    return "August";

  case Month1::Sep:
    return "September";

  case Month1::Oct:
    return "October";

  case Month1::Nov:
    return "November";

  case Month1::Dec:
    return "December";

  default:
    return "None";

    /**
     * Should be working in C++20.
     *
     * However, GCC-10 doesn't support this yet.
     * Clang-12 doesn't support it either.
     *
     * Supported on:
     * GCC-11
     * MSVC2019
     */

    // using enum Month1;

    // case Jan:
    //   return "January";

    // case Feb:
    //   return "February";

    // case Mar:
    //   return "March";

    // case Apr:
    //   return "April";

    // case May:
    //   return "May";

    // case Jun:
    //   return "June";

    // case Jul:
    //   return "July";

    // case Aug:
    //   return "August";

    // case Sep:
    //   return "September";

    // case Oct:
    //   return "October";

    // case Nov:
    //   return "November";

    // case Dec:
    //   return "December";

    // default:
    //   return "None";
  }
}

int main()
{
  Month month{Month::Mar};

  prn(sizeof(month));       // 4
  prn(sizeof(Month));       // 4
  prn(sizeof(Month_Char));  // 1
  prnn(sizeof(Month_Char)); // 1

  // prn(month); // error, can't print

  // prn(static_cast<int>(month));3

  pcn_row("Jan : ", static_cast<int>(Month::Jan));         // -1
  pcn_row("January : ", static_cast<int>(Month::January)); // -1
  pcn_row("Feb : ", static_cast<int>(Month::Feb));         // 0
  pcn_row("May : ", static_cast<int>(Month::May));         // 3
  pcn_row("Jun : ", static_cast<int>(Month::Jun));         // 18
  pcn_row("June : ", static_cast<int>(Month::June));       // 18
  pcn_row("Dec : ", static_cast<int>(Month::Dec));         // 24

  pn();

  pcn_row("Jan : ", static_cast<int>(Month_Char::Jan));         // -1
  pcn_row("January : ", static_cast<int>(Month_Char::January)); // -1
  pcn_row("Feb : ", static_cast<int>(Month_Char::Feb));         // 0
  pcn_row("May : ", static_cast<int>(Month_Char::May));         // 3
  pcn_row("Jun : ", static_cast<int>(Month_Char::Jun));         // 18
  pcn_row("June : ", static_cast<int>(Month_Char::June));       // 18
  pcn_row("Dec : ", static_cast<int>(Month_Char::Dec));         // 24

  /* No rounding */

  Month_Char month_exceed{12};

  nprn(month_exceed == Month_Char::Jan); // false. doesn't round

  /* No kind of Implicit conversion is allowed with Enums */

  pn();

  /* These are not implicit conversions. */

  DayOfWeek day1{Gender::Female}; // Works
  print_day(day1);                // No Day

  pn();

  DayOfWeek day2{Gender::Male}; // Works
  print_day(day2);              // Today is Monday

  /* These are implicit conversions. */

  // print_day(Gender::Female);
  // print_day(Gender::Male);
  /**
   * error: cannot convert ‘Gender’ to ‘DayOfWeek’
   */

  // print_day(static_cast<int>(Gender::Female));
  // print_day(static_cast<int>(Gender::Male));
  // print_day(3);
  /**
   * error: cannot convert ‘int’ to ‘DayOfWeek’
   */

  pn();

  Month1 month1{Month1::Apr};
  std::cout << "month : " << month_to_string(month1) << std::endl;

  /* Legacy/Old Enums (Not Recommended) */

  enum Direction : unsigned char
  {
    TopLeft,
    TopRight,
    Center,
    BottomLeft,
    BottomRight
  };

  enum Tool
  {
    Pen,
    Marker,
    Eraser,
    Rectangle,
    Circle,
    PaintBucket
  };

  enum class Direction1 : unsigned char
  {
    TopLeft,
    TopRight,
    Center,
    BottomLeft,
    BottomRight
  };

  enum class Tool1
  {
    Pen,
    Marker,
    Eraser,
    Rectangle,
    Circle,
    PaintBucket
  };

  prn(Direction::TopLeft); // Printing works.
  // prn(Direction1::TopLeft); // error: can't print

  prn(Direction::TopLeft < Tool::Pen); // Comparison works.
  // prn(Direction1::TopLeft > Tool1::Pen);
  /**
   * error: no match for
   * ‘operator==’ (operand types are ‘main()::Direction1’ and ‘main()::Tool1’)
   */

  prn(Direction::TopLeft > 0); // Works
  // prn(Direction1::TopLeft < 0);
  /**
   * error: no match for
   * ‘operator==’ (operand types are ‘main()::Direction1’ and ‘int’)
   */

  return 0;
}
