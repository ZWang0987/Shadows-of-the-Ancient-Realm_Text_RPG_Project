#include "../header/VoidWalker.hpp"

VoidWalker::VoidWalker()
    : EnemyCharacter("Void Walker", "Weakling", 50, 4, 4, 2, 2, 10 , 35) {}

VoidWalker::~VoidWalker() {
    // Nothing to clean up, so the destructor is empty
}

// void VoidWalker::corruption(UserCharacter& userChar) { 
//     double damage = 1 + (this->getStrength() * 1.5) + (this->getWisdom() * 0.5);
//     double defenseIgnore = userChar.getDefense() * 0.5; // Ignore 50% of the target's defense
//     damage -= defenseIgnore;
//     if(damage > 0){
//         userChar.appendCurrentHealth(damage * -1);
//     }
// }

// void VoidWalker::energyDrain(UserCharacter& userChar) { 
//     double damage = 1 + (this->getStrength() * 1.5) + (this->getWisdom() * 0.5) - userChar.getDefense();
//     if(damage > 0){
//         userChar.appendCurrentHealth(damage * -1);
//         this->appendCurrentHealth(damage * 0.3); // Heal 30% of the damage dealt
//     }
// }