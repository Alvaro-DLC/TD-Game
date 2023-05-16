#include <iostream>
#include "menu.hpp"
#include "towers.hpp"
#include "enemy_mobs.hpp"
#include "buy.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

void updateView(sf::RenderWindow& window, sf::View& view);

int main()
{
    sf::RenderWindow menu_window(sf::VideoMode(600, 600), "Menu");
    sf::RenderWindow instruct_win, gameWin;
    sf::Texture background;
    if (!background.loadFromFile("Map-2.png"))
    {
        // error
    }
    sf::Sprite backgroundSprite(background);
    MainMenu m;
    //button
    Buy btn;
    // Timer
    sf::Clock enemy_timer, enemy_move_timer;
    //Towers 
    Towers monkey1;
    // Enemies 
    int enemy_onscreen = -1;
    EnemyMobs enemy;
    vector<EnemyMobs> round1;
    // <---adds enemy 10--->
    for(int i = 0; i < 10; i++)
    {
        round1.push_back(enemy);
    }
    // <------------------->


    while (menu_window.isOpen())
    {
        menu_window.clear();
        menu_window.draw((m.getPlayBtn()));
        menu_window.draw((m.getInstructionsBtn()));
        menu_window.display();
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
                            // gameWin.draw(monkey1.getTower());
                            for(int i = 0; i < enemy_onscreen; i++)
                            {
                                gameWin.draw(round1[i].getEnemy());
                            }
                            


                            
                            
                            // gameWin.draw(monkey1.getTower());
                            // monkey1.set(50,100);
                            gameWin.draw(btn.getBuyBtn());
                            btn.set(34,122);
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
                            // attempting buttonbelow
                            
                            
                            bool showM = false;
                            // switch(event.type)
                            // {
                            //     case sf::Event::MouseButtonPressed:
                                    
                            //         if (event.mouseButton.button == sf::Mouse::Left)
                            //         {
                            //             // Check if the mouse clicked the button
                            //             if (gameWin.hasFocus() && btn.pressedBuy(sf::Mouse::getPosition(gameWin).x,sf::Mouse::getPosition(gameWin).y ))
                            //             {
                            //                 std::cout << "Button clicked! loser" << std::endl;
                            //                 showM = true; // Activate the menu
                                            
                            //             };
                            //         };
                            // };
                            // // gameWin.clear();
                            // gameWin.draw(btn.getBuyBtn());
                            // btn.set(30,50);
                            
                            if (showM)
                            {
                                sf::Font font;
                                // Draw the menu options
                                sf::RectangleShape option1(sf::Vector2f(32, 32));
                                option1.setFillColor(sf::Color(255,255,255));
                                option1.setPosition(300, 350);

                                sf::Text optionText1("Option 1", font, 24);
                                optionText1.setPosition(option1.getPosition().x + 50, option1.getPosition().y + 10);

                                sf::RectangleShape option2(sf::Vector2f(32, 32));
                                option2.setFillColor(sf::Color(255,255,255));
                                option2.setPosition(300, 425);

                                sf::Text optionText2("Option 2", font, 24);
                                optionText2.setPosition(option2.getPosition().x+ 50, option1.getPosition().y + 10);
                            };


                            // end of attempt
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
                            sf:: Event ppG;
                             while (gameWin.pollEvent(ppG))
                            {
                                if (event.type == sf::Event::Closed)
                                {
                                    gameWin.close();
                                }
                                else if (event.type == sf::Event::MouseButtonPressed)
                                {
                                    if (event.mouseButton.button == sf::Mouse::Left)
                                    {
                                        if (gameWin.hasFocus() && btn.pressedBuy(sf::Mouse::getPosition(gameWin).x,sf::Mouse::getPosition(gameWin).y ))
                                        {
                                            std::cout << "Button clicked! loser" << std::endl;
                                        }
                                    }
                                }
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

    return 0;
    };

void updateView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = static_cast<float>(window.getSize().x) / window.getSize().y;
    view.setSize(320 * aspectRatio, 320);
};