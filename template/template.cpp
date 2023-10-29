#include "print.hpp"

template <typename T>
void f1(T x, T y)
{
  prn("f1");
}

/* ------------------------ Template specialization ------------------------- */
/**
 * Commenting out "template<>" lead to the following errpr...
 *
 * error: specializing member ‘::f1<const char*>’ requires ‘template<>’ syntax
 */
template <>
void f1<const char *>(const char *x, const char *y)
{
  prn("f1-char*");
}

/**
 * This function will be called instead of the template one.
 *
 * Note:
 *  Templates are not C++ code. However, template specializations are.
 *  It is a way to tell compiler to generate relevant C++ code.
 *
 * So, the Compiler probably sees that there is already an existing function
 * for the template it's trying to generate, and stops.
 */
void f1(const char *x, const char *y)
{
  prn("f1-char*");
}

/* Re-declaration error. */
// void f1(const char *x, const char *y)
// {
//   prn("f1-char*");
// }

/* ------------------------ Template & Overloading -------------------------- */

/**
 * (3) Function template
 */

template <typename T>
T maximum(T a, T b)
{
  std::cout << "Template overload called(T) " << std::endl;
  return (a > b) ? a : b;
}

/**
 * (1) A raw overload will take precedence over any template instance.
 */

const char *maximum(const char *a, const char *b)
{
  std::cout << "Raw overload called" << std::endl;
  return (std::strcmp(a, b) > 0) ? a : b;
}

/**
 * (2) Overload through templates. Will take precedence over raw Template.
 */

template <typename T>
T *maximum(T *a, T *b)
{
  std::cout << "Template overload called (T*) " << std::endl;
  return (*a > *b) ? a : b;
}

/* ------------------- Function Templates Return value ---------------------- */

/**
 * Return Type will be auto-deduced.
 *
 * Order matters!
 *
 * These are different:
 *  template <typename ReturnType, typename T, typename P>
 *  template <typename T, typename ReturnType, typename P>
 *  template <typename T, typename P, typename ReturnType>
 *
 * Default ReturnType
 *  template <typename ReturnType = double, typename T, typename P>
 */

template <typename ReturnType, typename T, typename P>
ReturnType max1(T a, P b)
{
  prn("I am ReturnType.");
  return (a > b) ? a : b;
}

/**
 * With "auto", the Largest Type will be deduced.
 *
 * Note: The function definition must come before the call.
 */
template <typename T, typename P>
auto max2(T a, P b)
{
  prn("I am auto.");
  return (a > b) ? a : b;
  // return b;
  /**
   * When P is "const char *", returns a "const char *".
   */
}

/* ------------------------------- Decltype --------------------------------- */

/* Globals */
int g1{69};
int g2{69};

/**
 * error: ‘a’ was not declared in this scope
 * error: ‘b’ was not declared in this scope
 *
 * Because compiler reads left to right, and it can't find a & b.
 */
// decltype((a > b) ? a : b) max_decl1(T a, P b)

/**
 * Made "g1" & "g2" Global.
 */

/* Works */

template <typename T, typename P>
decltype((g1 > g2) ? g1 : g2) max_decl1(T a, P b)
{
  return (a > b) ? a : b;
}

/* --- OR --- */

/**
 * Use "Trailing Return Types".
 * Can split Definition & Declaration.
 */

// auto max_decl(T a, P b) -> decltype((g11 > g21) ? g11 : g21)
/**
 * error: ‘g11’ was not declared in this scope; did you mean ‘g1’?
 * error: ‘g21’ was not declared in this scope; did you mean ‘g2’?
 *
 * a & b works below, because it is coming before (in the template) it is read.
 * a & b didn't work above because compiler couldn't find them when reading
 * (from left to right).
 */

template <typename T, typename P>
auto max_decl2(T a, P b) -> decltype((a > b) ? a : b)
{
  return (a > b) ? a : b;
}

/**
 * Need to set "auto" as ReturnType.
 * It's not deducing, it's just a placeholder.
 */

/* ---------------------------- Decltype Auto ------------------------------- */

/**
 * Can't split into definition & declaration.
 *
 * "auto" will deduce from the returned value.
 */

template <typename T, typename P>
decltype(auto) max_dec_auto(T a, P b)
{
  return (a > b) ? a : b;

  /**
   * On Commenting out.
   *
   * error: ‘void m1’ has incomplete type
   * at function call:
   *  auto m1{max_dec_auto(1, 2ull)};
   *  ("auto" became "void")
   */
}

int main()
{
  f1("f", "y");

  /* ----------------------- Template & Overloading ------------------------- */

  const char *char_1{"wild"};
  const char *char_2{"animal"};

  maximum(char_1, char_2);
  /**
   * Priority:
   *  (1) A raw overload will take precedence over any template instance.
   *  (2) Overload through templates. Will take precedence over raw Template.
   *  (3) Function template.
   */

  int a{810};
  int b{23};

  auto result = maximum(&a, &b);
  /**
   * Priority:
   *  (2) Overload through templates. Will take precedence over raw Template.
   *  (3) Function template
   */

  /* ------------------ Function Templates Return value --------------------- */

  auto x1{max1<int, char, long>('c', 12L)};

  auto x2{max1<int, char>('c', 12L)}; // 12L will be auto-deduced.

  auto x3{max1<int>('c', 12L)};  // 'c', 12L will be auto-deduced.
  auto x4{max1<char>('c', 12L)}; // 'c', 12L will be auto-deduced.

  // auto x5{max1('c', 12L)};
  /**
   * error: no matching function for call to ‘max1(char, long int)’
   *
   * ReturnType can't be deduced!
   */

  /* "auto" deduction. */

  auto x5{max2(12.5, 99)};
  auto x6{max2('b', 90)};

  // auto x7{max2('b', "sexy fox")};

  /**
   * Will return a "const char *".
   *
   * Won't work at the moment because "max" is using comparison operator.
   */

  /* ------------------------------ Decltype -------------------------------- */

  /**
   * Useful for "Template Programming".
   */

  int y1{9};
  double y2{5.5};

  decltype((y1 > y2) ? y1 : y2) y3{67};

  max_decl1(1, 2);
  max_decl2(1, 2);

  auto m1{max_dec_auto(1, 2ull)};

  return 0;
}

/* Works */
// template <typename ReturnType, typename T, typename P>
// ReturnType max1(T a, P b)
// {
//   prn("I am ReturnType.");
//   return (a > b) ? a : b;
// }

/**
 * error: use of ‘auto max2(T, P) [with T = double; P = int]’ before deduction
 * of ‘auto’
 *
 * error: use of ‘auto max2(T, P) [with T = char; P = int]’ before deduction
 * of ‘auto’
 */
// template <typename T, typename P>
// auto max2(T a, P b)
// {
//   prn("I am auto.");
//   return (a > b) ? a : b;
//   // return b;
//   /**
//    * When P is "const char *", returns a "const char *".
//    */
// }

/* Works */
// template <typename T, typename P>
// decltype((g1 > g2) ? g1 : g2) max_decl1(T a, P b)
// {
//   return (a > b) ? a : b;
// }

/* Works */
// template <typename T, typename P>
// auto max_decl2(T a, P b) -> decltype((a > b) ? a : b)
// {
//   return (a > b) ? a : b;
// }
