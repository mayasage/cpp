#include <iostream>
#include <algorithm>

#include "print.hpp"

void print_array(int *arr, unsigned int n)
{
  for (unsigned int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void insertion_sort(int *array, unsigned int size)
{
  // YOUR CODE WILL GO BELOW THIS LINE
  // DON'T MODIFY ANYTHING ABOVE THIS LINE

  if (size >= 1)
  {
    /* Select each element to find its position. */

    for (unsigned int i{1}; i < size; i++)
    {
      for (unsigned int j{i - 1}; j >= 0; j--)
      {

        if (array[j] > array[j + 1])
        {
          std::swap(array[j], array[j + 1]);
        }
        else
        {
          break;
        }

        if (j == 0)
        {
          break;
        }
      }
    }
  }

  // YOUR CODE WILL GO ABOVE THIS LINE
  // DON'T MODIFY ANYTHING BELOW THIS LINE
}

int main()
{
  int data[] = {6, 3, 5, 7, 4, 2};
  int size = sizeof(data) / sizeof(int);
  std::cout << "Before :" << std::endl;
  print_array(data, size);
  insertion_sort(data, size);
  std::cout << "After :" << std::endl;
  print_array(data, size);
}