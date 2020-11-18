#include <string>

#ifndef CONSOLE_H
#define CONSOLE_H

namespace Console
{
  void preventInvalidInput();
  std::string green(std::string);
  std::string red(std::string);
  std::string cyan(std::string);
} // namespace Console

#endif