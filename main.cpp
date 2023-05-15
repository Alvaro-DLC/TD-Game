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
    sf::Texture backgroundTexture;
    MainMenu m;
    Towers monkey1;
    EnemyMobs enemy1;
    Buy btn;
    vector<EnemyMobs> myClass;
    myClass.push_back(enemy1);


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
                            gameWin.clear(sf::Color(255.f, 255.f, 255.f));
                            gameWin.draw(myClass[0].getEnemy());
                            gameWin.draw(monkey1.getTower());
                            gameWin.display();
                            // attempting buttonbelow
                            gameWin.draw(btn.getBuyBtn());
                            btn.set(30,50);
                            gameWin.draw(btn.getBuyBtn());
                             btn.set(30,50);
                            bool showM = false;
                            if (event.type == sf::Event::MouseButtonPressed)
                            {
                                if (event.mouseButton.button == sf::Mouse::Left)
                                {
                                    // Check if the mouse clicked the button
                                    if (btn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                                    {
                                        std::cout << "Button clicked!" << std::endl;
                                        showM = true; // Activate the menu
                                    };
                                };
                            };
                            
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
                             
                            // monkey1.set(30,50); // <---sets enemy--|
                            
                            // <---moves enemy till it reaches the goal--->
                            if (myClass[0].getTurn() > 60)
                                {
                                    int ox = 0;
                                }
                                else{
                                    myClass[0].move();
                                }
                            // <------------------------------------------>

                            sf::Event evGame;
                        //     while(gameWin.pollEvent(evGame))
                        //     {

                        //         if(sf::Event::Closed == evGame.type && gameWin.hasFocus())
                        //         {
                        //             mPlayer.reset();
                        //             myClass[0].reset();
                        //             myClass[0].resetTurn();
                        //             gameWin.close();
                
                        //         }
                                
                        //         else if(sf::Event::MouseButtonReleased == evGame.type && gameWin.hasFocus())
                        //         {
                        //             mPlayer.walk();
                        //             gameWin.clear(sf::Color(255.f, 255.f, 255.f));
                        //             gameWin.draw(mPlayer.getPlayer());
                        //             gameWin.display();
                        //         }
                                
                        //     }
                        // }
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
            menu_window.clear();
            menu_window.draw((m.getPlayBtn()));
            menu_window.draw((m.getInstructionsBtn()));
            menu_window.display();

        }
    }

    return 0;
    };
};
void updateView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = static_cast<float>(window.getSize().x) / window.getSize().y;
    view.setSize(320 * aspectRatio, 320);
};