// #include "../header/Knight.hpp"

// //(name, health, strength, wisdom, defense, speed, gold, xp )
// Knight::Knight(const string& userName) 
//     : UserCharacter(userName, "Knight", 100, 6, 1, 6, 1, 0, 0) {}


// void Knight::slash(EnemyCharacter& enemyChar) {
//     double damage = 0;
//     damage = 3 * this->getLevel() + (this->getStrength() - enemyChar.getDefense());

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Knight::shieldSlam(EnemyCharacter& enemyChar) {
//     double damage = 0;
//     damage = 3 * this->getLevel() + (this->getDefense() - enemyChar.getDefense());

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }


// void Knight::whirlwind(EnemyCharacter& enemyChar) {
//     double damage = 0;
//     //Special base attack
//     damage = 6 * this->getLevel() + (this->getStrength() - enemyChar.getDefense());

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Knight::thunderClap(EnemyCharacter& enemyChar) {
//     double damage = 0;
//     //True Damage
//     damage = 4 * this->getLevel() + (this->getStrength());

//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

