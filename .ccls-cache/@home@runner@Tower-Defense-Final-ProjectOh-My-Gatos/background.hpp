#include <iostream>
#include "menu.hpp"
#include "mainChar.hpp"
#include <background.hpp>

using namespace std;

int main()
{
    sf::RenderWindow menu_window(sf::VideoMode(300, 400), "Menu");
    sf::RenderWindow instruct_win, gameWin;
    MainMenu m;
    MainPlayer mPlayer;

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
                        gameWin.create(sf::VideoMode(500,600), "Walking");

                        while(gameWin.isOpen())
                        {
                            gameWin.clear(sf::Color(255.f, 255.f, 255.f));
                            gameWin.draw(mPlayer.getPlayer());
                            gameWin.display();
                            sf::Event evGame;
                            while(gameWin.pollEvent(evGame))
                            {
                                if(sf::Event::Closed == evGame.type && gameWin.hasFocus())
                                {
                                    mPlayer.reset();
                                    gameWin.close();
                                }
                                else if(sf::Event::MouseButtonReleased == evGame.type && gameWin.hasFocus())
                                {
                                    mPlayer.walk();
                                    gameWin.clear(sf::Color(255.f, 255.f, 255.f));
                                    gameWin.draw(mPlayer.getPlayer());
                                    gameWin.display();
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
            menu_window.clear();
            menu_window.draw((m.getPlayBtn()));
            menu_window.draw((m.getInstructionsBtn()));
            menu_window.display();

        }
    }

    return 0;
}
