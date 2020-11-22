#include "console.h"

#include <string>
#include <iostream>
#include <sstream>

namespace Console
{
  unsigned char options{0};

  std::string cardIcons[4][13]{
      {"🃒", "🃓", "🃔", "🃕", "🃖", "🃗", "🃘", "🃙", "🃚", "🃛", "🃝", "🃞", "🃑"},
      {"🃂", "🃃", "🃄", "🃅", "🃆", "🃇", "🃈", "🃉", "🃊", "🃋", "🃍", "🃎", "🃁"},
      {"🂲", "🂳", "🂴", "🂵", "🂶", "🂷", "🂸", "🂹", "🂺", "🂻", "🂽", "🂾", "🂱"},
      {"🂢", "🂣", "🂤", "🂥", "🂦", "🂧", "🂨", "🂩", "🂪", "🂫", "🂭", "🂮", "🂡"},
  };

  enum class Color
  {
    No = 0,
    Red = 31,
    Green = 32,
    Cyan = 36,
  };

  unsigned char operator&(unsigned char options, Option option)
  {
    return options & static_cast<unsigned char>(option);
  }

  std::string paintString(const Color color, const std::string &input)
  {
    if (options & Option::SuppressColor)
    {
      return input;
    }
    std::stringstream ss;
    ss << "\033[" << static_cast<int>(color) << "m" << input << "\033[0m";

    return ss.str();
  }

  void preventInvalidInput()
  {
    if (std::cin.fail())
    {
      std::cin.clear();
    }
    std::cin.ignore(32767, '\n');
  }

  void setOptions(unsigned char flags)
  {
    options |= flags;
  }

  std::string win(const std::string &str)
  {
    return paintString(Color::Green, str);
  }

  std::string loose(const std::string &str)
  {
    return paintString(Color::Red, str);
  }

  std::string ask(const std::string &str)
  {
    return paintString(Color::Cyan, str);
  }

  std::string card(const Card &card)
  {
    if (options & Option::UnicodeCards)
    {
      return cardIcons[static_cast<int>(card.suit())][static_cast<int>(card.rank())];
    }
    std::stringstream ss;
    ss << card;
    return ss.str();
  }
} // namespace Console