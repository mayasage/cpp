#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

const unsigned int DAYS_IN_A_WEEK = 7;
const unsigned int MONTHS_IN_A_YEAR = 12;

std::string getDayName(unsigned int);
std::string getMonthName(unsigned int);
void print_calendar(unsigned int, unsigned int);
unsigned int get_row_count(unsigned int, unsigned int);
unsigned int get_first_day_of_next_month(unsigned int, unsigned int);

// Returns space used -> [ gap, column, total ]
std::vector<unsigned int> print_calendar_heading(unsigned int, unsigned int);

unsigned int print_calendar_month(
    unsigned int, unsigned int, unsigned int, std::vector<unsigned int>);

unsigned int get_num_days_in_month(unsigned int, unsigned int);
bool is_leap_year(unsigned int);
void print_matrix(std::vector<std::vector<unsigned int>>);

int main()
{
  unsigned int year;
  unsigned int first_day_of_year;

  // Get input
  std::cout
      << "Enter a year : ";
  std::cin >> year;

  std::cout << "Enter the first day of the year [1: Monday, ... 7: Sunday] : ";
  std::cin >> first_day_of_year;

  print_calendar(year, first_day_of_year);

  return 0;
}

std::string getDayName(unsigned int day)
{
  std::string result;

  switch (day)
  {
  case 1:
    result = "Monday";
    break;
  case 2:
    result = "Tuesday";
    break;
  case 3:
    result = "Wednesday";
    break;
  case 4:
    result = "Thursday";
    break;
  case 5:
    result = "Friday";
    break;
  case 6:
    result = "Saturday";
    break;
  case 7:
    result = "Sunday";
    break;
  default:
    result = "";
    break;
  }

  return result;
}

std::string getMonthName(unsigned int month)
{
  std::string result;

  switch (month)
  {
  case 1:
    result = "January";
    break;
  case 2:
    result = "Febraury";
    break;
  case 3:
    result = "March";
    break;
  case 4:
    result = "April";
    break;
  case 5:
    result = "May";
    break;
  case 6:
    result = "June";
    break;
  case 7:
    result = "July";
    break;
  case 8:
    result = "August";
    break;
  case 9:
    result = "September";
    break;
  case 10:
    result = "October";
    break;
  case 11:
    result = "November";
    break;
  case 12:
    result = "December";
    break;
  default:
    result = "";
    break;
  }

  return result;
};

void print_matrix(std::vector<std::vector<unsigned int>> m)
{
  for (std::vector r : m)
  {
    for (unsigned int c : r)
    {
      std::cout << c;
    }

    std::cout << std::endl;
  }
};

void print_calendar(unsigned int year, unsigned int first_day_of_year)
{
  std::cout
      << std::endl
      << "Calendar for "
      << year
      << std::endl;

  unsigned int start_day{first_day_of_year};

  for (unsigned int i{1}; i <= MONTHS_IN_A_YEAR; i++)
  {
    std::vector<unsigned int> space_info = print_calendar_heading(year, i);

    // std::cout
    //     << std::endl
    //     << "i : "
    //     << i
    //     << std::endl
    //     << "year : "
    //     << year
    //     << std::endl
    //     << "start_day : "
    //     << start_day
    //     << std::endl;

    start_day = print_calendar_month(i, year, start_day, space_info);
  }
}

std::vector<unsigned int> print_calendar_heading(
    unsigned int year,
    unsigned int month)
{
  std::vector<unsigned int> space_info(3, 0);

  const unsigned int num_cols{7};

  const unsigned int gapw = 3;
  const unsigned int colw = 3;
  const unsigned int totalw = (colw * num_cols) + (gapw * num_cols);

  space_info.at(0) = gapw;
  space_info.at(1) = colw;
  space_info.at(2) = totalw;

  const std::string days[] = {
      "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

  std::cout
      << "--"
      << getMonthName(month)
      << " "
      << year
      << " --"
      << std::endl;

  for (std::string day : days)
  {
    std::cout
        << std::string(gapw, ' ')
        << day;
  }

  std::cout
      << std::endl;

  return space_info;
}

unsigned int print_calendar_month(
    unsigned int month,
    unsigned int year,
    unsigned int first_day_of_month,
    std::vector<unsigned int> space_info)
{
  const unsigned int gapw = space_info.at(0);
  const unsigned int colw = space_info.at(1);
  const unsigned int totalw = space_info.at(2);

  const unsigned int skipw = ((gapw * (first_day_of_month - 1)) +
                              (colw * (first_day_of_month - 1)));

  // std::cout << std::endl
  //           << " ----- SKIPW : " << skipw << std::endl;

  std::cout
      << std::string(skipw, ' ');

  // std::cout
  //     << std::endl
  //     // << "last_day : "
  //     // << last_day
  //     // << std::endl
  //     // << "day_count : "
  //     // << day_count
  //     << std::endl
  //     << "gapw, colw, totalw, skipw : "
  //     << gapw
  //     << ", "
  //     << colw
  //     << ", "
  //     << totalw
  //     << ", "
  //     << skipw
  //     << std::endl;

  // std::cout
  //     << std::endl
  //     << "-- ENTER THE DRAGON ---"
  //     << std::endl;

  const unsigned int days_in_month = get_num_days_in_month(month, year);
  const unsigned int total_rows = get_row_count(days_in_month, first_day_of_month);

  // unsigned int last_day{first_day_of_month};
  unsigned int day_count{1};

  // std::cout
  //     << std::endl
  //     << "last_day : "
  //     << last_day
  //     << std::endl
  //     << "day_count : "
  //     << day_count
  //     << std::endl
  //     << "gapw, colw, totalw, skipw : "
  //     << gapw
  //     << ", "
  //     << colw
  //     << ", "
  //     << totalw
  //     << ", "
  //     << skipw
  //     << std::endl;

  // std::cout
  //     << std::endl
  //     << "--- TOTAL ROWS : "
  //     << total_rows
  //     << " ---"
  //     << std::endl;

  for (unsigned int r{1}; r <= total_rows; r++)
  {
    for (
        unsigned int c{(r == 1) ? first_day_of_month : 1};
        c <= DAYS_IN_A_WEEK && day_count <= days_in_month;
        c++)
    {
      std::cout
          << std::string(gapw, ' ')
          << std::setw(colw)
          << day_count;

      day_count++;
      // last_day = ((last_day + 1) % DAYS_IN_A_WEEK);
      // if (last_day == 0)
      // {
      //   last_day = 7;
      // }
    }

    std::cout
        << std::endl;

    if (day_count > days_in_month)
    {
      break;
    }
  }

  std::cout
      << std::endl;

  return get_first_day_of_next_month(days_in_month, first_day_of_month);
}

bool is_leap_year(unsigned int year)
{
  bool result;

  if (year % 400 == 0)
  {
    result = true;
  }
  else if (year % 100 == 0)
  {
    result = false;
  }
  else if (year % 4 == 0)
  {
    result = true;
  }
  else
  {
    result = false;
  }

  return result;
}

unsigned int get_num_days_in_month(unsigned int month, unsigned int year)
{
  unsigned int result{};

  switch (month)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    // Jan, Mar, May, July, Aug, Oct, Dec
    result = 31;
    break;

  case 2:
  {
    // Feb
    bool is_ly = is_leap_year(year);
    result = is_ly ? 29 : 28;
    break;
  }

  case 4:
  case 6:
  case 9:
  case 11:
    // Apr, Jun, Sep, Nov,
    result = 30;
    break;
  }

  return result;
}

unsigned int get_row_count(
    unsigned int total_entries,
    unsigned int first_day_of_month)
{
  const unsigned int max_entries_per_row = DAYS_IN_A_WEEK;

  const unsigned int entries_in_first_row = max_entries_per_row - first_day_of_month + 1;

  unsigned int remaining_entries = total_entries - entries_in_first_row;

  unsigned int total_rows = (1 + // first row
                             static_cast<unsigned int>(
                                 ceil(
                                     static_cast<double>(remaining_entries) /
                                     max_entries_per_row)));

  // std::cout
  //     << std::endl
  //     << "--- total_entries : "
  //     << total_entries
  //     << " ---"
  //     << std::endl
  //     << "--- first_day_of_month : "
  //     << first_day_of_month
  //     << " ---"
  //     << std::endl
  //     << "--- entries_in_first_row : "
  //     << entries_in_first_row
  //     << " ---"
  //     << std::endl
  //     << "--- remaining_entries : "
  //     << remaining_entries
  //     << " ---"
  //     << std::endl
  //     << "--- ceil(remaining_entries / max_entries_per_row) : "
  //     << ceil(remaining_entries / max_entries_per_row)
  //     << " ---"
  //     << std::endl
  //     << "--- total_rows : "
  //     << total_rows
  //     << " ---"
  //     << std::endl;

  return total_rows;
}

unsigned int get_first_day_of_next_month(
    unsigned int total_entries,
    unsigned int first_day_of_month)
{
  const unsigned int total_rows = get_row_count(total_entries, first_day_of_month);

  const unsigned int max_entries_per_row = DAYS_IN_A_WEEK;

  const unsigned int entries_in_first_row = max_entries_per_row - first_day_of_month + 1;

  // total_rows - 2 => total_rows - first_row - last_row
  const unsigned int entries_filled = (total_rows - 2) * max_entries_per_row;

  const unsigned int remaining_entries = total_entries - entries_filled;

  const unsigned int entries_in_last_row = remaining_entries - entries_in_first_row;

  unsigned int first_day_of_next_month = (entries_in_last_row + 1) % max_entries_per_row;

  if (first_day_of_next_month == 0)
  {
    first_day_of_next_month = 7;
  }

  // std::cout
  //     << std::endl
  //     << "--- total_rows : "
  //     << total_rows
  //     << " ---"
  //     << std::endl
  //     << "--- entries_in_first_row : "
  //     << entries_in_first_row
  //     << " ---"
  //     << std::endl
  //     << "--- entries_filled : "
  //     << entries_filled
  //     << " ---"
  //     << std::endl
  //     << "--- total_entries : "
  //     << total_entries
  //     << " ---"
  //     << std::endl
  //     << "--- remaining_entries : "
  //     << remaining_entries
  //     << " ---"
  //     << std::endl
  //     << "--- entries_in_last_row : "
  //     << entries_in_last_row
  //     << " ---"
  //     << std::endl
  //     << "--- first_day_of_next_month : "
  //     << first_day_of_next_month
  //     << " ---"
  //     << std::endl;

  return first_day_of_next_month;
}
