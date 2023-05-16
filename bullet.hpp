#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Bullet
{
    public:
    // constructors
    Bullet(int color = 0, float x , float y)
    {
        if (!bullet[0].loadFromFile("bullet.png"))
        {
                // error...
        }
        bullet.setTexture(bullet[color]);
        bullet.set(x , y);
    }

    // Setters
    
    void set(float x,float y)                                                                                  
        {
            bullet.setPosition(sf::Vector2f(y, x));
        }
    void setHealth(double health) {this->health = health;}
    void setMoving(bool moving) {this->moving = moving;}

    // Getters
    sf::Sprite& getBullet(){return bullet;}
    int getHealth()const {return health;}
    int getMoving()const {return moving;}

    // member functions
    void take_damage(int damage) {health -= damage;}
    void reset() {bullet.setPosition(sf::Vector2f(200.f, 200.f));}
    void move()
    {
                 
    }

    private:
        sf::Sprite bullet;
        sf::Texture bullet[0];
        int damage = 2;
        double health = .01; 
        bool moving = false;

};

#endif