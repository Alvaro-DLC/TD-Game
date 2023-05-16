#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Player
{
    public:
        // constructor
        Player()
        {
            setHealth(10);
            update_healthBar(health);
            setCurrency(4);
            update_currency(currency);
            healthBar.setFillColor(sf::Color::Green);
            healthBar.setPosition(10.f,300.f);
            pixel_currency.setCharacterSize(10);
            pixel_currency.setFillColor(sf::Color::Green);
            pixel_currency.setPosition(10.f, 0.f);
            if (!pixel_font.loadFromFile("fonts/pixel.ttf")) 
            {
                // error handling
            }
            pixel_currency.setFont(pixel_font);
        }

        // Setters
        void setHealth(int health) {this->health = health;}
        void setCurrency(int currency) {this->currency = currency;}

        // Getters
        sf::RectangleShape getHeathBar()const {return healthBar;}
        sf::Text getDigitalCurrency()const {return pixel_currency;}
        int getHealth()const {return health;}
        int getCurrency()const {return currency;}

        // member functions
        void update_healthBar(int health)
        {
            healthBar.setSize(sf::Vector2f(health * 20.f, 10.f));
        }
        void take_damage(int damage) 
        {
            health -= damage;
            update_healthBar(health);
        }
        void update_currency(int currency)
        {
            pixel_currency.setString(to_string(currency));
        }
        void add_currency() 
        {
            currency += 2;
            update_currency(currency);
        }
        void reset() 
        {
            setHealth(10);
            update_healthBar(health);
            setCurrency(4);
            update_currency(currency);
        }

    private:
        int health, currency;
        sf::RectangleShape healthBar;
        sf::Font pixel_font;
        sf::Text pixel_currency;

};

#endif