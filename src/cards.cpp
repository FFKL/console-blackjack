#include "constants.h"
#include "cards.h"

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

  deck_type createDeck()
  {
    deck_type deck{};

    auto maxSuits{static_cast<int>(CardSuit::Max)};
    auto maxRanks{static_cast<int>(CardRank::Max)};

    index_type card{0};
    for (int suit{0}; suit < maxSuits; ++suit)
    {
      for (int rank{0}; rank < maxRanks; ++rank)
      {
        deck[card].rank = static_cast<CardRank>(rank);
        deck[card].suit = static_cast<CardSuit>(suit);
        ++card;
      }
    }

    return deck;
  }

  void printCard(const Card &card)
  {
    std::cout << pickRankCode(card.rank) << pickSuitCode(card.suit);
  }

  void printDeck(const deck_type &deck)
  {
    for (const auto &card : deck)
    {
      printCard(card);
      std::cout << ' ';
    }

    std::cout << '\n';
  }

  void shuffleDeck(deck_type &deck)
  {
    std::shuffle(deck.begin(), deck.end(), Random::mersenne);
  }

  int getCardValue(const Card &card)
  {
    if (card.rank <= CardRank::Rank10)
    {
      return static_cast<int>(card.rank) + Constants::CARD_RANK_SHIFT;
    }

    switch (card.rank)
    {
    case CardRank::Jack:
    case CardRank::Queen:
    case CardRank::King:
      return 10;
    case CardRank::Ace:
      return 11;
    default:
      return 0;
    }
  }
} // namespace Cards
