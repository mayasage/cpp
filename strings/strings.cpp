#include <iostream>

int main()
{
  {
    // using namespace std::string_literals;
    using std::literals::string_literals::operator""s;

    auto x = "nuclear"s + " " + "bomb";
  }

  return 0;
}
