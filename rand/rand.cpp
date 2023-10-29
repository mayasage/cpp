#include <iostream>
#include <iomanip>

int main()
{
  int rand_num = std::rand();          // 0 - RAND_MAX
  int rand_num2 = rand_num % 11;       // 0 - 10
  int rand_num3 = (rand_num % 10) + 1; // 1 - 10

  // Print RAND_MAX
  std::cout
      << std::endl
      << "RAND_MAX : "
      << RAND_MAX
      << std::endl
      << std::endl;

  // Print rand_nums
  std::cout
      << std::endl
      << "------------------------------------------------------------"
      << std::endl
      << "Will remain same, no matter how many times you run..."
      << std::endl
      << std::endl;

  std::cout
      << std::setw(20)
      << "[0-RAND_MAX]  ->  "
      << std::setw(35)
      << "rand_num = std::rand()  :  "
      << std::setw(20)
      << rand_num
      << std::endl;

  std::cout
      << std::setw(20)
      << "[0-10]  ->  "
      << std::setw(35)
      << "(rand_num % 11)  :  "
      << std::setw(20)
      << rand_num2
      << std::endl;

  std::cout
      << std::setw(20)
      << "[1-10]  ->  "
      << std::setw(35)
      << "(rand_num % 10) + 1  :  "
      << std::setw(20)
      << rand_num3
      << std::endl;

  std::cout
      << "------------------------------------------------------------"
      << std::endl
      << std::endl;

  // std::time(0); // Time since UNIX Epoch (1970-01-01T00:00:00.000Z)
  std::srand(std::time(0)); // Seed

  rand_num = std::rand();          // 0 - RAND_MAX
  rand_num2 = rand_num % 11;       // 0 - 10
  rand_num3 = (rand_num % 10) + 1; // 1 - 10

  // Print rand_nums again
  std::cout
      << std::endl
      << "------------------------------------------------------------"
      << std::endl
      << "Will always print random..."
      << std::endl
      << std::endl;

  std::cout
      << std::setw(20)
      << "[0-RAND_MAX]  ->  "
      << std::setw(35)
      << "rand_num = std::rand()  :  "
      << std::setw(20)
      << rand_num
      << std::endl;

  std::cout
      << std::setw(20)
      << "[0-10]  ->  "
      << std::setw(35)
      << "(rand_num % 11)  :  "
      << std::setw(20)
      << rand_num2
      << std::endl;

  std::cout
      << std::setw(20)
      << "[1-10]  ->  "
      << std::setw(35)
      << "(rand_num % 10) + 1  :  "
      << std::setw(20)
      << rand_num3
      << std::endl;

  std::cout
      << "------------------------------------------------------------"
      << std::endl
      << std::endl;

  return 0;
}
