#include <iostream>
#include <iomanip>
#include <cstring>

/**
 * pr = print
 * pn = print newline
 * ps = print separator
 * ph = print heading
 *
 * sw = set width
 */

/* -------------------------------------------------------------------------- */

/* Global Variables */

unsigned int PR_ROW_WIDTH_LEFT{25};
unsigned int PR_ROW_WIDTH_MIDDLE{2};
unsigned int PR_ROW_WIDTH_RIGHT{6};
char PC_ROW_FORMAT[20]{"f m l"};

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

void ps(unsigned int len = 80, char sep = '-');
void psn(unsigned int len = 80, char sep = '-');
void psnn(unsigned int len = 80, char sep = '-');
void nps(unsigned int len = 80, char sep = '-');
void npsn(unsigned int len = 80, char sep = '-');
void npsnn(unsigned int len = 80, char sep = '-');

/* ph */

void ph(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void phn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void phnn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void nph(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void nphn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void nphnn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);

/* --- utils --- */

void sw(unsigned int);
void pb(unsigned int);

/* pr_row */

template <typename T, typename U = std::string, typename V = std::string>
void pr_row(T msgLeft, U msgMid = "", V msgRight = "");

template <typename T, typename U = std::string, typename V = std::string>
void npr_row(T msgLeft, U msgMid = "", V msgRight = "");

template <typename T, typename U = std::string, typename V = std::string>
void nprn_row(T msgLeft, U msgMid = "", V msgRight = "");

template <typename T, typename U = std::string, typename V = std::string>
void nprnn_row(T msgLeft, U msgMid = "", V msgRight = "");

template <typename T, typename U = std::string, typename V = std::string>
void prn_row(T msgLeft, U msgMid = "", V msgRight = "");

template <typename T, typename U = std::string, typename V = std::string>
void prnn_row(T msgLeft, U msgMid = "", V msgRight = "");

/* pc_row */

template <typename T, typename U = std::string, typename V = std::string>
void pc_row(T msgF, U msgM = "", V msgL = "", const char *format = "");

template <typename T, typename U = std::string, typename V = std::string>
void npc_row(T msgF, U msgM = "", V msgL = "", const char *format = "");

template <typename T, typename U = std::string, typename V = std::string>
void npcn_row(T msgF, U msgM = "", V msgL = "", const char *format = "");

template <typename T, typename U = std::string, typename V = std::string>
void npcnn_row(T msgF, U msgM = "", V msgL = "", const char *format = "");

template <typename T, typename U = std::string, typename V = std::string>
void pcn_row(T msgF, U msgM = "", V msgL = "", const char *format = "");

template <typename T, typename U = std::string, typename V = std::string>
void pcnn_row(T msgF, U msgM = "", V msgL = "", const char *format = "");

void ch_pc_row_format(const char *f);

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

/* --- utils --- */

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

/* pr_row */

template <typename T, typename U, typename V>
void pr_row(T msgLeft, U msgMid, V msgRight)
{
  pr(msgLeft, PR_ROW_WIDTH_LEFT);
  pr(msgMid, PR_ROW_WIDTH_MIDDLE);
  pr(msgRight, PR_ROW_WIDTH_RIGHT);
}

template <typename T, typename U, typename V>
void npr_row(T msgLeft, U msgMid, V msgRight)
{
  pn();
  pr_row(msgLeft, msgMid, msgRight);
}

template <typename T, typename U, typename V>
void nprn_row(T msgLeft, U msgMid, V msgRight)
{
  pn();
  pr_row(msgLeft, msgMid, msgRight);
  pn();
}

template <typename T, typename U, typename V>
void nprnn_row(T msgLeft, U msgMid, V msgRight)
{
  pn();
  pr_row(msgLeft, msgMid, msgRight);
  pn();
  pn();
}

template <typename T, typename U, typename V>
void prn_row(T msgLeft, U msgMid, V msgRight)
{
  pr_row(msgLeft, msgMid, msgRight);
  pn();
}

template <typename T, typename U, typename V>
void prnn_row(T msgLeft, U msgMid, V msgRight)
{
  pr_row(msgLeft, msgMid, msgRight);
  pn();
  pn();
}

/* pc_row */

template <typename T, typename U, typename V>
void pc_row(T msgF, U msgM, V msgL, const char *format)
{
  const unsigned int len_format = std::strlen(format);
  const unsigned int len_pc_row_format = std::strlen(PC_ROW_FORMAT);

  const char *
      f{len_format > 0 ? format : PC_ROW_FORMAT};
  const unsigned int len{len_format > 0 ? len_format : len_pc_row_format};

  for (unsigned int i{0}; i < len; i++)
  {
    switch (f[i])
    {
    case ' ':
      pr(' ');
      break;

    case 'f':
      pr(msgF);
      break;

    case 'm':
      pr(msgM);
      break;

    case 'l':
      pr(msgL);
      break;
    }
  }
}

template <typename T, typename U, typename V>
void npc_row(T msgF, U msgM, V msgL, const char *format)
{
  pn();
  pc_row(msgF, msgM, msgL, format);
}

template <typename T, typename U, typename V>
void npcn_row(T msgF, U msgM, V msgL, const char *format)
{
  pn();
  pc_row(msgF, msgM, msgL, format);
  pn();
}

template <typename T, typename U, typename V>
void npcnn_row(T msgF, U msgM, V msgL, const char *format)
{
  pn();
  pc_row(msgF, msgM, msgL, format);
  pn();
  pn();
}

template <typename T, typename U, typename V>
void pcn_row(T msgF, U msgM, V msgL, const char *format)
{
  pc_row(msgF, msgM, msgL, format);
  pn();
}

template <typename T, typename U, typename V>
void pcnn_row(T msgF, U msgM, V msgL, const char *format)
{
  pc_row(msgF, msgM, msgL, format);
  pn();
  pn();
}

void ch_pc_row_format(const char *f)
{
  std::strcpy(PC_ROW_FORMAT, f);
}
