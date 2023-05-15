#include <iostream>
#include "menu.hpp"
#include "towers.hpp"
#include "enemy_mobs.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

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
    Towers monkey1;
    EnemyMobs enemy;
    vector<EnemyMobs> round1;
    // <---adds enemy 10--->
    for(int enemy_amount = 0; enemy_amount < 10; enemy_amount++)
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
                            gameWin.draw(monkey1.getTower());
                            for(int i = 0; i < 2; i++)
                            {
                                gameWin.draw(round1[i].getEnemy());
                            }
                            gameWin.display();
                            monkey1.set(30,50); // <---sets tower--|
                            
                            // <---moves enemy till it reaches the goal--->
                            if (round1[0].getTurn() > 160)
                                {
                                    int ox = 0;
                                }
                                else{
                                    round1[0].move();
                                }
                            // <------------------------------------------>

                            sf::Event evGame;
                            while(gameWin.pollEvent(evGame))
                            {

                                if(sf::Event::Closed == evGame.type && gameWin.hasFocus())
                                {
                                    
                                    round1[0].reset(50,0);
                                    round1[0].resetTurn();
                                    gameWin.close();
                
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