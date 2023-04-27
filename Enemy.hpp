#ifndef ENEMY.HPP
#define ENEMY.HPP
#include "Player.hpp"
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


class Enemy : public Player
{
    public: 
      Enemy();
      Enemy(int health, int damage, string type);
      int getHealth() const {int health;}
      int getDamage() const {int damage;}
      string getType() const {string type;}

      void setHealth(int health)
      void setDamage(int damage)
      void setType(string type)



    private:
      int health, damage;
      string type; 

};

#endif