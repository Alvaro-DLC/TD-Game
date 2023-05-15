#ifndef BUY_HPP_INCLUDED
#define BUY_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Buy
{
    public:
        Buy()
        {
            sf::RectangleShape buyBtn(sf::Vector2f(32.f, 32.f));
            buyBtn.setFillColor(sf::Color(255,255,255));
           //if
            if(!img3.loadFromFile("buyBtn.png"))
            {
                std::cout << "Error loading buyBtn.png\n";

            }

            // playBtn.setTexture(&img3);
            // playBtn.setPosition(50.f, 10.f);


        }
        bool pressedBuy(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 10.f && y <= 110.f) return true; else return false;}

          void set(float x,float y)                                                                                  
        {
            buyBtn.setPosition(sf::Vector2f(y, x));
        }
    
        sf::RectangleShape& getBuyBtn() {return buyBtn;}


    private:
        sf::RectangleShape buyBtn;
        sf::Texture img3;
};


#endif // BUY_HPP_INCLUDED
