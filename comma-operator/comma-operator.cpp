#include <iostream>

int main()
{
  int number1{10};
  int number2{20};
  int number3{30};

  int increment{5};

  std::cout
      << std::endl;

  // int r1 = ((std::cout << "hello1" << std::endl),
  //           (std::cout << "hello2" << std::endl));
  // compilation error : can't convert to int

  int r1 = ((std::cout << "hello1" << std::endl),
            number1,
            number2 + 1,
            number3 += 1); // new number3

  std::cout
      << std::endl
      << "         r1         : "
      << r1
      << std::endl
      << "incremented number3 : "
      << number3
      << std::endl;

  std::cout
      << std::endl;

  return 0;
}