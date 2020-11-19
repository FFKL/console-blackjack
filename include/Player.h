#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

#include <vector>

class Player
{
public:
  using player_deck_type = std::vector<Card>;

public: // TODO: make it private
  int m_aces{0};
  int m_score{0};
  player_deck_type m_deck{};

public:
  void drawCard(Deck &deck);
  int score() const;
  bool isBust() const;
  void checkAces();
};

#endif