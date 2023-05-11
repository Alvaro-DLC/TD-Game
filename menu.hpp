#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MainMenu
{
    public:
        MainMenu()
        {
            playBtn = sf::RectangleShape(sf::Vector2f(200.f, 100.f));
            playBtn.setFillColor(sf::Color(255,255,255));
           //if
            if(!img1.loadFromFile("playBtn.png"))
            {
                std::cout << "Error loading playBtn.png\n";

            }
             if(!(img2.loadFromFile("instructionsBtn.png")))
            {
                std::cout << "Error loading instructionsBtn.png\n";
            }

            playBtn.setTexture(&img1);
            playBtn.setPosition(50.f, 10.f);
            instructionsBtn = sf::RectangleShape(sf::Vector2f(200.f, 100.f));
            instructionsBtn.setFillColor(sf::Color(255, 255,255));
            instructionsBtn.setPosition(50.f, 120.f);
            instructionsBtn.setTexture(&img2);
        }
        bool pressedPlay(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 10.f && y <= 110.f) return true; else return false;}
        bool pressedInstructions(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 120.f && y <= 220.f) return true; else return false;}
        sf::RectangleShape& getPlayBtn() {return playBtn;}
        sf::RectangleShape& getInstructionsBtn() {return instructionsBtn;}

    private:
        sf::RectangleShape playBtn;
        sf::RectangleShape instructionsBtn;
        sf::Texture img1;
        sf::Texture img2;
};


#endif // MENU_HPP_INCLUDED
