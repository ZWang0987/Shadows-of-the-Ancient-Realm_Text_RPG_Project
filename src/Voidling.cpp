#include "../header/Voidling.hpp"

Voidling::Voidling()
    : EnemyCharacter("Voidling", "Weakling", 25, 3, 3, 3, 2, 5 , 15 ) {}

Voidling::~Voidling() {
    // Nothing to clean up, so the destructor is empty
}
// void Voidling::voidBite(UserCharacter& userChar) { 
//     double damage = 0;
//     damage = 1 + (this->getStrength()*1.5);
//      if(damage > 0){
//         userChar.appendCurrentHealth((damage * -1));
//     }
// }