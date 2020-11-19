#ifndef GAME_H
#define GAME_H

#include "cards.h"
#include "Deck.h"

#include <vector>

namespace Game
{
  enum class BlackjackResult
  {
    player_win,
    dealer_win,
    tie
  };

  BlackjackResult playBlackjack(Deck &deck);
} // namespace Game

#endif