#include <iostream>

/**
 * "consteval" is giving the exact same errors as "constexpr".
 *
 * The difference is that "consteval" guarantees that the function will get
 * evaluated at compile-time, and it it can't, you'll get a compiler error.
 *
 * "consteval" can only runs at compile-time.
 */

consteval int get_val(int val)
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
  /* "res1" will get initialized at compile-time. */

  int res1 = get_val(1);

  int val1{69};
  // int res2 = get_val(val1);

  /**
   * error: the value of ‘val’ is not usable in a constant expression
   *
   * Since "val" is non-const, it will not be available during compile-time.
   */

  /* Works */
  const int val2{69};
  int res3 = get_val(val2);

  return 0;
}
