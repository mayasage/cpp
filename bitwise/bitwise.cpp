#include <iostream>
#include <bitset>

void showPrintBinary();
void showShift();
void showRightShift();
void showLeftShift();
void show3BitwiseOps();
void showBitwiseNot();

int main()
{
  showPrintBinary();

  showShift();

  show3BitwiseOps();

  showBitwiseNot();

  return 0;
}

void showPrintBinary()
{
  // Print binary
  std::cout
      << std::endl
      << "-------------------------------"
      << std::endl
      << "  Print Binary"
      << std::endl
      << std::endl;

  // Declaration
  unsigned short int data{0b11111110};

  // Print
  std::cout << std::showbase;

  std::cout << std::dec << "dec : " << data << std::endl;
  std::cout << std::oct << "oct : " << data << std::endl;
  std::cout << std::hex << "hex : " << data << std::endl;

  std::cout << "bin : " << std::bitset<16>(data) << std::endl;

  std::cout << std::endl;
}

void showShift()
{
  // Declaration
  unsigned short int value{0xff0u};

  // Print
  std::cout << std::dec;

  std::cout << value << " = " << std::bitset<16>(value) << std::endl;

  showRightShift();

  showLeftShift();

  std::cout << std::endl;
}

void showRightShift()
{
  // Declaration
  unsigned short int value{0xff0u};
  unsigned short int right_shift_value;

  // Printing
  std::cout
      << std::endl
      << "-------------------------------"
      << std::endl
      << "  Shift right"
      << std::endl
      << std::endl;

  std::cout
      << std::endl
      << "Shift right once -> >> 1"
      << std::endl
      << std::endl;

  right_shift_value = static_cast<unsigned short int>(value >> 1);

  std::cout
      << value
      << " ("
      << std::bitset<16>(value)
      << ") >> 1 = "
      << right_shift_value
      << " ("
      << std::bitset<16>(right_shift_value)
      << ") "
      << std::endl;

  std::cout
      << std::endl
      << "Shift right twice -> >> 2"
      << std::endl
      << std::endl;

  right_shift_value = static_cast<unsigned short int>(value >> 2);

  std::cout
      << value
      << " ("
      << std::bitset<16>(value)
      << ") >> 2 = "
      << right_shift_value
      << " ("
      << std::bitset<16>(right_shift_value)
      << ") "
      << std::endl;

  std::cout
      << std::endl
      << "Shifting right divides by 2, unless you're throwing off 1s."
      << std::endl;

  std::cout << std::endl;
}

void showLeftShift()
{
  // Declaration
  unsigned short int value{0xff0u};
  unsigned short int left_shift_value;

  // Printing
  std::cout
      << std::endl
      << "-------------------------------"
      << std::endl
      << "  Shift Left"
      << std::endl
      << std::endl;

  std::cout
      << std::endl
      << "Shift left once -> << 1"
      << std::endl
      << std::endl;

  left_shift_value = static_cast<unsigned short int>(value << 1);

  std::cout
      << value
      << " ("
      << std::bitset<16>(value)
      << ") << 1 = "
      << left_shift_value
      << " ("
      << std::bitset<16>(left_shift_value)
      << ") "
      << std::endl;

  std::cout
      << std::endl
      << "Shift left twice -> << 2"
      << std::endl
      << std::endl;

  left_shift_value = static_cast<unsigned short int>(value << 2);

  std::cout
      << value
      << " ("
      << std::bitset<16>(value)
      << ") << 2 = "
      << left_shift_value
      << " ("
      << std::bitset<16>(left_shift_value)
      << ") "
      << std::endl;

  std::cout
      << std::endl
      << "Shifting left multiplies by 2, unless you're throwing off 1s.";

  std::cout
      << std::endl;
}

void show3BitwiseOps()
{
  std::cout
      << std::endl
      << "-------------------------------"
      << std::endl
      << "  Bitwise Operations -> ^ & |"
      << std::endl
      << std::endl;

  unsigned char value1{0x3};
  unsigned char value2{0x5};

  unsigned char valueAnd{static_cast<unsigned char>(value1 & value2)};
  unsigned char valueOr{static_cast<unsigned char>(value1 | value2)};
  unsigned char valueXor{static_cast<unsigned char>(value1 ^ value2)};

  std::cout
      << std::bitset<8>(value1)
      << " ("
      << static_cast<int>(value1)
      << ") "
      << " & "
      << std::bitset<8>(value2)
      << " ("
      << static_cast<int>(value2)
      << ") "
      << " = "
      << std::bitset<8>(valueAnd)
      << " ("
      << static_cast<int>(valueAnd)
      << ") "
      << std::endl;

  std::cout
      << std::bitset<8>(value1)
      << " ("
      << static_cast<int>(value1)
      << ") "
      << " | "
      << std::bitset<8>(value2)
      << " ("
      << static_cast<int>(value2)
      << ") "
      << " = "
      << std::bitset<8>(valueOr)
      << " ("
      << static_cast<int>(valueOr)
      << ") "
      << std::endl;

  std::cout
      << std::bitset<8>(value1)
      << " ("
      << static_cast<int>(value1)
      << ") "
      << " ^ "
      << std::bitset<8>(value2)
      << " ("
      << static_cast<int>(value2)
      << ") "
      << " = "
      << std::bitset<8>(valueXor)
      << " ("
      << static_cast<int>(valueXor)
      << ") "
      << std::endl;

  std::cout << std::endl;
}

void showBitwiseNot()
{
  // Heading
  std::cout
      << std::endl
      << "-------------------------------"
      << std::endl
      << "  Bitwise NOT"
      << std::endl
      << std::endl;

  // Declaration
  unsigned char value1{0x3};
  unsigned char value2{0x5};
  unsigned char value3{0b01011001};
  unsigned char value4{0x59};

  unsigned char value1Not{static_cast<unsigned char>(~value1)};
  unsigned char value2Not{static_cast<unsigned char>(~value2)};
  unsigned char value3Not{static_cast<unsigned char>(~value3)};
  unsigned char value4Not{static_cast<unsigned char>(~value4)};

  // Printing
  std::cout
      << "~ "
      << std::bitset<8>(value1)
      << " ("
      << static_cast<int>(value1)
      << ") = "
      << std::bitset<8>(value1Not)
      << " ("
      << static_cast<int>(value1Not)
      << ") "
      << std::endl;

  std::cout
      << "~ "
      << std::bitset<8>(value2)
      << " ("
      << static_cast<int>(value2)
      << ") = "
      << std::bitset<8>(value2Not)
      << " ("
      << static_cast<int>(value2Not)
      << ") "
      << std::endl;

  std::cout
      << "~ "
      << std::bitset<8>(value3)
      << " ("
      << static_cast<int>(value3)
      << ") = "
      << std::bitset<8>(value3Not)
      << " ("
      << static_cast<int>(value3Not)
      << ") "
      << std::endl;

  std::cout
      << "~ "
      << std::bitset<8>(value4)
      << " ("
      << static_cast<int>(value4)
      << ") = "
      << std::bitset<8>(value4Not)
      << " ("
      << static_cast<int>(value4Not)
      << ") "
      << std::endl;

  std::cout << std::endl;
}