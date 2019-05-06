/******************************
Programmer: Zach Nett
Date: 5/6/19
File: Entity.h
*******************************/

#ifndef ENTITY_H
#define ENTITY_H

#include "Game.h"

class Entity {
public:

    // Default Constructor
    Entity() : name(""), maxHealth(10.0), health(10.0), maxStamina(10.0), stamina(10.0) {}

    // Value Constructor 1
    Entity(std::string &_name, double &_health, double &_stamina) :
        name(_name), maxHealth(_health), health(_health), maxStamina(_stamina), stamina(_stamina) {}

    // Value Constructor 2
    Entity(std::string &_name, double &_maxHealth, double &_health, double &_maxStamina, double &_stamina) :
        name(_name), maxHealth(_maxHealth), health(_health), maxStamina(_maxStamina), stamina(_stamina) {}

    // Virtual Destructor
    virtual ~Entity() {}

    // Copy Constructor
    Entity(const Entity &oldEntity) {
        tags = oldEntity.tags;
        name = oldEntity.name;
        maxHealth = oldEntity.maxHealth;
        health = oldEntity.health;
        maxStamina = oldEntity.maxStamina;
        stamina = oldEntity.stamina;
    }

    // Copy Assignment Operator
    Entity& operator= (const Entity &oldEntity) {
        if (&oldEntity == this)
            return *this;
        tags = oldEntity.tags;
        name = oldEntity.name;
        maxHealth = oldEntity.maxHealth;
        health = oldEntity.health;
        maxStamina = oldEntity.maxStamina;
        stamina = oldEntity.stamina;
        return *this;
    }

    // *******************************************************************************************************
    // ACCESSORS
    // *******************************************************************************************************

    // getTag, returns if a specific tag is on an Entity (iterates over tag vector)
    bool getTag(std::string &lookFor) {
        for (auto &i : tags) {
            if(i == lookFor)
                return true;
        }
        return false;
    }

    // getTags, returns tags vector
    std::vector<std::string> getTags() {
        return tags;
    }

    // getName, returns name of the Entity object
    std::string getName() {
        return name;
    }

    // getMaxHealth, returns max health of the Entity object
    double getMaxHealth() {
        return maxHealth;
    }

    // getCurrentHealth, returns current health of the entity object
    double getCurrentHealth() {
        return health;
    }

    // getHealthRatio, returns ratio between current health and max health (health percentage)
    double getHealthRatio() {
        return health / maxHealth;
    }

    // getMaxStamina, returns max stamina of the Entity object
    double getMaxStamina() {
        return maxStamina;
    }

    // getStamina, returns current stamina of the Entity object
    double getStamina() {
        return stamina;
    }

    // getStaminaRatio, returns ratio between current stamina and max stamina (stamina percentage)
    double getStaminaRatio() {
        return stamina / maxStamina;
    }

    // *******************************************************************************************************
    // MUTATORS
    // *******************************************************************************************************

    // addTag, adds a tag (string) to vector of tags
    void addTag(std::string &tag) {
        tags.push_back(tag);
    }

    // setName, sets the name of the Entity
    void setName(std::string &newName) {
        name = newName;
    }

    // setMaxHealth, sets the max health of the Entity
    void setMaxHealth(double newMax) {
        maxHealth = newMax;
    }

    // setHealth, sets the health of the Entity
    void setHealth(double newHealth) {
        health = newHealth;
    }

    // setHealthRatio, sets the health ratio of the Entity (percentage)
    // Prerequisite: maxHealth is accurate
    void setHealthRatio(double percentage) {
        health = maxHealth * percentage;
    }

    // setMaxStamina, sets the max stamina of the Entity
    void setMaxStamina(double newMax) {
        maxStamina = newMax;
    }

    // setStamina, sets the current stamina of the Entity
    void setStamina(double newStamina) {
        stamina = newStamina;
    }

    // setStaminaRatio, sets the stamina ratio of the Entity (percentage)
    // Prerequisite: maxStamina is accurate
    void setStaminaRatio(double percentage) {
        stamina = maxStamina * percentage;
    }

private:

    std::vector<std::string> tags;
    std::string name;
    double maxHealth;
    double health;
    double maxStamina;
    double stamina;

};

#endif /* ENTITY_H */