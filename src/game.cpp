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

  void printPlayerCards(const Player &player)
  {
    for (auto &card : player.m_deck)
    {
      std::cout << ' ' << card;
    }
  }

  void printGameState(Player &dealer, Player &player)
  {
    std::cout << "DEALER\t";
    std::cout << "Score: " << dealer.m_score << "\t";
    std::cout << "Deck: ";
    printPlayerCards(dealer);
    std::cout << '\n';

    std::cout << "YOU\t";
    std::cout << "Score: " << player.m_score << "\t";
    std::cout << "Deck: ";
    printPlayerCards(player);
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
    return dealer.m_score < Constants::MIN_DEALER_SCORE;
  }

  BlackjackResult determineTheWinner(const Player &dealer, const Player &player)
  {
    if (player.m_score == dealer.m_score)
      return BlackjackResult::tie;
    if (player.m_score > dealer.m_score)
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
      if (player.m_score == Constants::MAX_SCORE)
        return BlackjackResult::player_win;
      if (player.m_score > Constants::MAX_SCORE)
        return BlackjackResult::dealer_win;
    } while (playerWantsHit());

    do
    {
      turn(dealer, dealer, player, deck);
      if (dealer.m_score == Constants::MAX_SCORE)
        return BlackjackResult::dealer_win;
      if (dealer.m_score > Constants::MAX_SCORE)
        return BlackjackResult::player_win;
    } while (dealerWantsHit(dealer));

    return determineTheWinner(dealer, player);
  }
} // namespace Game