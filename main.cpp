#include <iostream>
#include "menu.hpp"
#include "Player.hpp"
#include "towers.hpp"
#include "Enemy.hpp"
#include "buy.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow menu_window(sf::VideoMode(600, 600), "Menu");
    sf::RenderWindow instruct_win, gameWin,buyWin;
    sf::Texture background;
    if (!background.loadFromFile("Map-2.png"))
    {
        // error
    }
    sf::Sprite backgroundSprite(background);
    MainMenu m;
    // Player
    Player player;
    //button
    Buy btn;
    // Timer
    sf::Clock enemy_timer, enemy_move_timer;
    //Towers 
    Towers monkey1;
    // Enemies 
    int enemy_onscreen = -1;
    Enemy enemy(0);
    vector<Enemy> round1;
    // <---adds enemy 10--->
    for(int i = 0; i < 10; i++)
    {
        round1.push_back(enemy);
    }
    // <------------------->


    while (menu_window.isOpen())
    {
        menu_window.clear();
        menu_window.draw((m.getInstructionsBtn()));
        // menu_window.display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (menu_window.pollEvent(event))
        {
            switch(event.type)
            {
                // "close requested" event: we close the window
                case sf::Event::Closed :
                    menu_window.close();
                    break;
                case sf::Event::MouseButtonPressed: // Left click from mouse
                    if(menu_window.hasFocus() && m.pressedPlay(sf::Mouse::getPosition(menu_window).x,sf::Mouse::getPosition(menu_window).y ))
                    {
                        cout << "Clicked playBtn\n";

                        // <---Settting the window--->
                        gameWin.create(sf::VideoMode(960, 960, 32), "TD-Game");
                        const float aspectRatio = static_cast<float>(320) / 320;
                        sf::View view(sf::FloatRect(0.f, 0.f, 320,320));
                        if (aspectRatio > 1.f)
                        {
                            view.setSize(320 * aspectRatio, 320);
                        }
                        else
                        {
                            view.setSize(320, 320 / aspectRatio);
                        }
                        gameWin.setView(view);
                        // <------------------------>

                        while(gameWin.isOpen())
                        {
                            gameWin.clear();
                            gameWin.draw(backgroundSprite);
                            gameWin.draw(player.getHeathBar());
                            // gameWin.draw(monkey1.getTower());
                            for(int i = 0; i < enemy_onscreen; i++)
                            {
                                gameWin.draw(round1[i].getEnemy());
                            }
                            


                            
                            
                            gameWin.draw(monkey1.getTower());
                            monkey1.set(50,100);
                            // gameWin.draw(btn.getBuyB());
                            // gameWin.draw((btn.getBuyB()));
                            // gameWin.draw((m.getInstructionsBtn()));
                            gameWin.draw((m.getBuyBt()));
                            
                            gameWin.display();
                            // <---Allows enemies to move--->
                            if(enemy_timer.getElapsedTime().asSeconds() >= 2 && enemy_onscreen < 10)
                            {
                                enemy_onscreen++;
                                round1[enemy_onscreen].setMoving(true);
                                cout << "added enemy " << enemy_onscreen << endl;
                                enemy_timer.restart();
                            }
                            // <---------------------------->
                            
                            
                            monkey1.set(30,50); // <---sets enemy--|
                            
                            // <---Allows enemies to move--->
                            if(enemy_timer.getElapsedTime().asSeconds() >= 2 && enemy_onscreen < 10)
                            {
                                enemy_onscreen++;
                                round1[enemy_onscreen].setMoving(true);
                                cout << "added enemy " << enemy_onscreen << endl;
                                enemy_timer.restart();
                            }
                            // <---------------------------->

                            // <---moves enemies--->
                            if(enemy_move_timer.getElapsedTime().asMilliseconds() >= 100)
                            {
                                for(int x = 0; x < enemy_onscreen; x++)
                                {
                                    if (round1[x].getMoving() && round1[x].getTurn() < 250)
                                        {
                                            round1[x].move();

                                            // cout << "enemy " << x << " moved\n";
                                        }
                                        
                                }
                                enemy_move_timer.restart();
                            }
                            // <------------------->
                            if(gameWin.hasFocus() && m.pressedBuyBt(sf::Mouse::getPosition(gameWin).x,sf::Mouse::getPosition(gameWin).y ))
                            {
                                cout << "Clicked buy\n";
                                buyWin.create(sf::VideoMode(200,200),"BUY");
                                while(buyWin.isOpen())
                                {
                                    sf::Event eBuy;
                                    while(buyWin.pollEvent(eBuy))
                                    {
                                        if(sf::Event::Closed == eBuy.type && buyWin.hasFocus())
                                        {
                                            buyWin.close();
                                        }

                                    }
                                }
                            }
                            // <---Events--->
                            sf::Event evGame; 
                            while(gameWin.pollEvent(evGame))
                            {

                                if(sf::Event::Closed == evGame.type && gameWin.hasFocus())
                                {
                                    // <---Resets the enemies--->
                                    for(int y = 0; y < 10; y++)
                                    {
                                        round1[y].reset();
                                        round1[y].resetTurn();
                                        round1[y].setMoving(false);
                                    }
                                    enemy_timer.restart();
                                    enemy_onscreen = -1;
                                    enemy_move_timer.restart();
                                    // <------------------------>
                                    gameWin.close();
                
                                }
                                
                            }
                            // <-------->
                        }
                    }
                    if(menu_window.hasFocus() && m.pressedInstructions(sf::Mouse::getPosition(menu_window).x,sf::Mouse::getPosition(menu_window).y ))
                    {
                        cout << "Clicked instructionsBtn\n";
                        instruct_win.create(sf::VideoMode(400,500),"Instructions");
                        while(instruct_win.isOpen())
                        {
                            sf::Event eInst;
                            while(instruct_win.pollEvent(eInst))
                            {
                                if(sf::Event::Closed == eInst.type && instruct_win.hasFocus())
                                {
                                    instruct_win.close();
                                }
                            }
                        }
                    }
                    break;
                    
                }
            }
            menu_window.clear();
            menu_window.draw((m.getPlayBtn()));
            menu_window.draw((m.getInstructionsBtn()));
            menu_window.display();


        }
        }