#ifndef TOWER.HPP
#define TOWER.HPP
// include libraries
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


class Tower public: Player 
    public: 
      Tower();
      Tower(int health, int damage, string type);

      string getType()const{return name;}
      int getLevel()const{return quantity;}
      int getDamage()const{return damage;}

      void setType(string type);
      void setLevel(int level);
      void setDamage(int damage);

      void DisplayStats();

    


    private:
      int damage,level;
      string type; 

 
};

#endif