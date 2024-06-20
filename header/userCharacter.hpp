#ifndef USERCHARACTER_HPP
#define USERCHARACTER_HPP
#include "character.hpp"
#include <string>
using namespace std;
#include <iostream>

class UserCharacter : public Character {
    private:
        string userItems[8];
        int currentLevel, currentXp, currentGold;
        double maxHealth;
        string className;

    public:
        UserCharacter(const string& name, const string& className, double health, double strength, double widsom, double defense, double speed, int gold, int xp);
        ~UserCharacter();
        void appendXP(const int& xp);
        void levelUp();
        void appendGold(const int& gold);
        int getGold();
        int getXp();
        int getLevel();
        void addItem(const string& itemName);
        void removeItem(const string& itemName);
        double getMaxHealth();
        void appendMaxHealth(const double& health);
        string getClassName();
        void printInventory();
        void useItem();
};


#endif

