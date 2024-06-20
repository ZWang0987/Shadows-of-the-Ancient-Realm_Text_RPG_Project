#ifndef ENEMYCHARACTER_HPP
#define ENEMYCHARACTER_HPP
#include "character.hpp"

class EnemyCharacter: public Character {
    private:
        int currentXp, currentGold;
        string enemyRank;
    public:
        EnemyCharacter(const string& name, const string& enemyRank, double health, double strength, double wisdom, double defense, double speed, int droppedGold, int droppedXp);
        ~EnemyCharacter();
        int getDroppedXp();
        int getDroppedGold();
        void appendDroppedXp(const int& xp);
        void appendDroppedGold(const int& gold);
        string getEnemyRank();
};

#endif