#include "Printer.h"
#include "Player.h"

#include <iostream>
#include <cassert>

unsigned char operator&(unsigned char options, Printer::Option option)
{
  return options & static_cast<unsigned char>(option);
}

Printer &operator<<(Printer &printer, const std::string &string)
{
  printer.m_out << string;
  return printer;
}

Printer &operator<<(Printer &printer, const char ch)
{
  printer.m_out << ch;
  return printer;
}

Printer::Printer(std::ostream &out, unsigned char options) : m_out{out}, m_options{options} {}

Printer &Printer::player(const Player &player)
{
  for (auto &card : player.deck())
    this->card(card) << ' ';

  return *this;
}

Printer &Printer::paintString(const Color color, const std::string &input)
{
  if (m_options & Option::SuppressColor)
    m_out << input;
  else
    m_out << "\033[" << static_cast<int>(color) << "m" << input << "\033[0m";

  return *this;
}

Printer &Printer::win(const std::string &text)
{
  return paintString(Color::Green, text);
}

Printer &Printer::lose(const std::string &text)
{
  return paintString(Color::Red, text);
}

Printer &Printer::tie(const std::string &text)
{
  m_out << text;
  return *this;
}

Printer &Printer::ask(const std::string &text)
{
  return paintString(Color::Cyan, text);
}

Printer &Printer::newLine()
{
  m_out << '\n';
  return *this;
}

Printer &Printer::game(const Player &player, const Player &dealer)
{
  std::cout << "DEALER\t";
  std::cout << "Score: " << dealer.score() << "\t";
  std::cout << "Deck: ";
  this->player(dealer);
  std::cout << '\n';

  std::cout << "YOU\t";
  std::cout << "Score: " << player.score() << "\t";
  std::cout << "Deck: ";
  this->player(player);
  std::cout << "\n\n";

  return *this;
}

Printer::Color Printer::pickCardColor(const Card &card)
{
  switch (card.suit())
  {
  case Card::Suit::Club:
  case Card::Suit::Spade:
    return Color::Black;

  case Card::Suit::Diamond:
  case Card::Suit::Heart:
    return Color::Red;
  default:
    assert(false && "should never happen");
  }
}

Printer &Printer::card(const Card &card)
{
  if (m_options & Option::UnicodeCards)
  {
    const std::string icon{
        m_cardIcons[static_cast<int>(card.suit())]
                   [static_cast<int>(card.rank())]};
    return paintString(pickCardColor(card), icon);
  }

  m_out << card;
  return *this;
}