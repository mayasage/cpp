#include <iostream>

/**
 * pr = print
 * pn = print newline
 * ps = print separator
 * ph = print heading
 *
 * sw = set width
 */

/* Basic */

void const pr();
void const pn();

/* pr */

template <typename T>
void const pr(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void const prn(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void const prnn(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void const npr(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void const nprn(T x, unsigned int colw = 0, unsigned int wsl = 0);

template <typename T>
void const nprnn(T x, unsigned int colw = 0, unsigned int wsl = 0);

/* ps */

void const ps(unsigned int len = 21, char sep = '-');
void const psn(unsigned int len = 21, char sep = '-');
void const psnn(unsigned int len = 21, char sep = '-');
void const nps(unsigned int len = 21, char sep = '-');
void const npsn(unsigned int len = 21, char sep = '-');
void const npsnn(unsigned int len = 21, char sep = '-');

/* ph */

void const ph(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void const phn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void const phnn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void const nph(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void const nphn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);
void const nphnn(std::string s, unsigned int colw = 0, unsigned int wsl = 2);

/* utils */

void const sw(unsigned int);
void const pb(unsigned int);

/**
 * "" is considered a "std::string" by the compiler.
 * But, its running char* function, resulting in a warning :
 * ISO C++ forbids converting a string constant to ‘char*’
 *
 * This works though:
 *  const char test1[]{"-------------------"};
 *  char test2[]{"-------------------"};
 *
 *  print(test1);
 *  print(test2);
 *
 * Commenting this out for now, and rolling with strings.
 */
// void print(char *);
