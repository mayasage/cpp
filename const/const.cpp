#include <iostream>

#include "print.hpp"

void int_ref(int &val);
void const_int_ref(const int &val);

void string_ref(std::string &sref);
void const_string_ref(const std::string &sref);

void stringview_ref(std::string_view sv);
void const_stringview_ref(const std::string_view sv);

int main()
{
  /* Declaration */

  int num1{69};       // non-const => can be changed
  const int num2{16}; // const => can't be changed

  /* ------------------------------------------------------------------------ */
  /* Pointers */

  /**
   * Pointer to Const
   * (Data is Const from the Pointer's POV.)
   *
   * Can't change the value through this pointer.
   * Can change the pointer.
   */
  const int *p1{&num1};
  // *p1 = 16; // error: assignment of read-only location ‘* p’
  p1 = {&num2}; // works

  /**
   * Const Pointer
   * (The Pointer itself is Const.)
   *
   * Can change the value through this pointer.
   * Can't change the pointer.
   */
  int *const p2{&num1};
  *p2 = 27; // works
  // p2 = &num2; // error: assignment of read-only variable ‘p2’

  /**
   * Const Pointer to Const
   * (The Data is Const from the Const Pointer's POV.)
   *
   * Pointer to Const => Pointer can't change value.
   * Const Pointer => Can't change the pointer.
   */
  const int *const p3{&num1};
  // *p3 = 15; // error: assignment of read-only location ‘*(const int*)p3’
  // p3 = &num2; // error: assignment of read-only variable ‘p3’

  /**
   * A Const variable (should) require a Const Pointer.
   */
  // int *p4{&num2}; // error: invalid conversion from ‘const int*’ to ‘int*’
  // char *p5{"Hello world!"};
  /**
   * warning: ISO C++ forbids converting a string constant to ‘char*’
   * Some compilers forbid this.
   */
  // However...
  // p5[0] = 'M'; // Segmentation fault (core dumped)

  /* ------------------------------------------------------------------------ */
  /* Arrays */

  int num3{10};
  int num4{20};
  int num5{30};

  // const int nums1[]{1, 2, 3};
  int const nums1[]{1, 2, 3}; /* preferred */
  /**
   * Both are valid & equal.
   * "const" ensures that the data inside "nums1" never changes.
   */
  // nums1[0] = 69; /* error: assignment of read-only location ‘nums1[0]’ */

  /* Example */
  int *const nums2[]{&num3, &num4}; /* preferred */
  // const int *nums2[]{&num3, &num4};
  // nums2[0] = &num5; /* error: assignment of read-only location ‘nums2[0]’ */

  // const const char *students1[]{
  //     "Sasha Grey",
  //     "Mia Malkova",
  //     "Miya Khalifa",
  //     "Dani Daniels"}; /* error: duplicate ‘const’ */
  const char *const students1[]{
      "Sasha Grey",
      "Mia Malkova",
      "Miya Khalifa",
      "Dani Daniels"}; // valid
  /**
   * students is an array of "const char *".
   * "const char *"" can't be edited.
   *
   * Adding a "const" to ensure that the data inside students never changes.
   */

  /* Can't make static array variable to point somewhere else */

  int num6[] = {1, 2, 3, 4};
  int num7[] = {5, 6, 7, 8};
  int *num_ptr;

  num_ptr = num6; // valid
  // num6 = num7; // error: invalid array assignment

  num_ptr = &num7[0]; // valid
  // num6 = &num7[0];
  /* error: incompatible types in assignment of ‘int*’ to ‘int [4]’ */

  num_ptr += 1;
  // num6 += 1; // error: incompatible types in assignment of ‘int’ to ‘int [4]’

  /* Passing references of implicitly converted variables */

  const double double_var1{3.6};
  double double_var2{3.6};

  // int_ref(double_var1);
  // int_ref(double_var2);
  /**
   * error: cannot bind non-const lvalue reference of type ‘int&’
   * to an rvalue of type ‘int’
   *
   * double_var1 & double_var2 are implicitly converted to int in a temporary
   * variable, and its reference is passed to the function.
   * Here, the function takes a "non-const" reference, which means that it can
   * change the value of the temporary variable.
   * Changing this value is confusing, as it can't change the original
   * double_var1/double_var2, but the temporary variable.
   * Therefore, compiler prohibits this action.
   *
   * However, if the function takes a "const" reference, instead of a
   * "non-const" one, then the function can't change the value of the
   * temporary variable.
   * Thus, compiler allows this action.
   *
   * In short, if your function is guaranteed to never change the implicitly
   * converted variable (which can only happen if it is taking a
   * "const" reference), then you can pass it.
   *
   * Allow reading, disallow editing.
   */

  /* Works */
  const_int_ref(double_var1);
  const_int_ref(double_var2);

  /**
   * Conclusion:
   *
   * Implicitly converted references can only be passed to functions that take
   * a "const" reference.
   */

  int casted_var1{static_cast<int>(double_var1)};
  int casted_var2{static_cast<int>(double_var2)};

  int_ref(casted_var1);
  int_ref(casted_var2);

  const_int_ref(casted_var1);
  const_int_ref(casted_var2);

  /* String example */

  // string_ref("maya");
  // string_ref(std::string("maya"));
  /**
   * error: cannot bind non-const lvalue reference of type ‘std::string&’
   * {aka ‘std::__cxx11::basic_string<char>&’} to an rvalue of type
   * ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
   */

  const_string_ref("maya");
  /**
   * Works
   *
   * But, the compiler will detect that this is a "const char *", and so,
   * it will convert (by copying) & store this in a temporary
   * "std::string" variable.
   *
   * To avoid copying, use "std::string_view".
   */

  const_string_ref(std::string("maya"));

  /* std::string_view */

  /**
   * Note:
   *
   * An "std::string_view" can't change the original "std::string/const char*".
   * You can think of them it as a "const" by default.
   *
   * Also, an "std::string_view" is separate from the "std::string", and an
   * "std::string" is not mandatory for its construction.
   * It can also be directly constructed from a "const char *".
   *
   * And an "std::string_view" never copies.
   *
   * If you use "const" in the function parameter, then it will mean that you
   * can't make the local variable point anywhere else.
   *
   * In short, the only difference between "const" & "non-const" is that the
   * "const" local variable can be reassigned inside the function, while the
   * "non-const" can't be reassigned.
   * So, you don't have to even care about "const".
   */

  /* Works */

  stringview_ref("Maya");
  const_stringview_ref("Maya");

  stringview_ref(std::string("Maya"));
  const_stringview_ref(std::string("Maya"));

  stringview_ref(std::string_view("Maya"));
  const_stringview_ref(std::string_view("Maya"));

  /**
   * "Maya" (const char []) is created in Memory.
   * Its reference becomes the "Maya" we see (const char *).
   *
   * std::string("Maya") will create a new instance by copying "Maya".
   *
   * std::string_view("Maya") will also create a new instance,
   * but won't copy "Maya".
   *
   * After the above arguments are passed to the function,
   * an "std::string_view" instance is created (if not passed),
   * and its reference becomes the parameter "sv" in that function.
   */

  /* Converting "std::string_view" to "std::string" */

  /**
   * Implicit conversion is not allowed.
   *
   * These 2 are really 2 separate things.
   * "std::string" holds a solid string (it maintains its own
   * independent string).
   * "std::string_view" doesn't. It's a window to an existing string in memory.
   *
   * The types have to be related in some way for implicit conversion...
   * and these aren't.
   */

  // string_ref(std::string_view("Maya"));

  /**
   * error: invalid initialization of non-const reference of type
   * ‘std::string&’ {aka ‘std::__cxx11::basic_string<char>&’} from an rvalue of
   * type ‘std::string_view’ {aka ‘std::basic_string_view<char>’}
   */

  // const_string_ref(std::string_view("Maya"));

  /**
   * error: invalid initialization of reference of type ‘const string&’
   * {aka ‘const std::__cxx11::basic_string<char>&’} from expression of type
   * ‘std::string_view’ {aka ‘std::basic_string_view<char>’}
   */

  /**
   * Explicit conversion is allowed.
   *
   * But passing is only allowed if the function guarantees that it won't change
   * the "std::string" (declare "const" reference).
   */

  // string_ref(std::string("Maya"));
  // string_ref(std::string(std::string_view("Maya")));

  /**
   * error: cannot bind non-const lvalue reference of type ‘std::string&’
   * {aka ‘std::__cxx11::basic_string<char>&’} to an rvalue of type
   * ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
   */

  /* Works */

  const_string_ref(std::string("Maya"));
  const_string_ref(std::string(std::string_view("Maya")));

  /* ----------------------------- Reference -------------------------------- */

  std::string fucker1{"Cock man"};
  std::string fucker2{"Pussy gal"};

  std::string &s1 = fucker1;
  s1 = fucker2;

  const std::string const_fucker{"Sex addicted"};

  // std::string &cunt = const_fucker;
  /**
   * error: binding reference of type
   * ‘std::string&’ {aka ‘std::__cxx11::basic_string<char>&’} to ‘const string’
   * {aka ‘const std::__cxx11::basic_string<char>’} discards qualifiers
   */

  const std::string &cunt = const_fucker;

  /* Can't change const at all. */
  // cunt = fucker1; // No
  // cunt[1] = 'E'; // No
  // cunt[2] = 'X'; // No

  /* ------------------------------------------------------------------------ */

  return 0;
}

void int_ref(int &val)
{
  val++;
  prn(val);
}

void const_int_ref(const int &val)
{
  // val++; // error: increment of read-only reference ‘val’
  prn(val);
}

void string_ref(std::string &sref)
{
  sref = "Mage";
  sref[0] = 'S';

  prn(sref);
}

void const_string_ref(const std::string &sref)
{
  /* Can't change const */

  // sref = "Sage"; // error: invalid conversion from ‘const char*’ to ‘char’
  // sref[0] = 'S';
  /**
   * error: assignment of read-only location
   * ‘(& sref)->std::__cxx11::basic_string<char>::operator[](0)’
   */

  {
    using std::literals::string_literals::operator""s;

    // sref = std::string("Sage");
    /**
     * error: no match for ‘operator=’ (operand types are ‘const string’
     * {aka ‘const std::__cxx11::basic_string<char>’} and
     * ‘std::__cxx11::basic_string<char>’)
     */
  }

  prn(sref);
}

void stringview_ref(std::string_view sv)
{
  sv.remove_prefix(1);
  sv.remove_suffix(1);

  sv = "Sage";

  /**
   * valid because sv is not "const".
   *
   * "Sage" will be converted to a temporary variable of type "std::string",
   * and a "std::string_view" reference for the same will be obtained and
   * assigned to "sv".
   */

  // sv[0] = 'M';

  /**
   * error: assignment of read-only location
   * ‘sv.std::basic_string_view<char>::operator[](0)’
   *
   * This is not an "std::string"!
   */

  prn(sv);
}

void const_stringview_ref(const std::string_view sv)
{
  /* Can't change const */

  // sv = "Sage";
  // sv = std::string_view("Sage");
  /**
   * error: passing ‘const string_view’
   * {aka ‘const std::basic_string_view<char>’} as ‘this’ argument
   * discards qualifiers
   *
   * Invalid because sv is "const".
   */

  prn(sv);
}
