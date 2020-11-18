#include <array>

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

  struct Card
  {
    CardRank rank{};
    CardSuit suit{};
  };

  using deck_type = std::array<Card, 52>;
  using index_type = deck_type::size_type;

  deck_type createDeck();
  void shuffleDeck(deck_type &deck);
  void printCard(const Card &card);
  int getCardValue(const Card &card);
} // namespace Cards

#endif