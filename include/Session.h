#ifndef SESSION_H
#define SESSION_H

#include "Game.h"

class Session
{
private:
  int m_win{0};
  int m_lose{0};
  int m_tie{0};

  bool playNextGame();
  void printResult(const Game::Result &result);
  void updateSessionResult(const Game::Result &result);

public:
  void play();
};

#endif