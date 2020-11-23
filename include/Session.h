#ifndef SESSION_H
#define SESSION_H

#include "Game.h"
#include "Printer.h"

class Session
{
private:
  int m_win{0};
  int m_lose{0};
  int m_tie{0};
  Printer m_printer;

  bool playNextGame();
  void printResult(const Game::Result &result);
  void updateSessionResult(const Game::Result &result);

public:
  Session(Printer &m_printer);

  void play();
};

#endif