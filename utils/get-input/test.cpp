#include <iostream>

#include "get-input.hpp"

int main()
{
  const char prompt[]{"Hello dear, what's your name : "};
  const size_t max_length{50};

  const char *input = get_char_input(prompt, max_length);

  std::cout
      << "Sure, "
      << input
      << std::endl;

  return 0;
}
