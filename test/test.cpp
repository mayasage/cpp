#include <iostream>
#include "utilities.h"

int main()
{
  auto result = add(11, 22ul);
  std::cout << "result : " << result << std::endl;
  return 0;
}