#include <iostream>

int main()
{
  int int_condition{0};

  switch (int i; int_condition)
  {
    // A Recipe for Disaster
    int x;
    // int x{100}; // error: initialization won't occur (jump to case label)

  case 0:
  {
    int z{10000};
    x = 4; // Change x here
    i = 10;

    // Print x, i
    std::cout
        << std::endl
        << "Case 0"
        << std::endl
        << "    i : "
        << i
        << std::endl
        << "    x : "
        << x
        << std::endl;
  }
    // int g{100}; // error: initialization won't occur (jump to case label)

  case 1:
  {
    // z = 10; // z is not accessible, because it is inside curly braces

    std::cout
        << std::endl
        << "Fallthrough from Case 0..."
        << std::endl;

    // Print x, i
    std::cout
        << std::endl
        << "Case 1"
        << std::endl
        << "    i : "
        << i
        << std::endl
        << "    x : "
        << x
        << std::endl;

    std::cout << std::endl;
  }

  default:
    break; // Good practice
  }

  return 0;
}
