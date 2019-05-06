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
    Player(string name, double health, double maxHealth, double stamina, double maxStamina, 
        sf::Vector2f &size, sf::Texture &texture, sf::Vector2f &pos) : name(name), health(health), 
        maxHealth(maxHealth), stamina(stamina), maxStamina(maxStamina), sf::RectangleShape(size) {
            setTexture(texture);
            setPosition(position);
        }
    
    // Value Constructor 2
    Player(sf::Vector2f &size, sf::Texture &texture, sf::Vector2f &pos) : sf::RectangleShape(size) {
        setTexture(texture);
        setPosition(pos);
    }

    // Destructor
    ~Player() {}
};

#endif /* PLAYER_H */