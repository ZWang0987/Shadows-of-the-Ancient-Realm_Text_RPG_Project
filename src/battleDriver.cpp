// #include "../src/character.cpp"
// #include "../src/userCharacter.cpp"
// #include "../src/enemyCharacter.cpp"
// #include "../src/Archer.cpp"
// #include "../src/Dellio.cpp"
// #include "../src/Diallos.cpp"
// #include "../src/etharSoul.cpp"
// #include "../src/fallenEthar.cpp"
// #include "../src/KaiSon.cpp"
// #include "../src/Knight.cpp"
// #include "../src/Mage.cpp"
// #include "../src/Ragnar.cpp"
// #include "../src/Rogue.cpp"
// #include "../src/Voidling.cpp"
// #include "../src/VoidWalker.cpp"
#include "../header/battleDriver.hpp"
#include <iostream>

template <typename T1>
void BattleDriver<T1>::startBattle() {

    static int turnCounter=0; 

    outputFighters();

    if(userCharPointer->getSpeed() < enemyCharPointer->getSpeed()){
        turnCounter = 1;
    }




    //will go until someone dies
    while(userCharPointer->getHealth()>0 && enemyCharPointer->getHealth() >0){

        //user turn
        if(turnCounter%2 == 0){

            cout<<"-------------------------------------------------"<<endl;
            cout << "Enter 1 to continue to your turn." << endl;
            cout<<"-------------------------------------------------"<<endl;
            cin>>userMoveSelection;
            while (cin.fail() || userMoveSelection != 1) {
                    cout << "Invalid input. Please enter 1." << endl;
                    cin.clear(); 
                    cin.ignore();
                    cin>>userMoveSelection;
            }
            
            outputFighterHealth();
            //section outputs userturns
            outputUserChoices();

            //ask for user input until 1-4
            cin>>userMoveSelection;
            while (cin.fail() || userMoveSelection < 1 || userMoveSelection > 4) {
                    cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
                    cin.clear(); 
                    cin.ignore();
                    cin>>userMoveSelection;
            }

            //excutes moves
            if(userCharPointer->getClassName() == "Knight"){
                inputUserKnightChoices();
            }else if(userCharPointer->getClassName() == "Rogue"){
                inputUserRogueChoices();
            }else if(userCharPointer->getClassName() == "Mage"){
                inputUserMageChoices();
            }else{
                inputUserArcherChoices();
            }

            //sets to next players turn
            turnCounter++;

        }//enemies turn 
        else{
            
            cout<<"-------------------------------------------------"<<endl;
            cout << "Enter 1 to continue to enemy's turn." << endl;
            cout<<"-------------------------------------------------"<<endl;
            cin>>userMoveSelection;
            while (cin.fail() || userMoveSelection != 1) {
                    cout << "Invalid input. Please enter 1." << endl;
                    cin.clear(); 
                    cin.ignore();
                    cin>>userMoveSelection;
            }

            //random between 1 and 4
            enemyMoveSelection= rand()%(4-1) + 1;    

            if(enemyCharPointer->getName() == "Voidling"){
                enemyVoidlingChoices();
            }else if(enemyCharPointer->getName() == "Ethar Soul"){
                enemyEtharSoulChoices();
            }else if(enemyCharPointer->getName() == "Void Walker"){
                enemyVoidWalkerChoices();
            }else if(enemyCharPointer->getName() == "Fallen Ethar"){
                enemyFallenEtharChoices();
            }else if(enemyCharPointer->getName() == "Kaison"){
                enemyKaiSonChoices();
            }else if(enemyCharPointer->getName() == "Ragnar"){
                enemyRagnarChoices();
            }else if(enemyCharPointer->getName() == "Dellio"){
                enemyDellioChoices();
            }else //(enemyCharPointer->getName() == "Diallos")
            {
                enemyDiallosChoices();
            }

            turnCounter++;

        }
    }

    endBattleWinner();
    
}

template <typename T1>
void BattleDriver<T1>::endBattleWinner() {
    if(userCharPointer->getHealth()<=0){
        cout<<"-------------------------------------------------"<<endl;
        cout << "You were slain by " <<enemyCharPointer->getEnemyRank()<<" "<<enemyCharPointer->getName()<< endl;
        cout<<"-------------------------------------------------"<<endl;
    }else{
        cout<<"-------------------------------------------------"<<endl;
        cout<<"You slain " <<enemyCharPointer->getEnemyRank()<<" "<<enemyCharPointer->getName()<< endl;
        cout<<"You gained "<<enemyCharPointer->getDroppedXp()<<" XP and "<<enemyCharPointer->getDroppedGold()<<" gold"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        userCharPointer->appendXP(enemyCharPointer->getDroppedXp());
        userCharPointer->appendGold(enemyCharPointer->getDroppedGold());
        while(userCharPointer->getXp()>=100){
            userCharPointer->levelUp();
        }
    }
}

template <typename T1>
void BattleDriver<T1>::outputFighters() {
    cout<<"-------------------------------------------------"<<endl;
    cout<<"You now face "<<enemyCharPointer->getEnemyRank()<<" "<<enemyCharPointer->getName()<<"."<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

template <typename T1>
void BattleDriver<T1>::outputFighterHealth() {
    cout<<"-------------------------------------------------"<<endl;
    cout<<"LV:"<<userCharPointer->getLevel()<<" "<<userCharPointer->getName()<<"'s Health:"<<userCharPointer->getHealth()<<"."<<endl;
    cout<<enemyCharPointer->getEnemyRank()<<" "<<enemyCharPointer->getName()<<"'s Health:"<<enemyCharPointer->getHealth()<<"."<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

template <typename T1>
void BattleDriver<T1>::outputUserChoices() {
    // cout<<"-------------------------------------------------"<<endl;
    cout<<"Its your turn, select a move!"<<endl;
    if(userCharPointer->getClassName() == "Knight"){
        cout<<"1.Slash"<<endl;
        cout<<"2.Sheid Slam"<<endl;
        cout<<"3.Whirlwind"<<endl;
        cout<<"4.Thunder Clap"<<endl;
    }else if(userCharPointer->getClassName() == "Rogue"){
        cout<<"1.Sneaky Dagger"<<endl;
        cout<<"2.Shadow Step"<<endl;
        cout<<"3.Sinister Slash"<<endl;
        cout<<"4.Eviscerate"<<endl;
    }else if(userCharPointer->getClassName() == "Mage"){
        cout<<"1.Fireball"<<endl;
        cout<<"2.Frostbolt"<<endl;
        cout<<"3.Arcane Blast"<<endl;
        cout<<"4.Elemental Strike"<<endl;
    }else if(userCharPointer->getClassName() == "Archer"){
        cout<<"1.Explosive Bolt"<<endl;
        cout<<"2.Piercing Arrow"<<endl;
        cout<<"3.Volley"<<endl;
        cout<<"4.Arcane Shot"<<endl;
    }
    cout<<"-------------------------------------------------"<<endl;
}

template <typename T1>
void BattleDriver<T1>::inputUserKnightChoices() {
    if(userMoveSelection==1){
        damage = 3 * userCharPointer->getLevel() + (userCharPointer->getStrength() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Slash dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Slash did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==2){
        damage = 3 * userCharPointer->getLevel() + (userCharPointer->getDefense() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Shield Slam dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Shield Slam did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==3){
        damage = 6 * userCharPointer->getLevel() + (userCharPointer->getStrength() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Whirlwind dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Whirlwind did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = 4 * userCharPointer->getLevel() + (userCharPointer->getStrength());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Thunder Clap dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Thunder Clap did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }

}

template <typename T1>
void BattleDriver<T1>::inputUserRogueChoices() {
    if(userMoveSelection==1){
        damage = 4.5 * userCharPointer->getLevel() + (userCharPointer->getSpeed() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Sneaky Dagger dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Sneaky Dagger did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==2){
        damage = 2.5 * userCharPointer->getSpeed();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Shadow Step dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Shadow Step did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==3){
        damage = 3 * userCharPointer->getLevel() + (userCharPointer->getStrength() + userCharPointer->getSpeed() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Sinister Slash dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Sinister Slash did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage =  userCharPointer->getLevel() * (userCharPointer->getStrength()/2) + userCharPointer->getSpeed();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Eviscerate dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Eviscerate did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::inputUserMageChoices() {
    if(userMoveSelection==1){
        damage = 3 * userCharPointer->getLevel() + (userCharPointer->getWisdom() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Fireball dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Fireball did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==2){
        damage = 2 * userCharPointer->getLevel() + (enemyCharPointer->getHealth()/8);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Frostbolt dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Frostbolt did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==3){
        damage = 1.5 * userCharPointer->getLevel() + (userCharPointer->getWisdom() + (enemyCharPointer->getHealth()/4));
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Arcane Blast dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Arcane Blast did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = userCharPointer->getLevel() * userCharPointer->getWisdom();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Elemental Strike dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Elemental Strike did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::inputUserArcherChoices() {
    if(userMoveSelection==1){
        damage = 2.5 * userCharPointer->getLevel() + (userCharPointer->getStrength() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Explosive Bolt dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Explosive Bolt did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==2){
        damage = userCharPointer->getLevel() * 2;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Piercing Arrow dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Piercing Arrow did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(userMoveSelection==3){
        damage = 1.5 * userCharPointer->getLevel() + (userCharPointer->getStrength() + userCharPointer->getSpeed() - enemyCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Volley dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Volley did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = 2.5 * userCharPointer->getWisdom() + (enemyCharPointer->getHealth()/6 - enemyCharPointer->getDefense()/6);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Arcane Shot dealt "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Arcane Shot did 0 damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::enemyVoidlingChoices() {
    damage = 1 + (enemyCharPointer->getStrength()*1.5);
    if(damage > 0){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Voidling void bit you for "<<damage<<" damage."<<endl;
        cout<<"-------------------------------------------------"<<endl;
        userCharPointer->appendCurrentHealth((damage * -1));
    }else{
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Voidling did no damage to you."<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }
}

template <typename T1>
void BattleDriver<T1>::enemyEtharSoulChoices() {
    damage = 3;
    if(damage > 0){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Ethar Soul agoinizes you for "<<damage<<" damage."<<endl;
        cout<<"-------------------------------------------------"<<endl;
        userCharPointer->appendCurrentHealth((damage * -1));
    }else{
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Ethar Soul did no damage to you."<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }
}

template <typename T1>
void BattleDriver<T1>::enemyVoidWalkerChoices() {
    if(enemyMoveSelection%2==0){
        damage = 1 + (enemyCharPointer->getStrength() * 1.5) - (userCharPointer->getDefense() * 0.5) ;
    if(damage > 0){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Void Walker corrupts you for "<<damage<<" damage."<<endl;
        cout<<"-------------------------------------------------"<<endl;
        userCharPointer->appendCurrentHealth((damage * -1));
    }else{
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Void Walker did no damage to you."<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }
    }else{
        damage = 1 + (enemyCharPointer->getWisdom() * 1.5) - (userCharPointer->getDefense()*0.5);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Void Walker enegy drains you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Void Walker did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::enemyFallenEtharChoices() {
    if(enemyMoveSelection%2==0){
        damage = userCharPointer->getStrength()-5;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Fallen Ethar strikes you with light for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Fallen Ethar did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage =  userCharPointer->getWisdom()-5;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Fallen Ethar strikes you with darkness for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Fallen Ethar did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::enemyKaiSonChoices() {
    if(enemyMoveSelection==1){
        damage = 5 + (enemyCharPointer->getWisdom()*1.5 - userCharPointer->getDefense()-3);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon's void seaker hits you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==2){
        damage =  5 + (enemyCharPointer->getWisdom() - userCharPointer->getWisdom()-3);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon's void rain hits you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==3){
        damage = enemyCharPointer->getSpeed() - userCharPointer->getSpeed();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon void shifts you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = 3 + userCharPointer->getHealth()/8;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon void surges you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"KaiSon did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::enemyRagnarChoices() {
    if(enemyMoveSelection==1){
        damage = 2.5 + (enemyCharPointer->getStrength() * 1.5) - userCharPointer->getDefense();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar overheats dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==2){
        damage = 3.0 + (enemyCharPointer->getWisdom() * 1.5) - userCharPointer->getDefense() ;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar's casts pyroclasm dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==3){
        damage = (1.0 + (enemyCharPointer->getStrength() * 0.5) - userCharPointer->getDefense())*2;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar uses flamethrower dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = 5.0 + (enemyCharPointer->getStrength() * 3.0) - userCharPointer->getDefense()*1.5;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar fire slams you dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth(damage * -1);
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar took "<<damage/4<<" recoil damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth(damage * -1/4);
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Ragnar did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::enemyDellioChoices() {
    if(enemyMoveSelection==1){
        damage = 2.5 + (userCharPointer->getStrength()*1.5);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio slashes his nether blade dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==2){
        damage = 3+ (enemyCharPointer->getStrength()*2 - userCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio's inferno burns you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==3){
        damage = (1.0 + (userCharPointer->getStrength() * 0.5)) * 3 ; 
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio's rain of fire hits you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = (7.0 + ((enemyCharPointer->getStrength()-userCharPointer->getStrength())) * 2.0);
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio casts blazing death dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth(damage * -1);
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio took "<<damage/4<<" recoil damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            enemyCharPointer->appendCurrentHealth(damage * -1/4);
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Dellio did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

template <typename T1>
void BattleDriver<T1>::enemyDiallosChoices() {
    if(enemyMoveSelection==1){
        damage = 5 + (enemyCharPointer->getStrength() - userCharPointer->getDefense());
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos' hellfire burns you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==2){
        damage =  10 + enemyCharPointer->getWisdom() - userCharPointer->getWisdom();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos' null sphere hit you for "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else if(enemyMoveSelection==3){
        damage = 10;
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos' cast black death dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth((damage * -1));
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos' did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }else{
        damage = 15 - userCharPointer->getSpeed();
        if(damage > 0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos' rift walks dealing "<<damage<<" damage."<<endl;
            cout<<"-------------------------------------------------"<<endl;
            userCharPointer->appendCurrentHealth(damage * -1);
        }else{
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Diallos did no damage to you."<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }
    }
}

