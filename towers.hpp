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

            if (!towerText.loadFromFile("monkey.png"))
            {
                    // error...
            }
            tower.setTexture(towerText);
        }
    
    sf::Sprite& getTower(){return tower;}

   

    void set(float x,float y)                                                                                  
        {
            tower.setPosition(sf::Vector2f(y, x));
        }
    
    private:
        sf::Clock timer;
        sf::Sprite tower;
        sf::Texture towerText;
        int i, turn;

};

#endif