#ifndef BATTLEDRIVER_HPP
#define BATTLEDRIVER_HPP

// #include "character.hpp"
// #include "userCharacter.hpp"
// #include "enemyCharacter.hpp"
// #include "Archer.hpp"
// #include "Dellio.hpp"
// #include "Diallos.hpp"
// #include "etharSoul.hpp"
// #include "fallenEthar.hpp"
// #include "KaiSon.hpp"
// #include "Knight.hpp"
// #include "Mage.hpp"
// #include "Ragnar.hpp"
// #include "Rogue.hpp"
// #include "Voidling.hpp"
// #include "VoidWalker.hpp"

#include <string>
using namespace std;

template <typename T1>
class BattleDriver {
    private:
        UserCharacter* userCharPointer;
        T1* enemyCharPointer;
        int userMoveSelection; 
        int enemyMoveSelection;
        int damage;
    public:
        BattleDriver(UserCharacter* UserChar , T1* EnemyChar) : userCharPointer(UserChar), enemyCharPointer(EnemyChar),userMoveSelection(0),enemyMoveSelection(0),damage(0) {}
        ~BattleDriver(){}
        void startBattle();
        void outputFighters();
        void outputFighterHealth();
        void outputUserChoices();
        void inputUserKnightChoices();
        void inputUserRogueChoices();
        void inputUserArcherChoices();
        void inputUserMageChoices();
        void enemyVoidlingChoices();
        void enemyEtharSoulChoices();
        void enemyVoidWalkerChoices();
        void enemyFallenEtharChoices();
        void enemyKaiSonChoices();
        void enemyRagnarChoices();
        void enemyDellioChoices();
        void enemyDiallosChoices();
        void endBattleWinner();
};

#endif