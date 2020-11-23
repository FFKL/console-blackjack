#include "constants.h"
#include "Player.h"
#include "Deck.h"

#include <iostream>

bool Player::isBust() const
{
  return m_score > Constants::MaxScore;
}

void Player::drawCard(Deck &deck)
{
  const Card &card = deck.dealCard();
  m_score += card.value();
  m_aces += card.isAce();
  m_deck.push_back(card);
}

int Player::score() const
{
  return m_score;
}

void Player::checkAces()
{
  while (m_aces && m_score > Constants::MaxScore)
  {
    --m_aces;
    m_score -= Constants::AceRank1Shift;
  }
}

const Player::player_deck_type &Player::deck() const
{
  return m_deck;
}
