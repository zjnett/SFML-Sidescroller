/******************************
Programmer: Zach Nett
Date: 5/6/19
File: Player.cpp
*******************************/

#include "Player.h"

void Player::handlePlayerMovement() {
    // Logic Booleans
    bool isMoving = false;

    // Player Animation Clock
    sf::Clock playerAnimationClock;

    // Move Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        isMoving = true;
        this->move(-1.0 * this->speed, 0);
    }
    // Move Right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        isMoving = true;
        this->move(1.0 * this->speed, 0);
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        isMoving = false;
    }
    
    if (playerAnimationClock.getElapsedTime().asSeconds() > 1.0) {
        if (isMoving) {
            // Play run animation
            //handlePlayerAnimation(runAnim, 6);
        } else {
            // Default: Play idle animation
            //handlePlayerAnimation(idleAnim, 4);
        }
        playerAnimationClock.restart();
    }
}

void Player::handlePlayerAnimation(sf::Texture txArray[], int frameCount) {
    static int counter;
    if (counter == frameCount)
        counter = 0;
    this->setTexture(txArray + counter);
    counter++;
}