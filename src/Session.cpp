#include "Game.h"
#include "console.h"
#include "Session.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>

Session::Session(Printer &printer) : m_printer{printer} {}

void Session::printResult(const Game::Result &result)
{
  switch (result)
  {
  case Game::Result::player_win:
    m_printer.win("You win!");
    break;
  case Game::Result::dealer_win:
    m_printer.lose("You lose!");
    break;
  case Game::Result::tie:
    m_printer.tie("Tie!");
    break;
  }
  m_printer << '\n';
}

bool Session::playNextGame()
{
  m_printer.newLine();
  char answer{};
  do
  {
    m_printer.ask("Do you want to play the next game?(y/n) ");
    std::cin >> answer;
    Console::preventInvalidInput();
  } while (answer != 'y' && answer != 'n');
  m_printer.newLine();

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
    Game game{player, dealer, deck, m_printer};

    Game::Result result = game.play();
    printResult(result);
    updateSessionResult(result);
    m_printer.win("Win: " + std::to_string(m_win) + ". ");
    m_printer.lose("Lose: " + std::to_string(m_lose) + ". ");
    m_printer.tie("Tie: " + std::to_string(m_tie) + '\n');
  } while (playNextGame());
}