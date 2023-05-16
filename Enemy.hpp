#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Enemy
{
    public:
    // constructors
    Enemy(int color = 0)
    {

        if (!enemyText[0].loadFromFile("orange_enemy.png"))
        {
                // error...
        }
        if (!enemyText[1].loadFromFile("orange_enemy_down.png"))
        {
                // error...
        }
        if (!enemyText[2].loadFromFile("orange_enemy_left.png"))
        {
                // error...
        }
        if (!enemyText[3].loadFromFile("orange_enemy_up.png"))
        {
                // error...
        }
        enemy.setTexture(enemyText[color]);
        enemy.setPosition(sf::Vector2f(0.f, 50.f));

    }

    // Setters
    void setHealth(int health) {this->health = health;}
    void setMoving(bool moving) {this->moving = moving;}

    // Getters
    sf::Sprite& getEnemy(){return enemy;}
    int getHealth()const {return health;}
    int getTurn()const {return turn;}
    int getMoving()const {return moving;}

    // member functions
    void take_damage(int damage) {health -= damage;}
    void resetTurn() {turn = 0;}
    void reset() 
    {
        enemy.setPosition(sf::Vector2f(0.f, 50.f));
        enemy.setTexture(enemyText[0]);
    }
    void move()
    {
            if(turn > 150 && turn <= 240)
            {
                // <---rotate--->
                enemy.setTexture(enemyText[3]);
                // <------------>
                enemy.move(sf::Vector2f(0.f, -4.f));
                turn++;
            }
            else if(turn > 97 && turn <= 150)
            {
                // <---rotate--->
                enemy.setTexture(enemyText[0]);
                // <------------>
                enemy.move(sf::Vector2f(4.f, 0.f));
                turn++;
            }
            else if(turn > 75 && turn <= 97)
            {
                // <---rotate--->
                enemy.setTexture(enemyText[1]);
                // <------------>
                enemy.move(sf::Vector2f(0.f, 4.f));
                turn++;
            }
            else if(turn > 51 && turn <= 75)
            {
                // <---rotate--->
                enemy.setTexture(enemyText[2]);                
                // <------------>
                enemy.move(sf::Vector2f(-4.f, 0.f));
                turn++;
            }
            else if (turn > 29 && turn <= 51)
            {
                // <---rotate--->
                enemy.setTexture(enemyText[1]);         
                // <------------>
                enemy.move(sf::Vector2f(0.f, 4.f));
                turn++;
            }
            else
            {
                enemy.move(sf::Vector2f(4.f, 0.f));
                turn++;
            }
    }

    private:
        sf::Sprite enemy;
        sf::Texture enemyText[4];
        int turn = 0,health = 5, damage = 1;
        bool moving = false;

};

#endif