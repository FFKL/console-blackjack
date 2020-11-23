#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
public:
  enum class Suit
  {
    Club,
    Diamond,
    Heart,
    Spade,

    Max
  };

  enum class Rank
  {
    Rank2,
    Rank3,
    Rank4,
    Rank5,
    Rank6,
    Rank7,
    Rank8,
    Rank9,
    Rank10,
    Jack,
    Queen,
    King,
    Ace,

    Max
  };

private:
  Rank m_rank{};
  Suit m_suit{};

public:
  Card();
  Card(Rank rank, Suit suit);

  int value() const;
  Rank rank() const;
  Suit suit() const;
  bool isAce() const;

  friend std::ostream &operator<<(std::ostream &out, const Card &card);
};

#endif
