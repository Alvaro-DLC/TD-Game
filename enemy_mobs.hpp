#ifndef ENEMYMOBS_HPP_INCLUDED
#define ENEMYMOBS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class EnemyMobs
{
    public:
    EnemyMobs()
    {
        if (!enemyText[0].loadFromFile("blue_enemy.png"))
        {
                // error...
        }
        if (!enemyText[1].loadFromFile("orange_enemy.png"))
        {
                // error...
        }
        enemy.setTexture(enemyText[0]);
        enemy.setPosition(sf::Vector2f(0.f, 50.f));
    }
    
    sf::Sprite& getEnemy(){return enemy;}
    
    void setMoving(bool moving) {this->moving = moving;}

    int getTurn()const {return turn;}
    int getMoving()const {return moving;}

    void resetTurn() {turn = 0;}
    void reset() {enemy.setPosition(sf::Vector2f(0.f, 50.f));}

    void move()
    {
        //if(timer.getElapsedTime().asMilliseconds() >= 100)
        //{
            
            if(turn > 150 && turn <= 250)
            {
                enemy.move(sf::Vector2f(0.f, -4.f));
                turn++;
            }
            else if(turn > 97 && turn <= 150)
            {
                enemy.move(sf::Vector2f(4.f, 0.f));
                turn++;
            }
            else if(turn > 75 && turn <= 97)
            {
                enemy.move(sf::Vector2f(0.f, 4.f));
                turn++;
            }
            else if(turn > 51 && turn <= 75)
            {
                enemy.move(sf::Vector2f(-4.f, 0.f));
                turn++;
            }
            else if (turn > 29 && turn <= 51)
            {
                enemy.move(sf::Vector2f(0.f, 4.f));
                turn++;
            }
            else
            {
                enemy.move(sf::Vector2f(4.f, 0.f));
                turn++;
            }
            //timer.restart();
        //}
    }

    private:
        sf::Sprite enemy;
        sf::Texture enemyText[1];
        int turn = 0;
        bool moving = false;

};

#endif