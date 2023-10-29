#include <iostream>
#include <array>

#include "print.hpp"

/* Function Declarations */

/* Worked */
// double sum(double arr[][3], unsigned int size);
// double sum(double arr[][3][2], unsigned int size);

template <typename T, size_t rows, size_t cols>
T sum(T (&arr)[rows][cols]);

template <typename T, size_t x, size_t y, size_t z>
T sum(T (&arr)[x][y][z]);

int main()
{
  /* Declarations */

  // double weights[][3]{
  //     {10.0, 20.0, 30.0},
  //     {40.0, 50.0, 60.0},
  //     {70.0, 80.0, 90.0},
  //     {100.0, 110.0, 120.0},
  // };

  // double weights_3d[][3][2]{
  //     {
  //         {10, 20},
  //         {30, 40},
  //         {50, 60},
  //     },
  //     {
  //         {70, 80},
  //         {90, 100},
  //         {110, 120},
  //     },
  // };

  // float weights[][3]{
  //     {10.0, 20.0, 30.0},
  //     {40.0, 50.0, 60.0},
  //     {70.0, 80.0, 90.0},
  //     {100.0, 110.0, 120.0},
  // };

  // float weights_3d[][3][2]{
  //     {
  //         {10, 20},
  //         {30, 40},
  //         {50, 60},
  //     },
  //     {
  //         {70, 80},
  //         {90, 100},
  //         {110, 120},
  //     },
  // };

  int weights[][3]{
      {10, 20, 30},
      {40, 50, 60},
      {70, 80, 90},
      {100, 110, 120},
  };

  int weights_3d[][3][2]{
      {
          {10, 20},
          {30, 40},
          {50, 60},
      },
      {
          {70, 80},
          {90, 100},
          {110, 120},
      },
  };

  /* Worked */
  // pcn_row("sum = ", sum(weights, std::size(weights)));
  // pcn_row("sum = ", sum(weights_3d, std::size(weights_3d)));

  pcn_row("sum = ", sum(weights));
  pcn_row("sum = ", sum(weights_3d));

  return 0;
}

/* Function Definitions */

template <typename T, size_t rows, size_t cols>
T sum(T (&arr)[rows][cols])
{
  T s{0};

  for (size_t i{0}; i < rows; i++)
  {
    for (size_t j{0}; j < cols; j++)
    {
      const T val{arr[i][j]};

      s += val;
    }
  }

  return s;
}

template <typename T, size_t x, size_t y, size_t z>
T sum(T (&arr)[x][y][z])
{
  T s{0};

  for (size_t i{0}; i < x; i++)
  {
    for (size_t j{0}; j < y; j++)
    {
      for (size_t k{0}; k < z; k++)
      {
        const T val{arr[i][j][k]};

        s += val;
      }
    }
  }

  return s;
}

/* Worked */
// double sum(double arr[][3], unsigned int size)
// {
//   double s{0};

//   for (int i{0}; i < size; i++)
//   {
//     prn_row("size[i] = ", std::size(arr[i]));
//     for (int j{0}; j < std::size(arr[i]); j++)
//     {
//       const double val{arr[i][j]};

//       prn(val);
//       s += val;
//     }
//   }

//   return s;
// }

/* Worked */
// double sum(double arr[][3][2], unsigned int size)
// {
//   double s{0};

//   for (int i{0}; i < size; i++)
//   {
//     prn_row("size[i] = ", std::size(arr[i]));
//     for (int j{0}; j < std::size(arr[i]); j++)
//     {
//       prn_row("size[i][j] = ", std::size(arr[i][j]));
//       for (int k{0}; k < std::size(arr[i][j]); k++)
//       {
//         const double val{arr[i][j][k]};

//         prn(val);
//         s += val;
//       }
//     }
//   }

//   return s;
// }
