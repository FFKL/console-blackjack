#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Printer.h"

#include <vector>

class Game
{
public:
  enum class Result
  {
    player_win,
    dealer_win,
    tie
  };

private:
  Player m_player;
  Player m_dealer;
  Deck m_deck;
  Printer m_printer;

  bool playerWantsHit();
  bool dealerWantsHit();
  void printGameState();
  void turn(Player &actor);
  Result determineTheWinner();

public:
  Game(const Player &player, const Player &dealer, const Deck &deck, const Printer &printer);

  Result play();
};

#endif