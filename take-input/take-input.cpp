#include <iostream>

int main()
{
  /* Declaration */
  int age;
  std::string first_name;
  std::string full_name;

  /* Get age and first_name in one go. */
  std::cout
      << "Enter first name & age (separate by space): ";

  std::cin >> first_name >> age;

  /* Some bullshit message. */
  std::cout
      << "Hi, "
      << first_name
      << ", you're "
      << age
      << " years old."
      << std::endl;

  /* Get full_name. */
  std::cout
      << "Enter full name : ";

  std::cin.ignore(); /* Ignore \n left by previous cin call. */
  std::getline(std::cin, full_name);

  /*  */
  /**
   * World-Ending horseshit messages.
   *
   * Notice the difference in use of the 2 words...
   * bullshit & horseshit.
   * These represent similar expressions, but with different intensities.
   */
  std::cout
      << "Understood "
      << full_name
      << "."
      << std::endl;

  std::cout
      << "Bye."
      << std::endl;
}
