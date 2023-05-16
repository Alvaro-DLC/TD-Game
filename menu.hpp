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

            if(!img3.loadFromFile("buyBtn.png"))
            {
                std::cout << "Error loading Btn.png\n";
            }

            playBtn.setTexture(&img1);
            playBtn.setPosition(50.f, 10.f);
            instructionsBtn = sf::RectangleShape(sf::Vector2f(200.f, 100.f));
            instructionsBtn.setFillColor(sf::Color(255, 255,255));
            instructionsBtn.setPosition(50.f, 120.f);
            instructionsBtn.setTexture(&img2);

            // new attamp
            buyBt = sf::RectangleShape(sf::Vector2f(32.f, 32.f));
            buyBt.setFillColor(sf::Color(255, 255,255));
            buyBt.setPosition(122.f , 34.f);
            buyBt.setTexture(&img3);


        }
        bool pressedPlay(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 10.f && y <= 110.f) return true; else return false;}
        bool pressedInstructions(float x, float y){
            if(x > 50.f && x <= 250.f && y >= 120.f && y <= 220.f) return true; else return false;}


        // new
        bool pressedBuyBt(float x, float y){
            if(x > 390.f && x <= 422.f && y >= 110.f && y <= 155.f) return true; else return false;}


        sf::RectangleShape& getPlayBtn() {return playBtn;}
        sf::RectangleShape& getInstructionsBtn() {return instructionsBtn;}
        sf::RectangleShape& getBuyBt() {return buyBt;}
    private:
        sf::RectangleShape playBtn;
        sf::RectangleShape instructionsBtn;
        sf::RectangleShape buyBt;
        sf::Texture img3;
        sf::Texture img1;
        sf::Texture img2;
};


#endif // MENU_HPP_INCLUDED
