#include <iostream>

int main()
{
  // Declaration
  double x{1.8};
  double y{2.2};

  // Implicit cast
  int sum1 = x + y; // 4

  // Explicit cast
  int sum2 = static_cast<int>(x) + static_cast<int>(y); // 3
  int sum3 = static_cast<int>(x + y);                   // 4

  // Old style C-cast
  int x2 = (int)x; // 1

  std::cout << sum1 << std::endl;
  std::cout << sum2 << std::endl;
  std::cout << sum3 << std::endl;
  std::cout << x2 << std::endl;

  return 0;
}
