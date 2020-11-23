#include "Printer.h"
#include "console.h"

#include <iostream>

Printer::Printer(std::ostream &out) : m_out{out} {}

std::ostream &Printer::deck(const Deck &deck)
{
  for (const auto &card : deck.getCards())
    m_out << Console::card(card) << ' ';

  return m_out;
}

std::ostream &Printer::player(const Player &player)
{
  for (auto &card : player.deck())
    m_out << Console::card(card) << ' ';

  return m_out;
}

std::ostream &Printer::win(const std::string &text)
{
  return m_out << Console::win(text);
}

std::ostream &Printer::lose(const std::string &text)
{
  return m_out << Console::lose(text);
}

std::ostream &Printer::ask(const std::string &text)
{
  return m_out << Console::ask(text);
}
