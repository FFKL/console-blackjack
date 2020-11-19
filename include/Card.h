#ifndef CARD_H
#define CARD_H

#include "cards.h"

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
  bool isAce() const;

  friend std::ostream &operator<<(std::ostream &out, const Card &card);
};

#endif
