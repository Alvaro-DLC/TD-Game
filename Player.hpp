#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Player
{
    public:
        // constructor
        Player()
        {
            reset();
            update_healthBar(health);
            healthBar.setFillColor(sf::Color::Green);
            healthBar.setPosition(20.f,300.f);
        }

        // Setters
        void setHealth(int health) {this->health = health;}
        void setCurrency(int currency) {this->currency = currency;}

        // Getters
        sf::RectangleShape getHeathBar()const {return healthBar;}
        int getHealth()const {return health;}
        int getCurrency()const {return currency;}

        // member functions
        void update_healthBar(int health)
        {
            healthBar.setSize(sf::Vector2f(health * 20.f, 10.f));
        }
        void take_damage(int damage) {health -= damage;}
        void add_currency() {currency += 2;}
        void reset() 
        {
            setHealth(10);
            update_healthBar(health);
            setCurrency(4);
        }

    private:
        int health, currency;
        sf::RectangleShape healthBar;
};

#endif