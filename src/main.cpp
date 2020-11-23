#include "Session.h"
#include "Printer.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

unsigned char getPrinterOptions(int argc, char *argv[])
{
  unsigned char options{0};
  for (int i{1}; i < argc; ++i)
  {
    auto arg{argv[i]};
    if (!strcmp(arg, "--suppress-color"))
    {
      options |= static_cast<char>(Printer::Option::SuppressColor);
      continue;
    }

    if (!strcmp(arg, "--unicode-cards"))
    {
      options |= static_cast<char>(Printer::Option::UnicodeCards);
      continue;
    }

    std::cerr << "Invalid argument - " << arg << '\n';
    exit(1);
  }

  return options;
}

int main(int argc, char *argv[])
{
  Printer printer{std::cout, getPrinterOptions(argc, argv)};
  Session session{printer};
  session.play();
  return 0;
}
