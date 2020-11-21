#ifndef CONSOLE_H
#define CONSOLE_H

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
  std::string win(std::string);
  std::string loose(std::string);
  std::string ask(std::string);
} // namespace Console

#endif