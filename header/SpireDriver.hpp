#ifndef SPIREDRIVER_HPP
#define SPIREDRIVER_HPP

#include <string>
#include <vector>
using namespace std;

template <typename T1>
class SpireDriver {
    private:
        int currentSpireLevel;
        T1* hero;
    public:
        SpireDriver(T1* character);
        ~SpireDriver();
        void Spire_Runner();
        vector<int> printNextSpireLevelOption();
        void printUserInventory();
        void printUserStats();
        void restingRoom();
        void lootRoom();
        void loreRoom();
        void vendorRoom();
        void basicCombatEncounter();
        void miniBossRoom();
        void finalBossRoom();
        void setSpireLevel(int level);
};

#endif