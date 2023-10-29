#include <optional>

#include "print.hpp"

std::optional<int> f1(std::optional<char> c = std::nullopt)
{
  char x = c.value_or('z'); // Equivalent to (x = c || 'z') in JS

  prn(x);

  return {}; // retuns std::nullopt
}

int main()
{
  /* Can be wrapped around anything. */

  // std::optional<int> fire{};
  std::optional<int> fire{69};

  // prn(fire); // can't print

  /* Check with std::nullopt */
  if (fire != std::nullopt)
  {
    prn(fire.value());
    prn(*fire); // confusing to read (std::optional is not a pointer)
  }

  fire = 3; /* Change val */

  /* Check with has_value() behavior */
  if (fire.has_value())
  {
    prn(fire.value());
    prn(*fire); // confusing to read (std::optional is not a pointer)
  }

  pn();

  prn(f1('s') == std::nullopt);
  prn(f1().has_value());

  return 0;
}
