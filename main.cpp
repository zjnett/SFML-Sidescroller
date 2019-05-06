/******************************
Programmer: Zach Nett
Date: 5/6/19
File: main.cpp
*******************************/

#include "Game.h"
#include "Player.h"

int main(void) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Working Title");

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return EXIT_SUCCESS;
}