#include "game.h"
#include "cards.h"
#include "constants.h"
#include "console.h"

#include <vector>
#include <iostream>

namespace Game
{
  bool isAce(Cards::Card &card)
  {
    return Cards::CardRank::Ace == card.rank;
  }

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

  int calcScore(std::vector<Cards::Card> &cards)
  {
    int result{0};
    for (const auto &card : cards)
      result += Cards::getCardValue(card);

    return result;
  }

  void printPlayerCards(Player &player)
  {
    for (auto &card : player.deck)
    {
      std::cout << ' ';
      Cards::printCard(card);
    }
  }

  void printGameState(Player &dealer, Player &player)
  {
    std::cout << "DEALER\t";
    std::cout << "Score: " << dealer.score << "\t";
    std::cout << "Deck: ";
    printPlayerCards(dealer);
    std::cout << '\n';

    std::cout << "YOU\t";
    std::cout << "Score: " << player.score << "\t";
    std::cout << "Deck: ";
    printPlayerCards(player);
    std::cout << "\n\n";
  }

  Cards::Card nextCard(GameDeck &gameDeck)
  {
    return gameDeck.deck.at(gameDeck.cursor++);
  }

  void hit(Player &player, GameDeck &deck)
  {
    Cards::Card card = nextCard(deck);
    player.score += Cards::getCardValue(card);
    player.aces += isAce(card);
    player.deck.push_back(card);
  }

  void checkAces(Player &player)
  {
    while (player.aces && player.score > Constants::MAX_SCORE)
    {
      --player.aces;
      player.score -= Constants::ACE_RANK_1_SHIFT;
    }
  }

  Player createPlayer()
  {
    return {0, 0, {}};
  }

  void turn(Player &actor, Player &dealer, Player &player, GameDeck &deck)
  {
    hit(actor, deck);
    checkAces(actor);
    printGameState(dealer, player);
  }

  bool dealerWantsHit(Player &dealer)
  {
    return dealer.score < Constants::MIN_DEALER_SCORE;
  }

  BlackjackResult determineTheWinner(const Player &dealer, const Player &player)
  {
    if (player.score == dealer.score)
      return BlackjackResult::tie;
    if (player.score > dealer.score)
      return BlackjackResult::player_win;

    return BlackjackResult::dealer_win;
  }

  BlackjackResult playBlackjack(Cards::deck_type &deck)
  {
    GameDeck gameDeck{deck, 0};
    Player dealer{createPlayer()};
    hit(dealer, gameDeck);

    Player player{createPlayer()};
    hit(player, gameDeck);

    do
    {
      turn(player, dealer, player, gameDeck);
      if (player.score == Constants::MAX_SCORE)
        return BlackjackResult::player_win;
      if (player.score > Constants::MAX_SCORE)
        return BlackjackResult::dealer_win;
    } while (playerWantsHit());

    do
    {
      turn(dealer, dealer, player, gameDeck);
      if (dealer.score == Constants::MAX_SCORE)
        return BlackjackResult::dealer_win;
      if (dealer.score > Constants::MAX_SCORE)
        return BlackjackResult::player_win;
    } while (dealerWantsHit(dealer));

    return determineTheWinner(dealer, player);
  }
} // namespace Game