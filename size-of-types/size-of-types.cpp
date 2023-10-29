#include <iostream>
#include <iomanip>

#include "print.hpp"

const unsigned int width_num{2};
const unsigned int width_bytes{6};
unsigned int width_left{0};

void const pr_row(std::string type, unsigned long sof);

int main()
{
  /* Printing */

  // Short

  width_left = 21;

  npsn();

  phnn("Short");

  pr_row("Short : ", sizeof(short));
  pr_row("Short Int : ", sizeof(short int));
  pr_row("Signed Short : ", sizeof(signed short));
  pr_row("Signed Short Int : ", sizeof(signed short int));
  pr_row("Unsigned Short Int : ", sizeof(unsigned short int));

  // Int

  width_left = 15;

  npsn();

  phnn("Int");

  pr_row("Int : ", sizeof(int));
  pr_row("Signed : ", sizeof(signed));
  pr_row("Signed Int : ", sizeof(signed int));
  pr_row("Unsigned Int : ", sizeof(unsigned int));

  // Long

  width_left = 20;

  npsn();

  phnn("Long");

  pr_row("Long : ", sizeof(long));
  pr_row("Long Int : ", sizeof(long int));
  pr_row("Signed Long : ", sizeof(signed long));
  pr_row("Signed Long Int : ", sizeof(signed long int));
  pr_row("Unsigned Long Int : ", sizeof(unsigned long int));

  // Long Long

  width_left = 25;

  npsn();

  phnn("Long Long");

  pr_row("Long Long : ", sizeof(long long));
  pr_row("Long Long Int : ", sizeof(long long int));
  pr_row("Signed Long Long : ", sizeof(signed long long));
  pr_row("Signed Long Long Int : ", sizeof(signed long long int));
  pr_row("Unsigned Long Long Int : ", sizeof(unsigned long long int));

  // Others

  width_left = 14;

  npsn();

  phnn("Others");

  pr_row("Float : ", sizeof(float));
  pr_row("Double : ", sizeof(double));
  pr_row("Long Double : ", sizeof(long double));
  pr_row("Boolean : ", sizeof(bool));

  // Pointers

  width_left = 16;

  npsn();

  phnn("Pointers");

  pr_row("Float * : ", sizeof(float *));
  pr_row("Double * : ", sizeof(double *));
  pr_row("Long Double * : ", sizeof(long double *));
  pr_row("Boolean * : ", sizeof(bool *));

  nprnn("* All pointers have the same size, which is system-dependent.");

  return 0;
}

void const pr_row(std::string msg, unsigned long sof)
{
  pr(msg, width_left);
  pr(sof, width_num);
  prn(" bytes", width_bytes);
}
