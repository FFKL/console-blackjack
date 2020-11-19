#ifndef SESSION_H
#define SESSION_H

#include "game.h"

class Session
{
private:
  int m_win{0};
  int m_lose{0};
  int m_tie{0};

  bool playNextGame();
  void printResult(const Game::BlackjackResult &result);
  void updateSessionResult(const Game::BlackjackResult &result);

public:
  void play();
};

#endif