#include "../header/enemyCharacter.hpp"



EnemyCharacter::EnemyCharacter(const string& name, const string& enemyRank, double health, double strength, double wisdom, double defense, double speed, int droppedGold, int droppedXp)
    : Character(name, health, strength, wisdom, defense, speed), currentGold(droppedGold), currentXp(droppedXp), enemyRank(enemyRank) {
}

EnemyCharacter::~EnemyCharacter() {
    // Nothing specific to clean up or allocated in memory
}

int EnemyCharacter::getDroppedXp() {
    return currentXp;
}
int EnemyCharacter::getDroppedGold() {
    return currentGold;
}
void EnemyCharacter::appendDroppedXp(const int& xp) {
    currentXp += xp;
}
void EnemyCharacter::appendDroppedGold(const int& gold) {
    currentGold += gold;
}
string EnemyCharacter::getEnemyRank() {
    return enemyRank;
}