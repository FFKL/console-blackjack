#!/bin/bash
g++ \
  -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror \
  -std=c++17 -o blackjack \
  src/main.cpp src/game.cpp src/session.cpp src/console.cpp src/cards.cpp
