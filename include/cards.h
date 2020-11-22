#ifndef CARDS_DECK_H
#define CARDS_DECK_H

namespace Cards
{
  enum class CardSuit
  {
    Club,
    Diamond,
    Heart,
    Spade,

    Max
  };

  enum class CardRank
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
} // namespace Cards

#endif