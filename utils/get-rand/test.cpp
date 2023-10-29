#include <iostream>

#include "get-rand.hpp"

int main()
{
  /* Declarations */
  const unsigned int min_ranges[]{
      0,
      1,
      2,
      3,
      0,
      2};

  const unsigned int max_ranges[]{
      199,
      199,
      199,
      199,
      200,
      204};

  unsigned int count{0};

  std::cout
      << "Checking..."
      << std::endl;

  for (unsigned int i{0}; i < 1'000'000; i++)
  {
    /* Print rand num if it is out of range */
    for (
        unsigned int ptr_range{0};
        ptr_range < std::size(min_ranges);
        ptr_range++)
    {
      const unsigned int min_range{min_ranges[ptr_range]};
      const unsigned int max_range{max_ranges[ptr_range]};

      const unsigned int rand_num{get_rand_num(min_range, max_range)};

      if (rand_num < min_range || rand_num > max_range)
      {
        count++;

        std::cout
            << "["
            << min_range
            << "-"
            << max_range
            << "]"
            << " -> "
            << rand_num
            << std::endl;
      }
    }
  }

  if (count == 0)
  {
    std::cout
        << "All random numbers are within range.";
  }
  else
  {
    std::cout
        << "Found "
        << count
        << " out-of-range numbers.";
  }

  std::cout
      << std::endl;

  return 0;
}
