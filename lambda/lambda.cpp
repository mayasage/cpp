#include "print.hpp"

/**
 * [capture list] (params) -> return type {}
 *
 * To access variables outside lambda functions, you have to add them to
 * the [capture list].
 */

int main()
{
  double a{10};
  double b{69};

  double &ref_a{a};
  double &ref_b{b};

  /* Capture by copy */
  /**
   * a, b -> Capture by value
   * ref_a, ref_b -> Capture by reference
   *
   * These values will get locked at the time of declaration
   * (all will be const).
   *
   * = means capture everything in the outer context by value
   * & means capture everything in the outer context by reference
   *
   * Both will be const as usual.
   */
  // const auto func = []() /* Error when using outer variables */
  const auto func = [a, b, &ref_a, &ref_b]()
  // const auto func = [=]()     /* Error when incrementing reference. */
  // const auto func = [&]() /* Will capture a & b also as a reference. */
  {
    prn("Hello World, I'm Lambda !");
    // a++; // error: increment of read-only variable ‘a’

    prn(a); // will always print 10 (gets locked)

    prn(ref_a);
    /* will print the value of the original var, since its a reference */

    ref_a += 10000; // will increment the original variable
  };
  func();

  prn(ref_a);

  func();
  pn();

  /* IIFE style */
  const auto res = [](double a, double b)
  {
    prn("Double-G ! Hello World, I'm Lambda IIFE !");
    return (a + b);
  }(12.1, 5.78);
  prn(res);

  /* Lambda is an expression */
  prn(
      [](double a, double b)
      {
        prn("Double-G ! Hello World, I'm Lambda IIFE !");
        return (a + b);
      }(12.1, 5.78));

  return 0;
}