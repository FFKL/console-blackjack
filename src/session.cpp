#include "game.h"
#include "session.h"
#include "console.h"
#include "cards.h"
#include "Deck.h"

#include <iostream>

namespace Session
{
  struct Session
  {
    int win{};
    int lose{};
    int tie{};
  };

  void printResult(const Game::BlackjackResult &result)
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

  bool playNextGame()
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

  void updateSessionResult(Session &session, const Game::BlackjackResult &result)
  {
    switch (result)
    {
    case Game::BlackjackResult::player_win:
      ++session.win;
      break;
    case Game::BlackjackResult::dealer_win:
      ++session.lose;
      break;
    case Game::BlackjackResult::tie:
      ++session.tie;
      break;
    }
  }

  void play()
  {
    Session session{0, 0, 0};
    do
    {
      Deck deck;
      deck.shuffle();
      
      Game::BlackjackResult result = Game::playBlackjack(deck);
      printResult(result);
      updateSessionResult(session, result);
      std::cout << Console::green("Win: " + std::to_string(session.win) + ". ");
      std::cout << Console::red("Lose: " + std::to_string(session.lose) + ". ");
      std::cout << "Tie: " << session.tie << '\n';
    } while (playNextGame());
  }
} // namespace Session