#include "Game.h"
#include "constants.h"
#include "console.h"
#include "Player.h"
#include "Deck.h"
#include "Printer.h"

#include <vector>
#include <iostream>

Game::Game(const Player &player, const Player &dealer, const Deck &deck, const Printer &printer)
    : m_player{player}, m_dealer{dealer}, m_deck{deck}, m_printer{printer} {}

bool Game::playerWantsHit()
{
  char answer{};
  do
  {
    m_printer.ask("Hit or stand? (h/s): ");
    std::cin >> answer;
    Console::preventInvalidInput();
  } while (answer != 'h' && answer != 's');
  m_printer.newLine();

  return answer == 'h';
}

void Game::turn(Player &actor)
{
  actor.drawCard(m_deck);
  actor.checkAces();
  m_printer.game(m_player, m_dealer);
}

bool Game::dealerWantsHit()
{
  return m_dealer.score() < Constants::MinDealerScore;
}

Game::Result Game::determineTheWinner()
{
  if (m_player.score() == m_dealer.score())
    return Game::Result::tie;
  if (m_player.score() > m_dealer.score())
    return Game::Result::player_win;

  return Game::Result::dealer_win;
}

Game::Result Game::play()
{
  m_dealer.drawCard(m_deck);
  m_player.drawCard(m_deck);

  do
  {
    turn(m_player);
    if (m_player.score() == Constants::MaxScore)
      return Game::Result::player_win;
    if (m_player.score() > Constants::MaxScore)
      return Game::Result::dealer_win;
  } while (playerWantsHit());

  do
  {
    turn(m_dealer);
    if (m_dealer.score() == Constants::MaxScore)
      return Game::Result::dealer_win;
    if (m_dealer.score() > Constants::MaxScore)
      return Game::Result::player_win;
  } while (dealerWantsHit());

  return determineTheWinner();
}