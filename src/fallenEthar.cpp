#include "../header/fallenEthar.hpp"
//name,health,strength,wisdom, defnese, speed, dropped gold,dropped xp

fallenEthar::fallenEthar()
    : EnemyCharacter("Fallen Ethar", "The Prisoner", 50, 4, 4, 10, 3, 10, 40 ) {}
    
fallenEthar::~fallenEthar(){
    // Nothing to clean up, so the destructor is empty
}
// void fallenEthar::lightStrike(UserCharacter& userChar){
//     double damage = 0;
//     damage = userChar.getStrength()-5;
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }

// void fallenEthar::darkStrike(UserCharacter& userChar){
//     double damage = 0;
//     damage =  userChar.getWisdom()-5;
//     if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }