#ifndef ENEMYMOBS_HPP_INCLUDED
#define ENEMYMOBS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class EnemyMobs
{
    public:
    EnemyMobs()
    {
        if (!enemyText[0].loadFromFile("blue_enemy.png"))
        {
                // error...
        }
        if (!enemyText[1].loadFromFile("orange_enemy.png"))
        {
                // error...
        }
        enemy.setTexture(enemyText[0]);
    }
    
    sf::Sprite& getEnemy(){return enemy;}
    
    void setMoving(bool moving) {this->moving = moving;}

    int getTurn()const {return turn;}
    int getMoving()const {return turn;}

    void resetTurn() {turn = 0;}
    void reset(float x,float y) {enemy.setPosition(sf::Vector2f(y, x));}

    void move()
    {
        if(timer.getElapsedTime().asMilliseconds() >= 100)
        {
            if(turn > 75)
            {
                enemy.move(sf::Vector2f(0.f, 4.f));
                turn++;
            }
            else if(turn > 50 && turn <= 75)
            {
                enemy.move(sf::Vector2f(-4.f, 0.f));
                turn++;
            }
            else if (turn > 30 && turn <= 50)
            {
                enemy.move(sf::Vector2f(0.f, 4.f));
                turn++;
            }
            else
            {
                enemy.move(sf::Vector2f(4.f, 0.f));
                turn++;
            }
            timer.restart();
        }
    }

    void set(float x,float y)                                                                                  
        {
            enemy.setPosition(sf::Vector2f(y, x));
        }
    
    private:
        sf::Clock timer;
        sf::Sprite enemy;
        sf::Texture enemyText[1];
        int turn = 0;
        bool moving = false;

};

#endif