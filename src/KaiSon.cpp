#include "../header/KaiSon.hpp"
//name,health,strength,wisdom, defnese, speed, dropped gold,dropped xp

KaiSon::KaiSon()
    : EnemyCharacter("Kaison", "Diallos' Knight Of 1", 100, 5, 20, 5, 20, 70 , 100 ) {}
    
KaiSon::~KaiSon(){

// Nothing to clean up, so the destructor is empty

}
// void KaiSon::voidSeaker(UserCharacter& userChar){
//     double damage = 5 + (this->getWisdom()*1.5 - userChar.getDefense()*userChar.getLevel());
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void KaiSon::voidRain(UserCharacter& userChar){
//     double damage = 0;
//     damage =  5 + (this->getWisdom()*1.5 - userChar.getWisdom()*userChar.getLevel());
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void KaiSon::voidShift(UserCharacter& userChar){
//     double damage = 0;
//     damage = this->getSpeed() - userChar.getSpeed();
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void KaiSon::voidSurge(UserCharacter& userChar){
//     double damage = 0;
//     damage = 3 + userChar.getHealth()/8;
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }