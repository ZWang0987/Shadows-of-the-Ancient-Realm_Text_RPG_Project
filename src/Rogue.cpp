// #include "../header/Rogue.hpp"

// //(name, health, strength, wisdom, defense, speed, gold, xp )
// Rogue::Rogue(const string& userName) : 
//     UserCharacter(userName, "Rogue", 100, 6, 1, 1, 6, 0, 0) {}

// void Rogue::sneakyDagger(EnemyCharacter& enemyChar){
//      double damage = 0;
//     damage = 4.5 * this->getLevel() + (this->getSpeed() - enemyChar.getDefense());

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Rogue::shadowStep(EnemyCharacter& enemyChar) {
//     double damage = 0;
//     //True Damage, scales on the speed 
//     damage = 2.5 * this->getSpeed();

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Rogue::sinisterSlash(EnemyCharacter& enemyChar){
//      double damage = 0;
//     damage = 3 * this->getLevel() + (this->getStrength() + this->getSpeed() - enemyChar.getDefense());

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Rogue::eviserate(EnemyCharacter& enemyChar){
//      double damage = 0;
//     damage =  this->getLevel() * (this->getStrength()/2) + this->getSpeed();

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

