#include "constants.h"
#include "cards.h"
#include "Card.h"
#include "Deck.h"

#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>

namespace Cards
{
  namespace Random
  {
    std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
  } // namespace Random

  char pickRankCode(const CardRank &rank)
  {
    if (rank >= CardRank::Rank2 && rank <= CardRank::Rank9)
    {
      return static_cast<int>(rank) + Constants::ZERO_ASCII_CODE + Constants::CARD_RANK_SHIFT;
    }

    switch (rank)
    {
    case CardRank::Rank10:
      return 'T';
    case CardRank::Jack:
      return 'J';
    case CardRank::Queen:
      return 'Q';
    case CardRank::King:
      return 'K';
    case CardRank::Ace:
      return 'A';
    default:
      return '?';
    }
  }

  char pickSuitCode(const CardSuit &suit)
  {
    switch (suit)
    {
    case CardSuit::Club:
      return 'C';
    case CardSuit::Diamond:
      return 'D';
    case CardSuit::Heart:
      return 'H';
    case CardSuit::Spade:
      return 'S';
    default:
      return '?';
    }
  }
} // namespace Cards
