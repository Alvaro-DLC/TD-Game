#ifndef PLAYER.HPP
#define PLAYER.HPP
// include libraries
#include <iostream>
using namespace std;


class Player
{
public:
  //Constructor
  Player();

  //Setters
  void setCurrency(int currency);
  void setHealth(int health);

  //Getters
  int getHealth()const { return health; }
  int getCurrency()const { return currency; }

  //Currency
  void addCurrency(int currency);
  void useCurrency(int currency);

  //Health
  void heal(int health);

private:
  int currency, health;
};

#endif