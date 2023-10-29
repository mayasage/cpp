#include <iostream>

int main()
{
  // Declaration
  const int LIB_VERSION = 10;

  static_assert(LIB_VERSION == 10); // Compile-time testing

  return 0;
}
