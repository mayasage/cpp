// "iostream" makes more sense than "string" here, to me
#include <iostream>

std::string get_string_input(const std::string prompt);
char *get_char_input(const char *prompt, const size_t length);
