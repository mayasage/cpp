#include <iomanip>

#include "print.hpp"

/* Basic */

void const pr()
{
  pn();
}

void const pn()
{
  std::cout << std::endl;
}

/* pr */

template <typename T>
void const pr(T x, unsigned int colw, unsigned int wsl)
{
  sw(colw);
  pb(wsl);
  std::cout << x;
}
template void const pr(char const *x, unsigned int colw, unsigned int wsl);
template void const pr(std::string x, unsigned int colw, unsigned int wsl);
template void const pr(unsigned long x, unsigned int colw, unsigned int wsl);

template <typename T>
void const prn(T x, unsigned int colw, unsigned int wsl)
{
  pr(x, colw, wsl);
  pn();
}
template void const prn(char const *x, unsigned int colw, unsigned int wsl);
template void const prn(std::string x, unsigned int colw, unsigned int wsl);
template void const prn(unsigned long x, unsigned int colw, unsigned int wsl);

template <typename T>
void const prnn(T x, unsigned int colw, unsigned int wsl)
{
  pr(x, colw, wsl);
  pn();
  pn();
}
template void const prnn(char const *x, unsigned int colw, unsigned int wsl);
template void const prnn(std::string x, unsigned int colw, unsigned int wsl);
template void const prnn(unsigned long x, unsigned int colw, unsigned int wsl);

template <typename T>
void const npr(T x, unsigned int colw, unsigned int wsl)
{
  pn();
  pr(x, colw, wsl);
}
template void const npr(char const *x, unsigned int colw, unsigned int wsl);
template void const npr(std::string x, unsigned int colw, unsigned int wsl);
template void const npr(unsigned long x, unsigned int colw, unsigned int wsl);

template <typename T>
void const nprn(T x, unsigned int colw, unsigned int wsl)
{
  pn();
  pr(x, colw, wsl);
  pn();
}
template void const nprn(char const *x, unsigned int colw, unsigned int wsl);
template void const nprn(std::string x, unsigned int colw, unsigned int wsl);
template void const nprn(unsigned long x, unsigned int colw, unsigned int wsl);

template <typename T>
void const nprnn(T x, unsigned int colw, unsigned int wsl)
{
  pn();
  pr(x, colw, wsl);
  pn();
  pn();
}
template void const nprnn(char const *x, unsigned int colw, unsigned int wsl);
template void const nprnn(std::string x, unsigned int colw, unsigned int wsl);
template void const nprnn(unsigned long x, unsigned int colw, unsigned int wsl);

/* ph */

void const ph(std::string s, unsigned int colw, unsigned int wsl)
{
  pr(s, colw, wsl);
}

void const phn(std::string s, unsigned int colw, unsigned int wsl)
{
  prn(s, colw, wsl);
}

void const phnn(std::string s, unsigned int colw, unsigned int wsl)
{
  prnn(s, colw, wsl);
}

void const nph(std::string s, unsigned int colw, unsigned int wsl)
{
  npr(s, colw, wsl);
}

void const nphn(std::string s, unsigned int colw, unsigned int wsl)
{
  nprn(s, colw, wsl);
}

void const nphnn(std::string s, unsigned int colw, unsigned int wsl)
{
  nprnn(s, colw, wsl);
}

/* ps */

void const ps(unsigned int len, char sep)
{
  for (unsigned int i{0}; i < len; i++)
  {
    std::cout << sep;
  }
}

void const psn(unsigned int len, char sep)
{
  ps(len, sep);
  pn();
}

void const psnn(unsigned int len, char sep)
{
  ps(len, sep);
  pn();
  pn();
}

void const nps(unsigned int len, char sep)
{
  pn();
  ps(len, sep);
}

void const npsn(unsigned int len, char sep)
{
  pn();
  ps(len, sep);
  pn();
}

void const npsnn(unsigned int len, char sep)
{
  pn();
  ps(len, sep);
  pn();
  pn();
}

/* utils */

void const sw(unsigned int width)
{
  if (width > 0)
  {
    std::cout << std::setw(width);
  }
}

void const pb(unsigned int spaces)
{
  for (unsigned int i{0}; i < spaces; i++)
  {
    std::cout
        << " ";
  }
}

/**
 * Header file contains explanation for why this was commented out.
 */
// void const pr(char *msg)
// {
//   std::cout << msg;
//   pr();
// }
