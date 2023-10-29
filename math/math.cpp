#include <iostream>
#include <cmath>

#include "print.hpp"

int main()
{
  double weight{7.7};

  npsn();
  phnn("Math functions");

  PR_ROW_WIDTH_LEFT = 35;
  PR_ROW_WIDTH_MIDDLE = 10;

  prn_row("std::floor(7.7) : ", std::floor(7.7)); // 7
  prnn_row("std::ceil(7.7) : ", std::ceil(7.7));  // 8

  prn_row("std::abs(-7.7) : ", std::abs(-7.7));       // 7.7
  prn_row("std::pow(3, 4) : ", std::pow(3, 4));       // 81
  prn_row("std::log10(10000) : ", std::log10(10000)); // 4
  prnn_row("std::sqrt(81) : ", std::sqrt(81));        // 9

  prn_row("std::round(0.5) : ", std::round(0.5));  // 1
  prnn_row("std::round(0.4) : ", std::round(0.4)); // 0

  prn_row("std::max(0.5, -0.2) : ", std::max(0.5, -0.2));  // 0.5
  prnn_row("std::min(0.5, -0.2) : ", std::min(0.5, -0.2)); // -0.2

  PR_ROW_WIDTH_LEFT = 20;
  PR_ROW_WIDTH_MIDDLE = 15;
  PR_ROW_WIDTH_RIGHT = 10;

  prn_row("std::exp(4) => ", "e ^ 4 : ", std::exp(4));                // 54.5982
  prnn_row("std::log(54.59) => ", "loge(54.59) : ", std::log(54.59)); // 3.99985

  return 0;
}
