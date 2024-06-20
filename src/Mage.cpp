// #include "../header/Mage.hpp"

// Mage::Mage(const string& userName)
//     : UserCharacter(userName, "Mage", 100, 1, 10, 1, 1, 0 , 0) {}

// void Mage::fireBall(EnemyCharacter& enemyChar){

//     double damage = 0;
//     //base value * userLevel + (userStat-enemyStat)
//     damage = 3 * this->getLevel() + (this->getWisdom() - enemyChar.getDefense());
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Mage::frostBolt(EnemyCharacter& enemyChar){

//     double damage = 0;
//     damage = 2 * this->getLevel() + (enemyChar.getHealth()/8);
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Mage::arcaneBlast(EnemyCharacter& enemyChar){

//     double damage = 0;
//     damage = 1.5 * this->getLevel() + (this->getWisdom() + (enemyChar.getHealth()/4));
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Mage::elementalStrike(EnemyCharacter& enemyChar){

//     double damage = 0;
//     damage = this->getLevel() * this->getWisdom();
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }