#include "print.hpp"

/**
 * static variables -> static because of their lifetime (die when program dies)
 */

int im_a_static_var{0}; // a global var is always static

int f1()
{
  static int im_a_static_var{0}; // f1 will increment by 1 in each call.
  /**
   * scope will be this function.
   * But lifetime is the entire program.
   */

  // int im_a_static_var{0}; // f1 will always return 1

  im_a_static_var++;

  return im_a_static_var;
}

/**
 * With inline, the compiler will try to reduce the overhead of calling a
 * function, by replacing the function call with function body in such a way
 * that the output is same.
 *
 * inline is just a suggestion to the compiler.
 *
 * Also, this will drastically increase the binary size, because the function
 * is not getting reused, the compiler is replacing every function call with
 * the function body.
 */
inline int f2(int a, int b)
{
  return a + b;
}

int main()
{
  prn(f1());
  prn(f1());
  prn(f1());

  prn(f2(10, 20)); // inline will replace "f2(a, b)" with "a + b".

  return 0;
}
