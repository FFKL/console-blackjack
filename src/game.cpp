#include "game.h"
#include "cards.h"
#include "constants.h"
#include "console.h"
#include "Player.h"
#include "Deck.h"

#include <vector>
#include <iostream>

namespace Game
{
  bool playerWantsHit()
  {
    char answer{};
    do
    {
      std::cout << Console::cyan("Hit or stand? (h/s): ");
      std::cin >> answer;
      Console::preventInvalidInput();
    } while (answer != 'h' && answer != 's');
    std::cout << '\n';

    return answer == 'h';
  }

  void printGameState(Player &dealer, Player &player)
  {
    std::cout << "DEALER\t";
    std::cout << "Score: " << dealer.score() << "\t";
    std::cout << "Deck: ";
    printDeck(dealer);
    std::cout << '\n';

    std::cout << "YOU\t";
    std::cout << "Score: " << player.score() << "\t";
    std::cout << "Deck: ";
    printDeck(dealer);
    std::cout << "\n\n";
  }

  

  void turn(Player &actor, Player &dealer, Player &player, Deck &deck)
  {
    actor.drawCard(deck);
    actor.checkAces();
    printGameState(dealer, player);
  }

  bool dealerWantsHit(Player &dealer)
  {
    return dealer.score() < Constants::MIN_DEALER_SCORE;
  }

  BlackjackResult determineTheWinner(const Player &dealer, const Player &player)
  {
    if (player.score() == dealer.score())
      return BlackjackResult::tie;
    if (player.score() > dealer.score())
      return BlackjackResult::player_win;

    return BlackjackResult::dealer_win;
  }

  BlackjackResult playBlackjack(Deck &deck)
  {
    Player dealer;
    dealer.drawCard(deck);

    Player player;
    player.drawCard(deck);

    do
    {
      turn(player, dealer, player, deck);
      if (player.score() == Constants::MAX_SCORE)
        return BlackjackResult::player_win;
      if (player.score() > Constants::MAX_SCORE)
        return BlackjackResult::dealer_win;
    } while (playerWantsHit());

    do
    {
      turn(dealer, dealer, player, deck);
      if (dealer.score() == Constants::MAX_SCORE)
        return BlackjackResult::dealer_win;
      if (dealer.score() > Constants::MAX_SCORE)
        return BlackjackResult::player_win;
    } while (dealerWantsHit(dealer));

    return determineTheWinner(dealer, player);
  }
} // namespace Game