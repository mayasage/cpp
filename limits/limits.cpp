#include <iostream>
#include <limits>

int main()
{
  std::cout
      << std::endl
      << "--------------------------"
      << std::endl
      << "  Range of Numbers -> std::numeric_limits<T>::min/lowest/max"
      << std::endl
      << std::endl;

  std::cout
      << "Short : "
      << std::numeric_limits<short>::min()
      << " to "
      << std::numeric_limits<short>::max()
      << std::endl;

  std::cout
      << "Unsigned Short : "
      << std::numeric_limits<unsigned short>::min()
      << " to "
      << std::numeric_limits<unsigned short>::max()
      << std::endl;

  std::cout
      << "Int : "
      << std::numeric_limits<int>::min()
      << " to "
      << std::numeric_limits<int>::max()
      << std::endl;

  std::cout
      << "Unsigned Int : "
      << std::numeric_limits<unsigned int>::min()
      << " to "
      << std::numeric_limits<unsigned int>::max()
      << std::endl;

  std::cout
      << "Long : "
      << std::numeric_limits<long>::min()
      << " to "
      << std::numeric_limits<long>::max()
      << std::endl;

  std::cout
      << "Float : "
      << std::numeric_limits<float>::lowest()
      << " to "
      << std::numeric_limits<float>::max()
      << "; min() : "
      << std::numeric_limits<float>::min()
      << std::endl;

  std::cout
      << "Double : "
      << std::numeric_limits<double>::lowest()
      << " to "
      << std::numeric_limits<double>::max()
      << "; min() : "
      << std::numeric_limits<double>::min()
      << std::endl;

  std::cout
      << "Long Double : "
      << std::numeric_limits<long double>::lowest()
      << " to "
      << std::numeric_limits<long double>::max()
      << "; min() : "
      << std::numeric_limits<long double>::min()
      << std::endl;

  // Other facilities
  // More info : https://en.cppreference.com/w/cpp/types/numeric_limits

  std::cout
      << std::endl
      << "--------------------------"
      << std::endl
      << "  Others"
      << std::endl
      << std::endl;

  std::cout
      << "std::numeric_limits<int>::is_signed : "
      << std::numeric_limits<int>::is_signed
      << std::endl;

  std::cout
      << "std::numeric_limits<int>::digits : "
      << std::numeric_limits<int>::digits
      << std::endl;

  std::cout
      << std::endl
      << "For floating point numbers..."
      << std::endl
      << "min() will print the minimum positive value"
      << std::endl
      << "lowest() will print the minimum possible value"
      << std::endl
      << std::endl;

  return 0;
}