#include <iostream>
#include <iomanip>

/**
 * pr = print
 * pn = print newline
 * ps = print separator
 * ph = print heading
 *
 * sw = set width
 */

/* -------------------------------------------------------------------------- */

/* Declarations */

/* Basic */

void pr();
void pn();

/* pr */

template <typename T>
void pr(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void prn(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void prnn(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void npr(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void nprn(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void nprnn(T x, unsigned int colw = 0, unsigned int wsl = 0);

/* ps */

void ps(unsigned int len = 21, char sep = '-');
void psn(unsigned int len = 21, char sep = '-');
void psnn(unsigned int len = 21, char sep = '-');
void nps(unsigned int len = 21, char sep = '-');
void npsn(unsigned int len = 21, char sep = '-');
void npsnn(unsigned int len = 21, char sep = '-');

/* ph */

void ph(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void phn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void phnn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void nph(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void nphn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void nphnn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);

/* utils */

void sw(unsigned int);
void pb(unsigned int);

/* -------------------------------------------------------------------------- */

/* Definitions */

/* Basic */

void pr()
{
  pn();
}

void pn()
{
  std::cout << std::endl;
}

/* pr */

template <typename T>
void pr(T x, unsigned int colw, unsigned int wsl)
{
  sw(colw);
  pb(wsl);
  std::cout << x;
}

template <typename T>
void prn(T x, unsigned int colw, unsigned int wsl)
{
  pr(x, colw, wsl);
  pn();
}

template <typename T>
void prnn(T x, unsigned int colw, unsigned int wsl)
{
  pr(x, colw, wsl);
  pn();
  pn();
}

template <typename T>
void npr(T x, unsigned int colw, unsigned int wsl)
{
  pn();
  pr(x, colw, wsl);
}

template <typename T>
void nprn(T x, unsigned int colw, unsigned int wsl)
{
  pn();
  pr(x, colw, wsl);
  pn();
}

template <typename T>
void nprnn(T x, unsigned int colw, unsigned int wsl)
{
  pn();
  pr(x, colw, wsl);
  pn();
  pn();
}

/* ph */

void ph(std::string s, unsigned int colw, unsigned int wsl)
{
  pr(s, colw, wsl);
}

void phn(std::string s, unsigned int colw, unsigned int wsl)
{
  prn(s, colw, wsl);
}

void phnn(std::string s, unsigned int colw, unsigned int wsl)
{
  prnn(s, colw, wsl);
}

void nph(std::string s, unsigned int colw, unsigned int wsl)
{
  npr(s, colw, wsl);
}

void nphn(std::string s, unsigned int colw, unsigned int wsl)
{
  nprn(s, colw, wsl);
}

void nphnn(std::string s, unsigned int colw, unsigned int wsl)
{
  nprnn(s, colw, wsl);
}

/* ps */

void ps(unsigned int len, char sep)
{
  for (unsigned int i{0}; i < len; i++)
  {
    std::cout << sep;
  }
}

void psn(unsigned int len, char sep)
{
  ps(len, sep);
  pn();
}

void psnn(unsigned int len, char sep)
{
  ps(len, sep);
  pn();
  pn();
}

void nps(unsigned int len, char sep)
{
  pn();
  ps(len, sep);
}

void npsn(unsigned int len, char sep)
{
  pn();
  ps(len, sep);
  pn();
}

void npsnn(unsigned int len, char sep)
{
  pn();
  ps(len, sep);
  pn();
  pn();
}

/* utils */

void sw(unsigned int width)
{
  if (width > 0)
  {
    std::cout << std::setw(width);
  }
}

void pb(unsigned int spaces)
{
  for (unsigned int i{0}; i < spaces; i++)
  {
    std::cout
        << " ";
  }
}
