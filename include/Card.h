#ifndef CARD_H
#define CARD_H

#include "cards.h"

#include <iostream>

class Card
{
private:
  Cards::CardRank m_rank{};
  Cards::CardSuit m_suit{};

public:
  Card();
  Card(Cards::CardRank rank, Cards::CardSuit suit);

  void print() const;
  int value() const;
  Cards::CardRank rank() const;
  Cards::CardSuit suit() const;
  bool isAce() const;

  friend std::ostream &operator<<(std::ostream &out, const Card &card);
};

#endif
