#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using namespace std;

class Character {
    private: 
        string name;
        double currentHealth, wisdom, strength, defense, speed;

    public:
        Character(const string& name, double health, double strength, double wisdom, double defense, double speed);
        ~Character();
        void appendCurrentHealth(const double& health);
        //void appendMaxHealth(const double& health);
        void appendStrength(const double& strength);
        void appendWisdom(const double& wisdom);
        void appendDefense(const double& defense);
        void appendSpeed(const double& speed);
        string getName();
        double getHealth();
        //double getMaxHealth();
        double getStrength();
        double getWisdom();
        double getDefense();
        double getSpeed();
};

#endif
