#include "Card.h"
#include "constants.h"

#include <sstream>
#include <iostream>
#include <cassert>

char pickRankCode(const Card::Rank &rank)
{
  if (rank >= Card::Rank::Rank2 && rank <= Card::Rank::Rank9)
  {
    return static_cast<int>(rank) + Constants::ZERO_ASCII_CODE + Constants::CARD_RANK_SHIFT;
  }

  switch (rank)
  {
  case Card::Rank::Rank10:
    return 'T';
  case Card::Rank::Jack:
    return 'J';
  case Card::Rank::Queen:
    return 'Q';
  case Card::Rank::King:
    return 'K';
  case Card::Rank::Ace:
    return 'A';
  default:
    return '?';
  }
}

char pickSuitCode(const Card::Suit &suit)
{
  switch (suit)
  {
  case Card::Suit::Club:
    return 'C';
  case Card::Suit::Diamond:
    return 'D';
  case Card::Suit::Heart:
    return 'H';
  case Card::Suit::Spade:
    return 'S';
  default:
    return '?';
  }
}

Card::Card() = default;

Card::Card(Card::Rank rank, Card::Suit suit) : m_rank{rank}, m_suit{suit}
{
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
  return out << pickRankCode(card.m_rank) << pickSuitCode(card.m_suit);
}

int Card::value() const
{
  if (m_rank <= Card::Rank::Rank10)
  {
    return (static_cast<int>(m_rank) + 2);
  }

  switch (m_rank)
  {
  case Card::Rank::Jack:
  case Card::Rank::Queen:
  case Card::Rank::King:
    return 10;
  case Card::Rank::Ace:
    return 11;
  default:
    assert(false && "should never happen");
  }
}

bool Card::isAce() const
{
  return Card::Rank::Ace == m_rank;
}

Card::Rank Card::rank() const
{
  return m_rank;
}

Card::Suit Card::suit() const
{
  return m_suit;
}