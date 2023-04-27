#ifndef MAINCHAR_HPP_INCLUDED
#define MAINCHAR_HPP_INCLUDED

#include <background.hpp>
#include <iostream>
#include <string>

class MainPlayer
{
    public:
        MainPlayer(){
            i =0;

            if (!playerText[0].loadFromFile("music.png"))
            {
                    // error...
            }
            if (!playerText[1].loadFromFile("music2.png"))
            {
                    // error...
            }
            player.setTexture(playerText[0]);
        }
        sf::Sprite& getPlayer(){return player;}
        void walk()
        {
            player.move(sf::Vector2f(4.f, 2.f));
            player.setTexture(playerText[(++i)%2]);
            if(i == 120)
            {
                i = 0;
                reset();
            }

        }
        void reset()
        {
            player.setPosition(sf::Vector2f(0.f, 0.f));
        }

    private:
        sf::Sprite player;
        sf::Texture playerText[2];
        int i;
};

#endif // MAINCHAR_HPP_INCLUDED
