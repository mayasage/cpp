#include "print.hpp"

int main()
{
  /**
   * students is an array of "const char *".
   * "const char *"" can't be edited.
   */

  int scores[2]{11, 19}; // it is impossible to make scores point elsewhere

  /**
   * Similarities
   * A pointer basically points to the 1st element of the Array.
   */

  /* ------------------------------------------------------------------------ */
  /* Differences */

  /* scores can't point elsewhere */
  int num_arr[2]{11, 19};
  // scores = &num_arr[0];
  /* error: incompatible types in assignment of ‘int*’ to ‘int [2]’ */

  /* std::sizeof() doesn't work for pointers */
  int *int_ptr{num_arr};
  /**
   * Pointer Decay
   * The array will decay into a pointer, losing some info in the process.
   */
  // prn(std::size(int_ptr)); /* error: no matching param */
  prn(std::size(num_arr)); // works

  /* ------------------------------------------------------------------------ */

  return 0;
}