#include "print.hpp"

using lulli = unsigned long long int;
typedef unsigned long long int lulliNumber2;
// typedef lulliNumber3 unsigned long long int;
// error: ‘lulliNumber3’ does not name a type; did you mean ‘lulliNumber2’?

int main()
{
  lulli ek = 1;
  lulliNumber2 dow = 2;

  prn(ek);
  prn(dow);

  return 0;
}
