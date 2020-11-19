#ifndef DECK_H
#define DECK_H

#include "cards.h"
#include "Card.h"

#include <array>

class Deck
{
public:
  using deck_type = std::array<Card, 52>;
  using index_type = deck_type::size_type;

public: // TODO: make it private
  deck_type m_deck{};
  index_type m_cursor{0};

public:
  Deck();

  void print() const;
  void shuffle();
  const Card &dealCard();
};

#endif