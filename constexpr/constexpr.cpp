#include <iostream>

#include "print.hpp"

constexpr int get_val(int val)
{
  // for (unsigned int i{0}; i < (9999ul * 999ul); i++)
  // {
  // }

  /**
   * error: ‘constexpr’ loop iteration count exceeds limit of 262144
   * (use ‘-fconstexpr-loop-limit=’ to increase the limit)
   */

  // for (unsigned int i{0}; i < 262144; i++)
  // {
  //   prn("fuck now");
  // }

  /**
   * error: call to non-‘constexpr’ function
   * ‘void prn(T, unsigned int, unsigned int) [with T = const char*]’
   */

  for (unsigned int i{0}; i < 262144; i++)
  {
    // Works
  }

  return 69 * val;
}

int get_val_n(int val)
{
  return 69 * val;
}

int main()
{
  constexpr int res1 = get_val(1);
  const int res2 = get_val_n(1);
  const int res3 = get_val(1);

  static_assert(res1 == 69, "constexpr didn't work");

  /**
   * Works
   *
   * static_assert works at compile time, and therefore proves that res1
   * was evaluated at compile-time.
   */

  static_assert(res3 == 69, "this is not a constexpr");

  /**
   * This also works because we declared the variable as "const", and the
   * function is a "constexpr", meaning that the value can be determined at
   * compile-time by the compiler.
   */

  // static_assert(res2 == 69, "this is not a constexpr");

  /**
   * error: non-constant condition for static assertion
   * error: the value of ‘res2’ is not usable in a constant expression
   */

  return 0;
}
