#include <iostream>

int main()
{
  std::cout
      << std::endl
      << "Types that take less than 4 bytes can't be calculated."
      << std::endl
      << "This is due to processor design."
      << std::endl
      << "For a processor, the smallest data type is Int."
      << std::endl
      << "However, compilers auto convert these types to Int."
      << std::endl
      << std::endl;

  short int short_int_var1{10}; // 2 bytes
  short int short_int_var2{20};

  char char_var1{40}; // 1
  char char_var2{50};

  std::cout
      << "short_int_var1 : "
      << sizeof(short_int_var1)
      << " bytes"
      << std::endl;

  std::cout
      << "short_int_var2 : "
      << sizeof(short_int_var2)
      << " bytes"
      << std::endl;

  std::cout
      << "char_var1 : "
      << sizeof(char_var1)
      << " bytes"
      << std::endl;

  std::cout
      << "char_var2 : "
      << sizeof(char_var2)
      << " bytes"
      << std::endl;

  auto auto_var_short_int = short_int_var1 + short_int_var2;
  auto auto_var_char = char_var1 + char_var2;

  std::cout
      << std::endl
      << "Adding short_int variables..."
      << std::endl
      << "auto auto_var_short_int = short_int_var1 + short_int_var2;"
      << std::endl
      << "auto_var_short_int : "
      << sizeof(auto_var_short_int)
      << " bytes"
      << std::endl;

  std::cout
      << std::endl
      << "Adding char variables..."
      << std::endl
      << "auto auto_var_char = char_var1 + char_var2;"
      << std::endl
      << "auto_var_char : "
      << sizeof(auto_var_char)
      << " bytes"
      << std::endl;

  std::cout << std::endl;

  return 0;
}