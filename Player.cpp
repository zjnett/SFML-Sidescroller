/******************************
Programmer: Zach Nett
Date: 5/6/19
File: Player.cpp
*******************************/

#include "Player.h"

void Player::handlePlayerMovement() {
    // Move Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->move(-1.0 * this->speed, 0);
    }
    // Move Right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->move(1.0 * this->speed, 0);
    }
    // Jump
    sf::Clock jumpTimer;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (jumpTimer.getElapsedTime().asMilliseconds() < 1.0) {
            this->move(0, -1.0 * this->speed);
        }
    }
    jumpTimer.restart();
}

void Player::handlePlayerAnimation(sf::Texture txArray[], int frameCount, double animationSpeed) {
    sf::Clock animationClock;
    for (int i = 0; i < frameCount; i++) {
        if (animationClock.getElapsedTime().asSeconds() > animationSpeed) {
            this->setTexture(txArray + i);
        }
    }
}

void Player::handlePlayerAnimation(sf::Texture txArray[], int frameCount) {
    sf::Clock animationClock;
    for (int i = 0; i < frameCount; i++) {
        if (animationClock.getElapsedTime().asSeconds() > 1.0f) {
            this->setTexture(txArray + i);
        }
    }
}