#include "../header/Dellio.hpp"

Dellio::Dellio()
    : EnemyCharacter("Dellio", "Unruly Brother", 175, 5, 10, 25, 15, 100 , 100 ) {}

Dellio::~Dellio(){
    // Nothing to clean up, so the destructor is empty
}

// void Dellio::netherBlade(UserCharacter& userChar) { 
//     double damage = 0;
//     damage = 2.5 + (this->getStrength()*1.5);
//      if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Dellio::inferno(UserCharacter& userChar) { 
//     double damage = 0;
//     damage = 3+ (this->getStrength()*1.5 - userChar.getDefense());
//      if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Dellio::rainOfFire(UserCharacter& userChar) { 
//      int numberOfHits = 3; // Number of hits
//     double totalDamage = 0;
//     for(int i = 0; i < numberOfHits; ++i) {
//         double damage = 1.0 + (this->getStrength() * 0.5); // Lower damage per hit
//         if(damage > 0){
//             totalDamage += damage;
//         }
//     }
//     if(totalDamage > 0){
//         userChar.appendCurrentHealth(totalDamage * -1);
//     }
// }

// void Dellio::blazingDeath(UserCharacter& userChar) { 
//     double damage = 0;
//     damage = 5.0 + (this->getStrength() * 3.0);
//      if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
//     // High risk part: chance to deal damage to self
//     double selfDamageChance = 0.2; // 20% chance
//     if((rand() / double(RAND_MAX)) < selfDamageChance) {
//         double selfDamage = damage * 0.5; // Half of the damage to the enemy
//         this->appendCurrentHealth(selfDamage * -1);
//     }
// }