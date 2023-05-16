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
            

           if(!(img2.loadFromFile("buyBtn.png")))
            {
                std::cout << "Error loading Btn.png\n";
            }

            // buyBtn.setTexture(&buyText);
            // buyBtn.setPosition(50.f, 120.f);
            
            sf::RectangleShape buyB(sf::Vector2f(200.f, 100.f));
            buyB.setPosition(50.f, 120.f);
            buyB.setTexture(&img2);
            

        }
        // bool pressedBuy(float x, float y){
        //     // if(x > 390.f && x <= 422.f && y >= 110.f && y <= 155.f) return true; else return false;}
        //      if(x > 200.f && x <= 960.f && y >= 22.f && y <= 400.f) return true; else return false;}
         bool pressedBuy(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 120.f && y <= 220.f) return true; else return false;}

          void set(float x,float y)                                                                                  
        {
            buyB.setPosition(sf::Vector2f(y, x));
        }
    
        sf::RectangleShape& getBuyB() {return buyB;}
        // sf::Sprite& getBuyBtn(){return buyBtn;}
        

    private:
        sf::RectangleShape buyB;
        // sf::Sprite buyBtn;
        sf::Texture img2;
};


#endif // BUY_HPP_INCLUDED
