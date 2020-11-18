#include "console.h"

#include <string>
#include <iostream>

namespace Console
{
  void preventInvalidInput()
  {
    if (std::cin.fail())
    {
      std::cin.clear();
    }
    std::cin.ignore(32767, '\n');
  }
  
  std::string green(std::string str)
  {
    return "\x1B[32m" + str + "\033[0m";
  }

  std::string red(std::string str)
  {
    return "\x1B[31m" + str + "\033[0m";
  }

  std::string cyan(std::string str)
  {
    return "\x1B[36m" + str + "\033[0m";
  }
} // namespace Console