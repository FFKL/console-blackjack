#include "cards.h"

#include <vector>

#ifndef GAME_H
#define GAME_H

namespace Game
{
  using player_deck_type = std::vector<Cards::Card>;

  struct Player
  {
    int aces{};
    int score{};
    player_deck_type deck{};
  };

  struct GameDeck
  {
    Cards::deck_type deck{};
    Cards::index_type cursor{};
  };

  enum class BlackjackResult
  {
    player_win,
    dealer_win,
    tie
  };

  BlackjackResult playBlackjack(Cards::deck_type &deck);
} // namespace Game

#endif