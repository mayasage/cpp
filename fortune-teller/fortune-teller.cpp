#include <iostream>
#include <ctime>

#include "get-input.hpp"

int main()
{
  /* Seed Rand */
  std::srand(std::time(0));

  /* Declare Predictions */
  const char *predictions[]{
      "a lot of cats running in the backyard!",
      "a lot of hollow bulls on your dance door.",
      "you flirting too much with kids wearing yellow clothes.",
      "you cunning away from something really scary.",
      "clouds gathering in the sky, angels falling.",
      "squirrels running around in a deserted empty country.",
      "lots of taxis stuck in a one-way street.",
      "you moving in the dark with lot of little nightingales.",
      "you crossing your legs. Umm... the lights went out!",
      "you took the guns out. Feeling adventurous 😛.",
      "... shit... no, it's nothing! 🗿"};

  /* Get full_name */
  const unsigned int full_name_length{15};
  const char prompt[]{"Hello dear, what's your name : "};
  const char *full_name = get_char_input(prompt, full_name_length);

  while (true)
  {
    /* Print prediction */
    unsigned int rand_num = std::rand() % (std::size(predictions));
    /* From [0] to [predictions.length - 1] */

    std::cout
        << "Oh dear "
        << full_name
        << ", I see "
        << predictions[rand_num]
        << std::endl;

    /* Get input to end loop */
    char input;
    std::cout << "Do you want me to try again ? (Y | N) : ";
    std::cin >> input;
    if (input == 'n' || input == 'N')
    {
      break;
    }
  }

  std::cout << "Bu-bye dear. Short Kisses 😘" << std::endl;

  return 0;
}