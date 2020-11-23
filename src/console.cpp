#include "console.h"

#include <cassert>
#include <string>
#include <iostream>
#include <sstream>

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
} // namespace Console