#include "Session.h"
#include "console.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <assert.h>

unsigned char getConsoleOptions(int argc, char *argv[])
{
  unsigned char options{0};
  for (int i{1}; i < argc; ++i)
  {
    auto arg{argv[i]};
    if (!strcmp(arg, "--suppress-color"))
    {
      options |= static_cast<char>(Console::Options::SuppressColor);
      continue;
    }

    if (!strcmp(arg, "--unicode-cards"))
    {
      options |= static_cast<char>(Console::Options::UnicodeCards);
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
  std::cout << static_cast<int>(options) << '\n';
  Session session;
  session.play();
  return 0;
}
