#include "Card.h"
#include "cards.h"

#include <iostream>
#include <cassert>

Card::Card() = default;

Card::Card(Cards::CardRank rank, Cards::CardSuit suit) : m_rank{rank}, m_suit{suit}
{
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
  switch (card.m_rank)
  {
  case Cards::CardRank::Rank2:
    return out << '2';
  case Cards::CardRank::Rank3:
    return out << '3';
  case Cards::CardRank::Rank4:
    return out << '4';
  case Cards::CardRank::Rank5:
    return out << '5';
  case Cards::CardRank::Rank6:
    return out << '6';
  case Cards::CardRank::Rank7:
    return out << '7';
  case Cards::CardRank::Rank8:
    return out << '8';
  case Cards::CardRank::Rank9:
    return out << '9';
  case Cards::CardRank::Rank10:
    return out << 'T';
  case Cards::CardRank::Jack:
    return out << 'J';
  case Cards::CardRank::Queen:
    return out << 'Q';
  case Cards::CardRank::King:
    return out << 'K';
  case Cards::CardRank::Ace:
    return out << 'A';
  default:
    return out << '?';
  }

  switch (card.m_suit)
  {
  case Cards::CardSuit::Club:
    return out << 'C';
  case Cards::CardSuit::Diamond:
    return out << 'D';
  case Cards::CardSuit::Heart:
    return out << 'H';
  case Cards::CardSuit::Spade:
    return out << 'S';
  default:
    return out << '?';
  }
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