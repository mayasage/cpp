#include <iostream>
#include <iomanip>

void test_setting_column_width();
void test_justifying_data_in_column();
void test_substituting_spaces();
void test_show_plus_sign_on_positive_numbers();
void test_other_number_systems();
void test_number_casing();
void test_formatting_floating_point_numbers();

int main()
{
  test_setting_column_width();
  test_justifying_data_in_column();
  test_substituting_spaces();
  test_show_plus_sign_on_positive_numbers();
  test_other_number_systems();
  test_number_casing();
  test_formatting_floating_point_numbers();

  return 0;
}

void test_setting_column_width()
{
  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Set column width -> std::setw"
      << std::endl;

  unsigned int name_col_width = 15;
  unsigned int place_col_width = 25;

  // Heading
  std::cout
      << std::setw(name_col_width)
      << "Name"
      << std::setw(place_col_width)
      << "Place"
      << std::endl;

  // Row
  std::cout
      << std::setw(name_col_width)
      << "Lara Alana"
      << std::setw(place_col_width)
      << "Kuala Lumpur, Malaysia"
      << std::endl;

  std::cout << std::endl;
}

void test_justifying_data_in_column()
{
  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Justification -> std::left|right|internal"
      << std::endl;

  unsigned int name_col_width = 15;
  unsigned int place_col_width = 25;

  // Right justified
  std::cout
      << std::endl
      << "  Right Justification -> std::right (default)..."
      << std::endl
      << std::endl;

  std::cout << std::right; // default setting

  // Heading
  std::cout
      << std::setw(name_col_width)
      << "Name"
      << std::setw(place_col_width)
      << "Place"
      << std::endl;

  // Row
  std::cout
      << std::setw(name_col_width)
      << "Lara Alana"
      << std::setw(place_col_width)
      << "Kuala Lumpur, Malaysia"
      << std::endl;

  // Left justify
  std::cout
      << std::endl
      << "  Left Justification -> std::left..."
      << std::endl
      << std::endl;

  std::cout << std::left;

  // Heading
  std::cout
      << std::setw(name_col_width)
      << "Name"
      << std::setw(place_col_width)
      << "Place"
      << std::endl;

  // Row
  std::cout
      << std::setw(name_col_width)
      << "Lara Alana"
      << std::setw(place_col_width)
      << "Kuala Lumpur, Malaysia"
      << std::endl;

  // Justify Internally: sign is left, data is right
  std::cout
      << std::endl
      << "  Internal Justification (sign left, data right) -> std::internal..."
      << std::endl
      << std::endl;

  std::cout << std::internal;
  std::cout << std::showpos; // shows + sign

  // Heading
  std::cout
      << std::setw(name_col_width)
      << "Double-1"
      << std::setw(place_col_width)
      << "Double-2"
      << std::endl;

  // Row
  std::cout
      << std::setw(name_col_width)
      << -123.777
      << std::setw(place_col_width)
      << 69.96
      << std::endl;

  std::cout << std::endl;
}

void test_substituting_spaces()
{
  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Substitute spaces with any character -> std::setfill"
      << std::endl;

  unsigned int name_col_width = 15;
  unsigned int place_col_width = 25;

  std::cout << std::setfill('+');

  // Heading
  std::cout
      << std::setw(name_col_width)
      << "Name"
      << std::setw(place_col_width)
      << "Place"
      << std::endl;

  // Row
  std::cout
      << std::setw(name_col_width)
      << "Lara Alana"
      << std::setw(place_col_width)
      << "Kuala Lumpur, Malaysia"
      << std::endl;

  std::cout << std::endl;
}

void test_show_plus_sign_on_positive_numbers()
{
  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Show/Hide a Number's positive sign -> std::showpos"
      << std::endl;

  // noshowpos
  std::cout
      << std::endl
      << "  Don't show plus sign -> noshowpos (default)..."
      << std::endl
      << std::endl;

  std::cout << std::noshowpos; // doesn't shows + sign, by default

  std::cout << "Positive 25 : " << 25 << std::endl;

  // showpos
  std::cout
      << std::endl
      << "  Show plus sign -> std::showpos..."
      << std::endl
      << std::endl;

  std::cout << std::showpos; // doesn't shows + sign, by default

  std::cout << "Positive 25 : " << 25 << std::endl;

  std::cout << std::endl;
}

void test_other_number_systems()
{
  // Set std::cout configurations
  std::cout << std::noshowpos;

  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Number System -> std::dec|hex|oct"
      << std::endl;

  // decimal
  std::cout
      << std::endl
      << "  Decimal -> std::dec (default)..."
      << std::endl
      << std::endl;

  std::cout << std::dec; // set decimal number system

  std::cout << "Num 9999 : " << 9999 << std::endl;

  // octal
  std::cout
      << std::endl
      << "  Octal -> std::oct..."
      << std::endl
      << std::endl;

  std::cout << std::oct; // set octal number system

  std::cout << "Num 9999 : " << 9999 << std::endl;

  // hexadecimal
  std::cout
      << std::endl
      << "  Hexadecimal -> std::hex..."
      << std::endl
      << std::endl;

  std::cout << std::hex; // set hexadecimal number system

  std::cout << "Num 9999 : " << 9999 << std::endl;

  // floating point numbers are unaffected
  std::cout
      << std::endl
      << "  floating point numbers (unaffected) ..."
      << std::endl
      << std::endl;

  std::cout << "Float 9999.99f : " << 9999.99f << std::endl;
  std::cout << "Double 9999.99 : " << 9999.99 << std::endl;

  std::cout << std::endl;

  std::cout
      << "Unaffected because floating point numbers are stored differently."
      << std::endl;

  std::cout << std::endl;
}

void test_number_casing()
{
  // Set std::cout configurations
  std::cout << std::noshowpos;

  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Number Casing -> std::uppercase|nouppercase"
      << std::endl;

  // nouppercase
  std::cout
      << std::endl
      << "  No Uppercase => std::nouppercase (default)..."
      << std::endl
      << std::endl;

  std::cout << std::nouppercase; // default

  // hexadecimal

  std::cout << std::hex; // set hexadecimal number system

  std::cout << "Num 9999 in Hex : " << 9999 << std::endl;

  // nouppercase
  std::cout
      << std::endl
      << "  Uppercase => std::uppercase..."
      << std::endl
      << std::endl;

  std::cout << std::uppercase;

  // hexadecimal

  std::cout << std::hex; // set hexadecimal number system

  std::cout << "Num 9999 in Hex : " << 9999 << std::endl;

  std::cout << std::endl;
}

void test_formatting_floating_point_numbers()
{
  // Set std::cout configurations
  std::cout << std::noshowpos;

  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Force Formatting Floating Point Numbers -> std::fixed|scientific"
      << std::endl;

  // default
  std::cout
      << std::endl
      << "  Default..."
      << std::endl
      << std::endl;

  std::cout << "Num 9999.999 : " << 9999.999 << std::endl;

  // fixed
  std::cout
      << std::endl
      << "  Force Fixed => std::fixed..."
      << std::endl
      << std::endl;

  std::cout << std::fixed;

  std::cout << "Num 9999.999 : " << 9999.999 << std::endl;

  // scientific
  std::cout
      << std::endl
      << "  Force Scientific => std::scientific..."
      << std::endl
      << std::endl;

  std::cout << std::scientific;

  std::cout << "Num 9999.999 : " << 9999.999 << std::endl;

  // unset
  std::cout
      << std::endl
      << "  Unset (back to default) Hack => "
      << "std::cout.unsetf(std::ios::scientific | std::ios::fixed)..."
      << std::endl
      << std::endl;

  std::cout.unsetf(std::ios::scientific | std::ios::fixed); // back to default

  std::cout << "Num 9999.999 : " << 9999.999 << std::endl;

  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Setting precision for Floating Point Numbers -> std::setprecision"
      << std::endl
      << std::endl;

  std::cout << std::fixed;

  std::cout << std::setprecision(10);

  std::cout
      << "Num 3.141592653589793238 (precision 10) : "
      << 3.141592653589793238 << std::endl;

  std::cout << std::setprecision(20);

  std::cout
      << "Num 3.141592653589793238 (precision 20) : "
      << 3.141592653589793238 << std::endl;

  std::cout
      << std::endl
      << "Prints garbage from (setprecision - number's-type_max_precision)..."
      << std::endl
      << std::endl;

  std::cout << "Num 9999.0 : " << 9999.01 << std::endl;

  // Reset configurations
  std::cout.unsetf(std::ios::scientific | std::ios::fixed); // back to default
  std::cout << std::dec;

  std::cout
      << std::endl
      << "-------------------------------------------------"
      << std::endl
      << "  Always add decimal point -> std::noshowpoint|showpoint"
      << std::endl
      << std::endl;

  // noshowpoint
  std::cout
      << std::endl
      << "  Don't show if number is whole -> std::noshowpoint (default)..."
      << std::endl
      << std::endl;

  std::cout << std::noshowpoint;

  std::cout << "Num 9999.0 : " << 9999.0 << std::endl;

  // showpoint
  std::cout
      << std::endl
      << "  Show even if number is whole -> std::showpoint..."
      << std::endl
      << std::endl;

  std::cout << std::showpoint;

  std::cout << "Num 9999.0 : " << 9999.0 << std::endl;

  std::cout << std::endl;
}
