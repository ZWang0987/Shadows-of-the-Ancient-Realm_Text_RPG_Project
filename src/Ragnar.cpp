#include "../header/Ragnar.hpp"

Ragnar::Ragnar()
    : EnemyCharacter("Ragnar", "Unruly Brother's Right Hand", 125, 15, 5, 12, 5, 50 , 70) {}

Ragnar::~Ragnar() {
    // Nothing to clean up, so the destructor is empty
}

// void Ragnar::overheat(UserCharacter& userChar) { 
//     double damage = 2.5 + (this->getStrength() * 1.5) - userChar.getDefense();
//     if(damage > 0){
//         userChar.appendCurrentHealth(damage * -1);
//     }
// }

// void Ragnar::pyroclasm(UserCharacter& userChar) { 
//     double damage = 3.0 + (this->getStrength() * 1.5) - userChar.getDefense();
//     if(damage > 0){
//         userChar.appendCurrentHealth(damage * -1);
//     }
// }

// void Ragnar::flamethrower(UserCharacter& userChar) { 
//     int numberOfHits = 3; // Number of hits
//     double totalDamage = 0;
//     for(int i = 0; i < numberOfHits; ++i) {
//         double damage = 1.0 + (this->getStrength() * 0.5) - userChar.getDefense();
//         if(damage > 0){
//             totalDamage += damage;
//         }
//     }
//     if(totalDamage > 0){
//         userChar.appendCurrentHealth(totalDamage * -1);
//     }
// }

// void Ragnar::fireSlam(UserCharacter& userChar) { 
//     double damage = 5.0 + (this->getStrength() * 3.0) - userChar.getDefense();
//     if(damage > 0){
//         userChar.appendCurrentHealth(damage * -1);
//     }
//     // High risk part: chance to deal damage to self
//     double selfDamageChance = 0.2; // 20% chance
//     if((rand() / double(RAND_MAX)) < selfDamageChance) {
//         double selfDamage = (5.0 + (this->getStrength() * 3.0)) * 0.5; // Half of the initial calculated damage
//         this->appendCurrentHealth(selfDamage * -1);
//     }
// }