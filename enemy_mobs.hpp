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
        turn = 0
        if(timer.getElapsedTime().asMilliseconds() >= 100)
        {
            enemy.move(sf::Vector2f(5.f, 0.f));
            timer.restart();
        }
    }

    void reset()
        {
            enemy.setPosition(sf::Vector2f(0.f, 0.f));
        }
    
    private:
        sf::Clock timer;
        sf::Sprite enemy;
        sf::Texture enemyText[2];
        int i, turn;

};

#endif