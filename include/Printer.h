#ifndef PRINTER_H
#define PRINTER_H

#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <iterator>

class Printer
{
private:
  std::ostream &m_out;

public:
  Printer(std::ostream &out);
  std::ostream &deck(const Deck &);
  std::ostream &player(const Player &);

  std::ostream &win(const std::string &);
  std::ostream &lose(const std::string &);
  std::ostream &ask(const std::string &);
};

#endif