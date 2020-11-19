#include "game.h"
#include "console.h"
#include "cards.h"
#include "Session.h"
#include "Deck.h"

#include <iostream>

void Session::printResult(const Game::BlackjackResult &result)
{
  switch (result)
  {
  case Game::BlackjackResult::player_win:
    std::cout << Console::green("You win!");
    break;
  case Game::BlackjackResult::dealer_win:
    std::cout << Console::red("You lose!");
    break;
  case Game::BlackjackResult::tie:
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
    std::cout << Console::cyan("Do you want to play the next game?(y/n) ");
    std::cin >> answer;
    Console::preventInvalidInput();
  } while (answer != 'y' && answer != 'n');
  std::cout << '\n';

  return answer == 'y';
}

void Session::updateSessionResult(const Game::BlackjackResult &result)
{
  switch (result)
  {
  case Game::BlackjackResult::player_win:
    ++m_win;
    break;
  case Game::BlackjackResult::dealer_win:
    ++m_lose;
    break;
  case Game::BlackjackResult::tie:
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

    Game::BlackjackResult result = Game::playBlackjack(deck);
    printResult(result);
    updateSessionResult(result);
    std::cout << Console::green("Win: " + std::to_string(m_win) + ". ");
    std::cout << Console::red("Lose: " + std::to_string(m_lose) + ". ");
    std::cout << "Tie: " << m_tie << '\n';
  } while (playNextGame());
}