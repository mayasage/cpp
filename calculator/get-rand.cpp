#include <cstdlib> // std::srand
#include <ctime>   // std::time()
#include "get-rand.hpp"

unsigned int get_rand_num(unsigned int min_range, unsigned int max_range)
{
  return ((std::rand() % (max_range + 1 - min_range)) + min_range);
}
