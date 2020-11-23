#ifndef PRINTER_H
#define PRINTER_H

#include "Player.h"

#include <iostream>
#include <iterator>
#include <string>

class Printer
{
public:
  enum class Option
  {
    SuppressColor = 1 << 0,
    UnicodeCards = 1 << 1,
  };

private:
  enum class Color
  {
    No = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Cyan = 36,
  };

  std::ostream &m_out;
  unsigned char m_options{0};
  std::string m_cardIcons[4][13]{
      {"🃒", "🃓", "🃔", "🃕", "🃖", "🃗", "🃘", "🃙", "🃚", "🃛", "🃝", "🃞", "🃑"},
      {"🃂", "🃃", "🃄", "🃅", "🃆", "🃇", "🃈", "🃉", "🃊", "🃋", "🃍", "🃎", "🃁"},
      {"🂲", "🂳", "🂴", "🂵", "🂶", "🂷", "🂸", "🂹", "🂺", "🂻", "🂽", "🂾", "🂱"},
      {"🂢", "🂣", "🂤", "🂥", "🂦", "🂧", "🂨", "🂩", "🂪", "🂫", "🂭", "🂮", "🂡"}};

  Printer &paintString(const Color color, const std::string &input);
  Printer &card(const Card &card);
  Color pickCardColor(const Card &card);

public:
  Printer(std::ostream &out, unsigned char options = 0);

  Printer &player(const Player &);
  Printer &game(const Player &player, const Player &dealer);
  Printer &win(const std::string &);
  Printer &lose(const std::string &);
  Printer &tie(const std::string &);
  Printer &ask(const std::string &);
  Printer &newLine();

  friend Printer &operator<<(Printer &printer, const std::string& string);
  friend Printer &operator<<(Printer &printer, const char ch);
};

#endif