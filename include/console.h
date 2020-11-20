#include <string>

#ifndef CONSOLE_H
#define CONSOLE_H

namespace Console
{
  enum class Options
  {
    SuppressColor = 1 << 0,
    UnicodeCards = 1 << 1,
  };
  void preventInvalidInput();
  std::string green(std::string);
  std::string red(std::string);
  std::string cyan(std::string);
} // namespace Console

#endif