#include "Card.h"
#include "constants.h"
#include "cards.h"

#include <sstream>
#include <iostream>
#include <cassert>

char pickRankCode(const Cards::CardRank &rank)
{
  if (rank >= Cards::CardRank::Rank2 && rank <= Cards::CardRank::Rank9)
  {
    return static_cast<int>(rank) + Constants::ZERO_ASCII_CODE + Constants::CARD_RANK_SHIFT;
  }

  switch (rank)
  {
  case Cards::CardRank::Rank10:
    return 'T';
  case Cards::CardRank::Jack:
    return 'J';
  case Cards::CardRank::Queen:
    return 'Q';
  case Cards::CardRank::King:
    return 'K';
  case Cards::CardRank::Ace:
    return 'A';
  default:
    return '?';
  }
}

char pickSuitCode(const Cards::CardSuit &suit)
{
  switch (suit)
  {
  case Cards::CardSuit::Club:
    return 'C';
  case Cards::CardSuit::Diamond:
    return 'D';
  case Cards::CardSuit::Heart:
    return 'H';
  case Cards::CardSuit::Spade:
    return 'S';
  default:
    return '?';
  }
}

Card::Card() = default;

Card::Card(Cards::CardRank rank, Cards::CardSuit suit) : m_rank{rank}, m_suit{suit}
{
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
  return out << pickRankCode(card.m_rank) << pickSuitCode(card.m_suit);
}

int Card::value() const
{
  if (m_rank <= Cards::CardRank::Rank10)
  {
    return (static_cast<int>(m_rank) + 2);
  }

  switch (m_rank)
  {
  case Cards::CardRank::Jack:
  case Cards::CardRank::Queen:
  case Cards::CardRank::King:
    return 10;
  case Cards::CardRank::Ace:
    return 11;
  default:
    assert(false && "should never happen");
  }
}

bool Card::isAce() const
{
  return Cards::CardRank::Ace == m_rank;
}

Cards::CardRank Card::rank() const
{
  return m_rank;
}

Cards::CardSuit Card::suit() const
{
  return m_suit;
}