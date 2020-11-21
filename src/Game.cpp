#include "Game.h"
#include "cards.h"
#include "constants.h"
#include "console.h"
#include "Player.h"
#include "Deck.h"

#include <vector>
#include <iostream>

Game::Game(const Player &player, const Player &dealer, const Deck &deck)
    : m_player{player}, m_dealer{dealer}, m_deck{deck} {}

bool Game::playerWantsHit()
{
  char answer{};
  do
  {
    std::cout << Console::ask("Hit or stand? (h/s): ");
    std::cin >> answer;
    Console::preventInvalidInput();
  } while (answer != 'h' && answer != 's');
  std::cout << '\n';

  return answer == 'h';
}

void Game::printGameState()
{
  std::cout << "DEALER\t";
  std::cout << "Score: " << m_dealer.score() << "\t";
  std::cout << "Deck: ";
  printDeck(m_dealer);
  std::cout << '\n';

  std::cout << "YOU\t";
  std::cout << "Score: " << m_player.score() << "\t";
  std::cout << "Deck: ";
  printDeck(m_player);
  std::cout << "\n\n";
}

void Game::turn(Player &actor)
{
  actor.drawCard(m_deck);
  actor.checkAces();
  printGameState();
}

bool Game::dealerWantsHit()
{
  return m_dealer.score() < Constants::MIN_DEALER_SCORE;
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
    if (m_player.score() == Constants::MAX_SCORE)
      return Game::Result::player_win;
    if (m_player.score() > Constants::MAX_SCORE)
      return Game::Result::dealer_win;
  } while (playerWantsHit());

  do
  {
    turn(m_dealer);
    if (m_dealer.score() == Constants::MAX_SCORE)
      return Game::Result::dealer_win;
    if (m_dealer.score() > Constants::MAX_SCORE)
      return Game::Result::player_win;
  } while (dealerWantsHit());

  return determineTheWinner();
}