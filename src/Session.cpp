#include "Game.h"
#include "console.h"
#include "cards.h"
#include "Session.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>

void Session::printResult(const Game::Result &result)
{
  switch (result)
  {
  case Game::Result::player_win:
    std::cout << Console::win("You win!");
    break;
  case Game::Result::dealer_win:
    std::cout << Console::loose("You lose!");
    break;
  case Game::Result::tie:
    std::cout << "Tie!";
    break;
  }
  std::cout << '\n';
}

bool Session::playNextGame()
{
  std::cout << '\n';
  char answer{};
  do
  {
    std::cout << Console::ask("Do you want to play the next game?(y/n) ");
    std::cin >> answer;
    Console::preventInvalidInput();
  } while (answer != 'y' && answer != 'n');
  std::cout << '\n';

  return answer == 'y';
}

void Session::updateSessionResult(const Game::Result &result)
{
  switch (result)
  {
  case Game::Result::player_win:
    ++m_win;
    break;
  case Game::Result::dealer_win:
    ++m_lose;
    break;
  case Game::Result::tie:
    ++m_tie;
    break;
  }
}

void Session::play()
{
  do
  {
    Deck deck;
    deck.shuffle();

    Player player;
    Player dealer;
    Game game{player, dealer, deck};

    Game::Result result = game.play();
    printResult(result);
    updateSessionResult(result);
    std::cout << Console::win("Win: " + std::to_string(m_win) + ". ");
    std::cout << Console::loose("Lose: " + std::to_string(m_lose) + ". ");
    std::cout << "Tie: " << m_tie << '\n';
  } while (playNextGame());
}