#include "Session.h"
#include "console.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

unsigned char getConsoleOptions(int argc, char *argv[])
{
  unsigned char options{0};
  for (int i{1}; i < argc; ++i)
  {
    auto arg{argv[i]};
    if (!strcmp(arg, "--suppress-color"))
    {
      options |= static_cast<char>(Console::Option::SuppressColor);
      continue;
    }

    if (!strcmp(arg, "--unicode-cards"))
    {
      options |= static_cast<char>(Console::Option::UnicodeCards);
      continue;
    }

    std::cerr << "Invalid argument - " << arg << '\n';
    exit(1);
  }

  return options;
}

int main(int argc, char *argv[])
{
  auto options{getConsoleOptions(argc, argv)};
  Console::setOptions(options);
  Session session;
  session.play();
  return 0;
}
