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

    // TODO: Delegate graphics loading to its own function

    // Load player idle textures
    sf::Texture pcIdleTx[4];
    pcIdleTx[0].loadFromFile("textures/player/idle-nowep/adventurer-idle-00.png");
    pcIdleTx[1].loadFromFile("textures/player/idle-nowep/adventurer-idle-01.png");
    pcIdleTx[2].loadFromFile("textures/player/idle-nowep/adventurer-idle-02.png");
    pcIdleTx[3].loadFromFile("textures/player/idle-nowep/adventurer-idle-03.png");

    // Load player run textures
    sf::Texture pcRunTx[6];
    pcRunTx[0].loadFromFile("textures/player/run/adventurer-run-00.png");
    pcRunTx[1].loadFromFile("textures/player/run/adventurer-run-01.png");
    pcRunTx[2].loadFromFile("textures/player/run/adventurer-run-02.png");
    pcRunTx[3].loadFromFile("textures/player/run/adventurer-run-03.png");
    pcRunTx[4].loadFromFile("textures/player/run/adventurer-run-04.png");
    pcRunTx[5].loadFromFile("textures/player/run/adventurer-run-05.png");

    // Create player object
    Player pc(*(new sf::Vector2f(250.0, 185.0)), pcIdleTx, *(new sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)));
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
        pc.handlePlayerAnimation(pcIdleTx, 4);
    }
    return EXIT_SUCCESS;
}