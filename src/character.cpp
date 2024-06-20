#include "../header/character.hpp"

Character::Character(const string& name, double health, double strength, double wisdom, double defense, double speed){
    this->name = name;
    this->currentHealth = health;
    this->strength = strength;
    this->wisdom = wisdom;
    this->defense = defense;
    this->speed = speed;
}

Character::~Character() {
    // Nothing to clean up, so the destructor is empty
}

void Character::appendCurrentHealth(const double& health){
    currentHealth += health;
}

// void Character::appendMaxHealth(const double& health){
//     maxHealth += health;
// }

void Character::appendStrength(const double& strength) {
    this->strength += strength;
}

void Character::appendWisdom(const double& wisdom){
    this->wisdom += wisdom;
}

void Character::appendDefense(const double& defense) {
    this->defense += defense;
}

void Character::appendSpeed(const double& speed) {
    this->speed += speed;
}

double Character::getHealth(){
    return currentHealth;
}

// double Character::getMaxHealth() {
//     return maxHealth;
// }

double Character::getStrength() {
    return strength;
}

double Character::getWisdom() {
    return wisdom;
}

double Character::getDefense() {
    return defense;
}

double Character::getSpeed() {
    return speed;
}

string Character::getName() {
    return name;
}