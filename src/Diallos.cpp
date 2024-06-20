#include "../header/Diallos.hpp"
//name,health,strength,wisdom, defnese, speed, dropped gold,dropped xp

Diallos::Diallos()
    : EnemyCharacter("Diallos", "Ruined King", 200, 20, 20, 20, 20, 100 , 100 ) {}

Diallos::~Diallos(){

    // Nothing to clean up, so the destructor is empty

}

// void Diallos::Hellfire(UserCharacter& userChar){
//     double damage = 5 + (this->getStrength()*1.5 - userChar.getDefense()*userChar.getLevel());
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Diallos::nullSphere(UserCharacter& userChar){
//     double damage = 0;
//     damage =  10 + (this->getWisdom()*1.5 - userChar.getWisdom()*userChar.getLevel());
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Diallos::blackDeath(UserCharacter& userChar){
//     double damage = 0;
//     damage = 15;
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void Diallos::riftWalk(UserCharacter& userChar){
//     double damage = 0;
//     damage = 30 - userChar.getSpeed()*userChar.getLevel();
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }