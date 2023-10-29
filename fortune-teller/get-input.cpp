#include <iostream>

#include "get-input.hpp"

std::string get_string_input(const std::string prompt)
{
  std::string input;

  // Get input
  std::cout << prompt;
  std::getline(std::cin, input);

  return input;
}

char *get_char_input(const char *prompt, const size_t length)
{
  char *input = new char[length];

  // Get input
  std::cout << prompt;
  std::cin.getline(input, length);

  return input;
}
