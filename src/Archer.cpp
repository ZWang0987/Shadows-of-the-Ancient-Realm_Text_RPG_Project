// #include "../header/Archer.hpp"

// Archer::Archer(const string& userName)
//     : UserCharacter(userName, "Archer", 100, 3, 2, 1, 5, 0 , 0) {}

// void Archer::explosvieBolt(EnemyCharacter& enemyChar){

//     double damage = 0;
//     //base value * userLevel + (userStat-enemyStat)
//     damage = 2.5 * this->getLevel() + (this->getStrength() - enemyChar.getDefense());
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Archer::piercingArrow(EnemyCharacter& enemyChar){

//     double damage = 0;
//     //ignores enemy defense (userlevel*2)
//     damage = this->getLevel() * 2;
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Archer::Volley(EnemyCharacter& enemyChar){

//     double damage = 0;
//     //base value * userLevel + (userStat-enemyStat)
//     damage = 1.5 * this->getLevel() + (this->getStrength() + this->getSpeed() - enemyChar.getDefense());
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Archer::arcaneShot(EnemyCharacter& enemyChar){

//     double damage = 0;
//     //base value * userLevel + (userStat-enemyStat)
//     damage = 2.5 * this->getWisdom() + (enemyChar.getHealth()/6 - enemyChar.getDefense()/6);
//     if(damage > 0){
//         enemyChar.appendCurrentHealth((damage * -1));
//     }
// }