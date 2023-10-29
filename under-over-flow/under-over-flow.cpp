#include <iostream>

int main()
{
  // Declarations
  unsigned char char1;

  // Overflow => reset to 0
  char1 = 256 + 65; // 65, 'A'

  std::cout << char1 << std::endl;
  std::cout << static_cast<int>(char1) << std::endl;

  // Underflow => reset to 255
  char1 = 0 - 191; // 65, 'A'

  std::cout << char1 << std::endl;
  std::cout << static_cast<int>(char1) << std::endl;

  return 0;
}