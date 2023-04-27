#include "Player.hpp"
#include <cassert>

Player::Player()
{
  currency = 500;
  health = 100;
}

void Player::setCurrency(int currency){
  this->currency = currency;
}

