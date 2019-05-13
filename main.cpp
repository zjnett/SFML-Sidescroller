/******************************
Programmer: Zach Nett
Date: 5/6/19
File: main.cpp
*******************************/

#include "Game.h"
#include "Player.h"

int main(void) {
    // Create game window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Working Title");

    // Create clocks

    // Create player object
    Player pc(*(new sf::Vector2f(250.0, 185.0)), idle[0], *(new sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)));

    // Load player idle textures
    sf::Texture idle[4];
    idle[0].loadFromFile("textures/player/idle-nowep/adventurer-idle-00.png");
    pc.setIdleAnim(idle[0], 0);
    idle[1].loadFromFile("textures/player/idle-nowep/adventurer-idle-01.png");
    pc.setIdleAnim(idle[1], 1);
    idle[2].loadFromFile("textures/player/idle-nowep/adventurer-idle-02.png");
    pc.setIdleAnim(idle[2], 2);
    idle[3].loadFromFile("textures/player/idle-nowep/adventurer-idle-03.png");
    pc.setIdleAnim(idle[3], 3);

    // Load player run textures
    sf::Texture run[6];
    run[0].loadFromFile("textures/player/run/adventurer-run-00.png");
    pc.setRunAnim(run[0], 0);
    run[1].loadFromFile("textures/player/run/adventurer-run-01.png");
    pc.setRunAnim(run[1], 1);
    run[2].loadFromFile("textures/player/run/adventurer-run-02.png");
    pc.setRunAnim(run[2], 2);
    run[3].loadFromFile("textures/player/run/adventurer-run-03.png");
    pc.setRunAnim(run[3], 3);
    run[4].loadFromFile("textures/player/run/adventurer-run-04.png");
    pc.setRunAnim(run[4], 4);
    run[5].loadFromFile("textures/player/run/adventurer-run-05.png");
    pc.setRunAnim(run[5], 5);

    // Set player speed
    pc.setSpeed(2.0);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(pc);
        window.display();
        
        pc.handlePlayerMovement();

        
    }
    return EXIT_SUCCESS;
}