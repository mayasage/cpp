#include <iostream>
#include <bitset>
#include <vector>
#include <iomanip>

// Can use this instead of getMasks().
const unsigned char mask_bit_0{0b00000001}; // Bit0
const unsigned char mask_bit_1{0b00000010}; // Bit1
const unsigned char mask_bit_2{0b00000100}; // Bit2
const unsigned char mask_bit_3{0b00001000}; // Bit3
const unsigned char mask_bit_4{0b00010000}; // Bit4
const unsigned char mask_bit_5{0b00100000}; // Bit5
const unsigned char mask_bit_6{0b01000000}; // Bit6
const unsigned char mask_bit_7{0b10000000}; // Bit7

std::vector<unsigned char> getMasks();

void show_set_bits_to_one(std::vector<unsigned char>);
void show_set_bits_to_zero(std::vector<unsigned char>);
void show_check_bit_value(std::vector<unsigned char>);
void show_toggle_bit_value(std::vector<unsigned char>);

void show_masks_use_case();
void use_options_v0(bool, bool, bool, bool, bool, bool, bool, bool);
void use_options_v1(unsigned char);

void show_packing_color_information();

int main()
{
  // Declaration
  std::vector<unsigned char> masks = getMasks();

  show_set_bits_to_one(masks);
  show_set_bits_to_zero(masks);
  show_check_bit_value(masks);
  show_toggle_bit_value(masks);

  show_masks_use_case();

  return 0;
}

std::vector<unsigned char> getMasks()
{
  std::vector<unsigned char> masks;

  // 8 bit masks
  unsigned char mask_bit_0{0b00000001}; // Bit0
  unsigned char mask_bit_1{0b00000010}; // Bit1
  unsigned char mask_bit_2{0b00000100}; // Bit2
  unsigned char mask_bit_3{0b00001000}; // Bit3
  unsigned char mask_bit_4{0b00010000}; // Bit4
  unsigned char mask_bit_5{0b00100000}; // Bit5
  unsigned char mask_bit_6{0b01000000}; // Bit6
  unsigned char mask_bit_7{0b10000000}; // Bit7

  masks.push_back(mask_bit_0);
  masks.push_back(mask_bit_1);
  masks.push_back(mask_bit_2);
  masks.push_back(mask_bit_3);
  masks.push_back(mask_bit_4);
  masks.push_back(mask_bit_5);
  masks.push_back(mask_bit_6);
  masks.push_back(mask_bit_7);

  return masks;
}

void show_set_bits_to_one(std::vector<unsigned char> masks)
{
  // Declaration
  unsigned char var{0b00000000}; // Starts off all bits off
  unsigned char mask_bit_0 = masks.at(0);
  unsigned char mask_bit_4 = masks.at(4);

  std::cout
      << std::endl
      << "------------------------------"
      << std::endl
      << "  Set Bit to 1"
      << std::endl
      << std::endl;

  // Set Bit 0
  std::cout
      << std::endl
      << "Set Bit 0 to 1"
      << std::endl
      << std::endl;

  std::cout
      << "   var     = "
      << std::bitset<8>(var)
      << std::endl
      << "mask_bit_0 = "
      << std::bitset<8>(mask_bit_0)
      << std::endl
      << "var | mask = "
      << std::bitset<8>(var | mask_bit_0)
      << std::endl;

  std::cout << std::endl;

  // Set Bit 4
  std::cout
      << std::endl
      << "Set Bit 4 to 1"
      << std::endl
      << std::endl;

  std::cout
      << "   var     = "
      << std::bitset<8>(var)
      << std::endl
      << "mask_bit_4 = "
      << std::bitset<8>(mask_bit_4)
      << std::endl
      << "var | mask = "
      << std::bitset<8>(var | mask_bit_4)
      << std::endl;

  std::cout << std::endl;

  // Set All Bits to 1
  std::cout
      << std::endl
      << "Set All Bits to 1"
      << std::endl
      << std::endl;

  unsigned int index = 0;
  unsigned char or_of_all_masks = 0;
  for (unsigned char bits : masks)
  {
    std::cout
        << "mask_bit_"
        << index++
        << " = "
        << std::bitset<8>(bits)
        << std::endl;

    or_of_all_masks |= bits;
  }

  std::cout
      << "     OR    = "
      << std::bitset<8>(or_of_all_masks)
      << std::endl;

  std::cout << std::endl;

  // Set Selective Bits to 1
  std::cout
      << std::endl
      << "Set Even Bits to 1"
      << std::endl
      << std::endl;

  index = 0;
  unsigned char or_of_even_masks = 0;

  std::cout
      << "   var     = "
      << std::bitset<8>(or_of_even_masks)
      << std::endl;

  for (unsigned char bits : masks)
  {
    if (index % 2 == 0)
    {
      std::cout
          << "mask_bit_"
          << index
          << " = "
          << std::bitset<8>(bits)
          << std::endl;

      or_of_even_masks |= bits;
    }

    index++;
  }

  std::cout
      << "     OR    = "
      << std::bitset<8>(or_of_even_masks)
      << std::endl;

  std::cout << std::endl;
}

void show_set_bits_to_zero(std::vector<unsigned char> masks)
{
  // Declaration
  unsigned char var1{0b00000000};
  unsigned char var2{0b11111111};

  unsigned char mask_bit_0 = masks.at(0);
  unsigned char mask_bit_4 = masks.at(4);

  unsigned char neg_mask_bit_0 = ~masks.at(0);
  unsigned char neg_mask_bit_4 = ~masks.at(4);

  std::cout
      << std::endl
      << "------------------------------"
      << std::endl
      << "  Set Bit to 0"
      << std::endl
      << std::endl;

  // Set Bit 0 to 1
  std::cout
      << std::endl
      << "Set Bit 0 to 0"
      << std::endl
      << std::endl;

  std::cout
      << "        var1          = "
      << std::bitset<8>(var1)
      << std::endl
      << "    neg_mask_bit_0    = "
      << std::bitset<8>(neg_mask_bit_0)
      << std::endl
      << "var1 & neg_mask_bit_0 = "
      << std::bitset<8>(var1 & neg_mask_bit_0)
      << std::endl;

  std::cout
      << std::endl;

  std::cout
      << "        var2          = "
      << std::bitset<8>(var2)
      << std::endl
      << "    neg_mask_bit_0    = "
      << std::bitset<8>(neg_mask_bit_0)
      << std::endl
      << "var2 & neg_mask_bit_0 = "
      << std::bitset<8>(var2 & neg_mask_bit_0)
      << std::endl;

  std::cout
      << std::endl;

  // Set Bit 4 to 0
  std::cout
      << std::endl
      << "Set Bit 4 to 0"
      << std::endl
      << std::endl;

  std::cout
      << "        var1          = "
      << std::bitset<8>(var1)
      << std::endl
      << "    neg_mask_bit_4    = "
      << std::bitset<8>(neg_mask_bit_4)
      << std::endl
      << "var1 & neg_mask_bit_4 = "
      << std::bitset<8>(var1 & neg_mask_bit_4)
      << std::endl;

  std::cout
      << std::endl;

  std::cout
      << "        var2          = "
      << std::bitset<8>(var2)
      << std::endl
      << "    neg_mask_bit_4    = "
      << std::bitset<8>(neg_mask_bit_4)
      << std::endl
      << "var2 & neg_mask_bit_4 = "
      << std::bitset<8>(var2 & neg_mask_bit_4)
      << std::endl;

  std::cout << std::endl;

  // Set All Bits to 1
  std::cout
      << std::endl
      << "Set All Bits to 0"
      << std::endl
      << std::endl;

  unsigned int index = 0;
  unsigned char or_all_neg_masks = 0;
  for (unsigned char bits : masks)
  {
    bits = ~bits;

    std::cout
        << "neg_mask_bit_"
        << index++
        << " = "
        << std::bitset<8>(bits)
        << std::endl;

    or_all_neg_masks &= bits;
  }

  std::cout
      << "      AND      = "
      << std::bitset<8>(or_all_neg_masks)
      << std::endl;

  std::cout << std::endl;

  // Set Selective Bits to 0
  std::cout
      << std::endl
      << "Set Odd Bits to 0"
      << std::endl
      << std::endl;

  index = 0;
  unsigned char or_of_odd_neg_masks{0b11111111};

  std::cout
      << "     var       = "
      << std::bitset<8>(or_of_odd_neg_masks)
      << std::endl;

  for (unsigned char bits : masks)
  {
    if (index % 2 != 0)
    {
      bits = ~bits;

      std::cout
          << "neg_mask_bit_"
          << index
          << " = "
          << std::bitset<8>(bits)
          << std::endl;

      or_of_odd_neg_masks &= bits;
    }

    index++;
  }

  std::cout
      << "     AND       = "
      << std::bitset<8>(or_of_odd_neg_masks)
      << std::endl;

  std::cout << std::endl;
}

void show_check_bit_value(std::vector<unsigned char> masks)
{
  // Declaration
  unsigned char var{0b01010101};

  // Printing
  std::cout
      << std::endl
      << "------------------------------"
      << std::endl
      << "  Check Bit Value"
      << std::endl
      << std::endl;

  std::cout
      << "      var        = "
      << std::bitset<8>(var)
      << std::endl
      << std::endl;

  unsigned int index{0};
  for (unsigned char bits : masks)
  {
    unsigned char bit_at_pos{static_cast<unsigned char>((var & bits) >> index)};
    bool bit_at_pos_bool{static_cast<bool>(bit_at_pos)};

    std::cout
        << "   mask_bit_"
        << index
        << "    = "
        << std::bitset<8>(bits)
        << std::endl
        << "var & mask_bit_"
        << index
        << " = "
        << std::bitset<8>(var & bits)
        << std::endl
        << "      >> "
        << index
        << "       = "
        << std::bitset<8>((var & bits) >> index)
        << std::endl
        << "    Bit at "
        << index
        << "     = "
        << std::bitset<8>(bit_at_pos)
        << std::endl
        << "      Bool       = "
        << bit_at_pos_bool
        << std::endl
        << std::endl;

    index++;
  }
}

void show_toggle_bit_value(std::vector<unsigned char> masks)
{
  // Declaration
  unsigned char var1{0b00000000};
  unsigned char var2{0b11111111};

  unsigned char mask_bit_0 = masks.at(0);
  unsigned char mask_bit_4 = masks.at(4);

  std::cout
      << std::endl
      << "------------------------------"
      << std::endl
      << "  Toggle Bit Value"
      << std::endl
      << std::endl;

  // Toggle Bit 0
  std::cout
      << std::endl
      << "Toggle Bit 0"
      << std::endl
      << std::endl;

  std::cout
      << "       var1       = "
      << std::bitset<8>(var1)
      << std::endl
      << "    mask_bit_0    = "
      << std::bitset<8>(mask_bit_0)
      << std::endl
      << "var1 ^ mask_bit_0 = "
      << std::bitset<8>(var1 ^ mask_bit_0)
      << std::endl;

  std::cout
      << std::endl;

  std::cout
      << "       var2       = "
      << std::bitset<8>(var2)
      << std::endl
      << "    mask_bit_0    = "
      << std::bitset<8>(mask_bit_0)
      << std::endl
      << "var2 ^ mask_bit_0 = "
      << std::bitset<8>(var2 ^ mask_bit_0)
      << std::endl;

  std::cout
      << std::endl;

  // Toggle Bit 4
  std::cout
      << std::endl
      << "Toggle Bit 4"
      << std::endl
      << std::endl;

  std::cout
      << "       var1       = "
      << std::bitset<8>(var1)
      << std::endl
      << "    mask_bit_4    = "
      << std::bitset<8>(mask_bit_4)
      << std::endl
      << "var1 ^ mask_bit_4 = "
      << std::bitset<8>(var1 ^ mask_bit_4)
      << std::endl;

  std::cout
      << std::endl;

  std::cout
      << "       var2       = "
      << std::bitset<8>(var2)
      << std::endl
      << "    mask_bit_4    = "
      << std::bitset<8>(mask_bit_4)
      << std::endl
      << "var2 ^ mask_bit_4 = "
      << std::bitset<8>(var2 ^ mask_bit_4)
      << std::endl;

  std::cout << std::endl;

  // Toggle All Bits
  std::cout
      << std::endl
      << "Toggle All Bits"
      << std::endl
      << std::endl;

  unsigned char or_all_masks{0b11111111};

  std::cout
      << "     or_all_masks    = "
      << std::bitset<8>(or_all_masks)
      << std::endl
      << std::endl;

  std::cout
      << "         var1        = "
      << std::bitset<8>(var1)
      << std::endl
      << " var1 ^ or_all_masks = "
      << std::bitset<8>(var1 ^ or_all_masks)
      << std::endl;

  std::cout << std::endl;

  std::cout
      << "         var2        = "
      << std::bitset<8>(var2)
      << std::endl
      << " var2 ^ or_all_masks = "
      << std::bitset<8>(var2 ^ or_all_masks)
      << std::endl;

  std::cout << std::endl;

  // Toggle Selective Bits
  unsigned char var3{0b01010101};

  unsigned int index{0};

  // Toggle Odd Bits
  std::cout
      << std::endl
      << "Toggle Odd Bits"
      << std::endl
      << std::endl;

  index = 0;
  unsigned char or_odd_masks{0};

  for (unsigned char bits : masks)
  {
    if (index % 2 != 0)
    {
      std::cout
          << "      mask_bit_"
          << index
          << "      = "
          << std::bitset<8>(bits)
          << std::endl;

      or_odd_masks |= bits;
    }

    index++;
  }

  std::cout
      << "     or_odd_masks     = "
      << std::bitset<8>(or_odd_masks)
      << std::endl
      << std::endl;

  std::cout
      << "         var1         = "
      << std::bitset<8>(var1)
      << std::endl
      << " var1 ^ or_odd_masks  = "
      << std::bitset<8>(var1 ^ or_odd_masks)
      << std::endl;

  std::cout << std::endl;

  std::cout
      << "         var2         = "
      << std::bitset<8>(var2)
      << std::endl
      << " var2 ^ or_odd_masks  = "
      << std::bitset<8>(var2 ^ or_odd_masks)
      << std::endl;

  std::cout << std::endl;

  std::cout
      << "         var3         = "
      << std::bitset<8>(var3)
      << std::endl
      << " var3 ^ or_odd_masks  = "
      << std::bitset<8>(var3 ^ or_odd_masks)
      << std::endl;

  std::cout << std::endl;

  // Toggle Odd Bits
  std::cout
      << std::endl
      << "Toggle Even Bits"
      << std::endl
      << std::endl;

  index = 0;
  unsigned char or_even_masks{0};

  for (unsigned char bits : masks)
  {
    if (index % 2 == 0)
    {
      std::cout
          << "      mask_bit_"
          << index
          << "      = "
          << std::bitset<8>(bits)
          << std::endl;

      or_even_masks |= bits;
    }

    index++;
  }

  std::cout
      << "    or_even_masks     = "
      << std::bitset<8>(or_even_masks)
      << std::endl
      << std::endl;

  std::cout
      << "         var1         = "
      << std::bitset<8>(var1)
      << std::endl
      << " var1 ^ or_even_masks = "
      << std::bitset<8>(var1 ^ or_even_masks)
      << std::endl;

  std::cout << std::endl;

  std::cout
      << "         var2         = "
      << std::bitset<8>(var2)
      << std::endl
      << " var2 ^ or_even_masks = "
      << std::bitset<8>(var2 ^ or_even_masks)
      << std::endl;

  std::cout << std::endl;

  std::cout
      << "         var3         = "
      << std::bitset<8>(var3)
      << std::endl
      << " var3 ^ or_even_masks = "
      << std::bitset<8>(var3 ^ or_even_masks)
      << std::endl;

  std::cout << std::endl;
}

void show_masks_use_case()
{
  std::cout
      << std::endl
      << "------------------------------"
      << std::endl
      << "  Show Masks Use Case -> Passing Bools as Arguments"
      << std::endl
      << std::endl;

  // Even Bools
  std::cout
      << std::endl
      << "Even Bools"
      << std::endl
      << std::endl;

  unsigned char even_bools{mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6};

  use_options_v0(0, 1, 0, 1, 0, 1, 0, 1);
  use_options_v1(even_bools);

  // Odd Bools
  std::cout
      << std::endl
      << "Odd Bools"
      << std::endl
      << std::endl;

  unsigned char odd_bools{mask_bit_1 | mask_bit_3 | mask_bit_5 | mask_bit_7};

  use_options_v0(1, 0, 1, 0, 1, 0, 1, 0);
  use_options_v1(odd_bools);

  std::cout
      << std::endl
      << "------------------------------"
      << std::endl
      << "  Show Masks Use Case -> Show Packing Color Information"
      << std::endl
      << std::endl;

  show_packing_color_information();
}

void use_options_v0(bool flag0, bool flag1, bool flag2, bool flag3,
                    bool flag4, bool flag5, bool flag6, bool flag7)
{
  std::cout
      << "Function with Bools : use_options_v0 (8 bools * 8 bits = 64 bits)"
      << std::endl
      << "Received... " << std::endl
      << " flag0 : " << flag0 << std::endl
      << " flag1 : " << flag1 << std::endl
      << " flag2 : " << flag2 << std::endl
      << " flag3 : " << flag3 << std::endl
      << " flag4 : " << flag4 << std::endl
      << " flag5 : " << flag5 << std::endl
      << " flag6 : " << flag6 << std::endl
      << " flag7 : " << flag7 << std::endl
      << "("
      << flag0
      << flag1
      << flag2
      << flag3
      << flag4
      << flag5
      << flag6
      << flag7
      << ")"
      << std::endl;

  std::cout
      << std::endl;
}

void use_options_v1(unsigned char flags)
{
  std::cout
      << "Function with Bits : use_options_v1 (8 bits)"
      << std::endl
      << "Received... " << std::endl
      << " flag0 : " << ((flags & mask_bit_7) >> 7) << std::endl
      << " flag1 : " << ((flags & mask_bit_6) >> 6) << std::endl
      << " flag2 : " << ((flags & mask_bit_5) >> 5) << std::endl
      << " flag3 : " << ((flags & mask_bit_4) >> 4) << std::endl
      << " flag4 : " << ((flags & mask_bit_3) >> 3) << std::endl
      << " flag5 : " << ((flags & mask_bit_2) >> 2) << std::endl
      << " flag6 : " << ((flags & mask_bit_1) >> 1) << std::endl
      << " flag7 : " << ((flags & mask_bit_0) >> 0) << std::endl
      << "("
      << ((flags & mask_bit_7) >> 7)
      << ((flags & mask_bit_6) >> 6)
      << ((flags & mask_bit_5) >> 5)
      << ((flags & mask_bit_4) >> 4)
      << ((flags & mask_bit_3) >> 3)
      << ((flags & mask_bit_2) >> 2)
      << ((flags & mask_bit_1) >> 1)
      << ((flags & mask_bit_0) >> 0)
      << ")"
      << std::endl;

  std::cout << std::endl;
}

void show_packing_color_information()
{
  const unsigned int red_mask{0xFF000000};
  const unsigned int green_mask{0x00FF0000};
  const unsigned int blue_mask{0x0000FF00};
  const unsigned int alpha_mask{0x000000FF}; // Transparency information

  unsigned int my_color{0xAABCDE00};

  // Print Configurations
  std::cout
      << std::hex
      << std::showbase;

  std::cout
      << std::endl
      << "Red Mask   = " << red_mask << std::endl
      << "Green Mask = " << green_mask << std::endl
      << "Blue Mask  = " << blue_mask << std::endl
      << "Alpha Mask = " << alpha_mask << std::endl;

  std::cout
      << std::endl
      << "My Color : " << my_color << std::endl;

  std::cout
      << std::endl
      << "Red   = " << ((my_color & red_mask) >> 24) << std::endl
      << "Green = " << ((my_color & green_mask) >> 16) << std::endl
      << "Blue  = " << ((my_color & blue_mask) >> 8) << std::endl
      << "Alpha = " << ((my_color & alpha_mask) >> 0) << std::endl
      << std::endl;
}
