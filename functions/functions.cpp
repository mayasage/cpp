#include <iostream>

#include "print.hpp"

int sum(const int (&arr)[10])
{
  // arr[0] = 69; // error due to "const"

  int sum{0};

  for (int val : arr)
  {
    sum += val;
  }

  return sum;
}

// void test_ref(int &const val)
/* error: ‘const’ qualifiers cannot be applied to ‘int&’ */

// void test_ref(int const &val) // valid
// void test_ref(int &val) // valid

void test_ref(const int &val) // valid
{
  // val++; // error: increment of read-only reference ‘val'
}

int main()
{
  int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int val{16};

  test_ref(val);
  sum(arr);

  return 0;
}
