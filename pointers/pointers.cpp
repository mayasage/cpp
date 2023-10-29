#include "print.hpp"

template <typename T>
unsigned int get_difference_in_bytes(T *ptr_1, T *ptr_2);

int main()
{
  /* Pointer arithmetic */

  int nums[]{1, 7, 11, 19};
  int *ptr{nums};
  int *ptr_plus_2{ptr + 2};
  int *prt_minus_1{ptr - 1}; // garbage value

  std::ptrdiff_t diff{ptr_plus_2 - ptr};  // 2
  auto diff_in_bytes{diff * sizeof(int)}; // 8

  /**
   * std::ptrdiff_t
   *
   * Class to store differences between pointers.
   */

  // std::ptrdiff_t ptr{nums};
  // error: invalid conversion from ‘int*’ to ‘std::ptrdiff_t’ {aka ‘long int’}

  // std::ptrdiff_t ptr_plus_2{ptr + 2};
  // error: invalid conversion from ‘int*’ to ‘std::ptrdiff_t’ {aka ‘long int’}

  /* Delete */
  int *ptr_1{};
  int *ptr_2 = new int(2);

  delete ptr_1; // ok
  delete ptr_1; // ok

  delete ptr_2; // ok
  // delete ptr_2; // not ok

  ptr_2 = nullptr;
  delete ptr_2; // ok
  delete ptr_2; // ok

  /**
   * Can call delete on a nullptr any number of time.
   * Can call delete on a non-nullptr only once.
   */

  return 0;
}

template <typename T>
unsigned int get_difference_in_bytes(T *ptr_1, T *ptr_2)
{
  return (ptr_2 - ptr_1) * sizeof(T);
}
