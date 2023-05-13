#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MainMenu
{
    public:
        MainMenu()
        {
            buyBtn = sf::RectangleShape(sf::Vector2f(200.f, 100.f));
            buyBtn.setFillColor(sf::Color(255,255,255));
           //if
            if(!img1.loadFromFile("buy.png"))
            {
                std::cout << "Error loading buy.png\n";

            }
             if(!(img2.loadFromFile("instructionsBtn.png")))//add map
            {
                std::cout << "Error loading instructionsBtn.png\n";
            }

            buyBtn.setTexture(&img1);
            buyBtn.setPosition(50.f, 10.f);
           
        }
        bool pressedBuy(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 10.f && y <= 110.f) return true; else return false;}
        sf::RectangleShape& getBuyBtn() {return buyBtn;} sf::RectangleShape& getInstructionsBtn() {return instructionsBtn;}

    private:
        sf::RectangleShape buyBtn;
        sf::Texture img1;
        sf::Texture img2;
};


#endif // MENU_HPP_INCLUDED
