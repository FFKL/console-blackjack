#ifndef CONSOLE_H
#define CONSOLE_H

#include "Card.h"

#include <string>

namespace Console
{
  enum class Option
  {
    SuppressColor = 1 << 0,
    UnicodeCards = 1 << 1,
  };
  void preventInvalidInput();
  void setOptions(unsigned char flags);
  std::string win(const std::string &);
  std::string lose(const std::string &);
  std::string ask(const std::string &);
  std::string card(const Card &);
} // namespace Console

#endif