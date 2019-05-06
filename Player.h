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
    Player(std::string name, double health, double maxHealth, double stamina, double maxStamina, 
        sf::Vector2f &size, const sf::Texture *texture, sf::Vector2f &pos) : sf::RectangleShape(size) {
            setName(name);
            setHealth(health);
            setMaxHealth(maxHealth);
            setStamina(stamina);
            setMaxStamina(maxStamina);
            setTexture(texture);
            setPosition(pos);
        }
    
    // Value Constructor 2
    Player(sf::Vector2f &size, const sf::Texture *texture, sf::Vector2f &pos) : sf::RectangleShape(size) {
        setTexture(texture);
        setPosition(pos);
    }

    // Destructor
    ~Player() {}

    void handlePlayerMovement();
};

#endif /* PLAYER_H */