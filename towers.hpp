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
            tower.setTexture(towerText[0]);
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

    void set(float x,float y)                                                                                  
        {
            tower.setPosition(sf::Vector2f(y, x));
        }
    
    private:
        sf::Clock timer;
        sf::Sprite tower;
        sf::Texture towerText[2];
        int i, turn;

};

#endif