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
            // sf::RectangleShape buyBtn(sf::Vector2f(32.f, 32.f));
            // buyBtn.setFillColor(sf::Color(255,255,255));
           //if
            if(!buyText.loadFromFile("buyBtn.png"))
            {
                std::cout << "Error loading buyBtn.png\n";

            }

            buyBtn.setTexture(buyText);
           


        }
        bool pressedBuy(float x, float y){
            // if(x > 390.f && x <= 422.f && y >= 110.f && y <= 155.f) return true; else return false;}
             if(x > 200.f && x <= 960.f && y >= 22.f && y <= 400.f) return true; else return false;}

          void set(float x,float y)                                                                                  
        {
            buyBtn.setPosition(sf::Vector2f(y, x));
        }
    
        // sf::RectangleShape& getBuyBtn() {return buyBtn;}
        sf::Sprite& getBuyBtn(){return buyBtn;}

    private:
        // sf::RectangleShape buyBtn;
        sf::Sprite buyBtn;
        sf::Texture buyText;
};


#endif // BUY_HPP_INCLUDED
