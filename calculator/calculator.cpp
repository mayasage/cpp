#include <iostream>
#include <ctime>

#include "get-rand.hpp"

int main()
{
  /* Seed rand */
  std::srand(std::time(0));

  /* Declarations */

  const char ops[]{'+', '-', '*'};
  const unsigned int max_range{199};
  const unsigned int min_range{0};

  /* Print intro */

  std::cout
      << "Welcome to the greatest calculator on Earth!"
      << std::endl;

  /* Loop till user quits */

  while (true)
  {
    /* General Variables */

    unsigned int input;
    char choice;

    /* Generate 2 random numbers */

    const unsigned int rand_num_1{get_rand_num(min_range, max_range)};
    const unsigned int rand_num_2{get_rand_num(min_range, max_range)};

    /* Generate random operation */

    const char op{ops[get_rand_num(0, (std::size(ops) - 1))]};

    /* Calculate & save result */

    int result;
    switch (op)
    {
    case '+':
      result = rand_num_1 + rand_num_2;
      break;
    case '-':
      result = rand_num_1 - rand_num_2;
      break;
    case '*':
      result = rand_num_1 * rand_num_2;
      break;
    }

    /* Ask question */

    std::cout
        << "What's the result of "
        << rand_num_1
        << " "
        << op
        << " "
        << rand_num_2
        << " : ";

    /* Get response */

    std::cin >> input;

    /* Print result */

    const bool is_correct = (input == result);

    if (is_correct)
    {
      std::cout
          << "Congratulations! You got the result "
          << result
          << " right!"
          << std::endl;
    }
    else
    {
      std::cout
          << "Naah! the correct result is : "
          << result
          << std::endl;
    }

    /* Add a newline separator */

    std::cout
        << std::endl;

    /* Does the user wanna continue playing ? */

    /* Get user's choice */

    std::cout
        << "Do you want to try again ? (Y | N) : ";

    std::cin >> choice;

    /* Evaluate user's choice */
    if (choice != 'y' && choice != 'Y')
    {
      /* Exit */

      std::cout
          << "See you later !"
          << std::endl;

      break;
    }
  }

  return 0;
}
