#include "console.h"
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

  auto suits{static_cast<index_type>(Card::Suit::Max)};
  auto ranks{static_cast<index_type>(Card::Rank::Max)};

  for (index_type suit{0}; suit < suits; ++suit)
  {
    for (index_type rank{0}; rank < ranks; ++rank)
    {
      m_deck[card] = {static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)};
      ++card;
    }
  }
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

std::ostream &operator<<(std::ostream &out, const Deck &deck)
{

  for (const auto &card : deck.m_deck)
    out << Console::card(card) << ' ';

  return out << '\n';
}
