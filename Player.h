/******************************
Programmer: Zach Nett
Date: 5/6/19
File: Player.h
*******************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include "Entity.h"

class Player : public Entity, public sf::RectangleShape {
public:
    // Value Constructor 1
    Player(std::string name, double health, double maxHealth, double stamina, double maxStamina, double speed,
        sf::Vector2f &size, const sf::Texture *texture, sf::Vector2f &pos) : sf::RectangleShape(size) {
            setName(name);
            setHealth(health);
            setMaxHealth(maxHealth);
            setStamina(stamina);
            setMaxStamina(maxStamina);
            setSpeed(speed);
            setTexture(texture);
            setPosition(pos);
        }
    
    // Value Constructor 2
    Player(sf::Vector2f &size, const sf::Texture *texture, sf::Vector2f &pos) : speed(1.0), sf::RectangleShape(size) {
        setTexture(texture);
        setPosition(pos);
    }

    // Destructor
    ~Player() {}

    double getSpeed() {
        return speed;
    }

    void setSpeed(double newSpeed) {
        speed = newSpeed;
    }

    void handlePlayerMovement();

    void handlePlayerAnimation(sf::Texture txArray[], int frameCount, double animationSpeed);

    void handlePlayerAnimation(sf::Texture txArray[], int frameCount);

private:
    double speed;
};

#endif /* PLAYER_H */