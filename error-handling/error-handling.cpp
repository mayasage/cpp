#include <iostream>

#include "print.hpp"

int main()
{
  /* std::exception */

  nps();
  nphnn("std::exception");

  try
  {
    int *arr = new int[1000000000000000000];
  }
  catch (std::exception &ex)
  {
    prn(ex.what());
  }

  /* std::nothrow */

  nps();
  nphnn("std::nothrow");

  int *arr = new (std::nothrow) int[1000000000000000000];
  if (arr == nullptr)
  {
    prn("Allocation failed.");
  }

  nprnn("Program did not crash.");

  return 0;
}
