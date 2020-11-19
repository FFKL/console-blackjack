#include "cards.h"
#include "Card.h"
#include "Deck.h"

#include <array>
#include <iostream>
#include <cassert>
#include <ctime>
#include <random>
#include <algorithm>

Deck::Deck()
  {
    index_type card{0};

    auto suits{static_cast<index_type>(Cards::CardSuit::Max)};
    auto ranks{static_cast<index_type>(Cards::CardRank::Max)};

    for (index_type suit{0}; suit < suits; ++suit)
    {
      for (index_type rank{0}; rank < ranks; ++rank)
      {
        m_deck[card] = {static_cast<Cards::CardRank>(rank), static_cast<Cards::CardSuit>(suit)};
        ++card;
      }
    }
  }

  void Deck::print() const
  {
    for (const auto &card : m_deck)
      std::cout << card << ' ';

    std::cout << '\n';
  }

  void Deck::shuffle()
  {
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cursor = 0;
  }

  const Card &Deck::dealCard()
  {
    assert(m_cursor < m_deck.size());

    return m_deck[m_cursor++];
  }