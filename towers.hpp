#ifndef TOWERS_HPP_INCLUDED
#define TOWERS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Towers
{
    public:
    Towers()
    {
            i =0;

            if (!towerText[0].loadFromFile("monkey.png"))
            {
                    // error...
            }
            if (!towerText[1].loadFromFile("orange_enemy.png"))
            {
                    // error...
            }
            enemy.setTexture(towerText[0]);
        }
    
    sf::Sprite& getTower(){return tower;}

    // void move()
    // {
    //     turn = 0
    //     if(timer.getElapsedTime().asMilliseconds() >= 100)
    //     {
    //         enemy.move(sf::Vector2f(5.f, 0.f));
    //         timer.restart();
    //     }
    // }

    void reset()
        {
            tower.setPosition(sf::Vector2f(0.f, 0.f));
        }
    
    private:
        sf::Clock timer;
        sf::Sprite enemy;
        sf::Texture towerText[2];
        int i, turn;

};

#endif