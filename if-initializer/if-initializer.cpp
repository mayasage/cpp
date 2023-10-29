#include <iostream>

int main()
{
  // bool condition{true};
  bool condition{false};

  std::cout << std::endl;

  std::cout
      << "if (int test{10}, x{1}; condition)..."
      << std::endl
      << std::endl;

  if (int test{10}, x{1}; condition)
  {
    std::cout
        << "    If block : "
        << std::endl
        << "        x : "
        << x
        << std::endl
        << "        test : "
        << test
        << std::endl;
  }
  else
  {
    std::cout
        << "    Else block : "
        << std::endl
        << "        x : "
        << x
        << std::endl
        << "        test : "
        << test
        << std::endl;
  }

  std::cout << std::endl;

  return 0;
}
