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
            i =0;

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

    void move()
    {
        if(timer.getElapsedTime().asMilliseconds() >= 100)
        {
            if (turn > 40 && turn <= 120)
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

    void resetTurn()
    {
        turn = 0;
    }

    int getTurn()const {return turn;}

    void reset()
        {
            enemy.setPosition(sf::Vector2f(0.f, 0.f));
        }
    
    private:
        sf::Clock timer;
        sf::Sprite enemy;
        sf::Texture enemyText[2];
        int i, turn = 0;

};

#endif