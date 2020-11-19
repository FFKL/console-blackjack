#include "constants.h"
#include "Player.h"
#include "Deck.h"

bool Player::isBust() const
{
  return m_score > Constants::MAX_SCORE;
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
  while (m_aces && m_score > Constants::MAX_SCORE)
  {
    --m_aces;
    m_score -= Constants::ACE_RANK_1_SHIFT;
  }
}