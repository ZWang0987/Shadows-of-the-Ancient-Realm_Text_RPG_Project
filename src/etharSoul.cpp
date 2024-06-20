#include "../header/etharSoul.hpp"
//name,health,strength,wisdom, defnese, speed, dropped gold,dropped xp

etharSoul::etharSoul()
    : EnemyCharacter("Ethar Soul", "Haunted", 25, 6, 6, 1, 10, 5 , 15 ) {}

etharSoul::~etharSoul(){

    // Nothing to clean up, so the destructor is empty

}

// void etharSoul::Agony(UserCharacter& userChar){
//     double damage = 3;
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }