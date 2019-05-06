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

    // Load player textures
    sf::Texture pcTx[10];
    pcTx[0].loadFromFile("textures/player/player.png");

    // Create player object
    Player pc(*(new sf::Vector2f(250.0, 185.0)), pcTx, *(new sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)));

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