#include "print.hpp"

int main(int argc, char **argv)
{
  /* --------------------------- Error Checking ----------------------------- */

  /* Check args length */

  if (argc != 4)
  {
    pen("Call Program with 3 arguments like this: ");
    pen("rooster a + b");

    pe("You called with : ");

    for (int i{0}; i < argc; ++i)
    {
      pr(" ");
      pr(argv[i]);
    }

    pn();

    return 0;
  }

  /* Check Numbers */

  double first_number{atof(argv[1])};
  double second_number{atof(argv[3])};

  if ((first_number == 0.0) || (second_number == 0.0))
  {
    prn("Use non-zero valid numbers.");

    return 0;
  }

  /* Check Operand */

  const char *operation{argv[2]};
  char op;

  if ((strlen(operation) == 1) &&
      ((operation[0] == '+') ||
       (operation[0] == '-') ||
       (operation[0] == 'x') || // x is for multiplication. * is interpreted
                                // by the shell and disturbing things.
       (operation[0] == '/')))
  {
    op = operation[0];
  }
  else
  {
    pe(operation);
    pen(" is not a valid operation.");

    return 0;
  }

  /* ------------------------------------------------------------------------ */

  pr(first_number);
  pr(op);
  pr(second_number);
  pr("=");

  switch (op)
  {
  case '+':
    prn(first_number + second_number);

    break;

  case '-':
    prn(first_number - second_number);

    break;

  case 'x':
    prn(first_number * second_number);

    break;

  case '/':
    prn(first_number / second_number);

    break;
  }

  return 0;
}
