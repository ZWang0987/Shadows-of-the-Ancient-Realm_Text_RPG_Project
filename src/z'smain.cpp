#include <string>
#include <iostream>
using namespace std;


#include "../src/character.cpp"
#include "../src/userCharacter.cpp"
#include "../src/enemyCharacter.cpp"
#include "../src/Knight.cpp"
#include "../src/Mage.cpp"
#include "../src/Archer.cpp"
#include "../src/Rogue.cpp"
#include "../src/Voidling.cpp"
#include "../src/KaiSon.cpp"
#include "../src/battleDriver.cpp"


// void battle(Knigh* UserChar, Voidling* EnemyChar){

//     UserChar->slash(*EnemyChar);
//     cout<<"Voidling new health "<<EnemyChar->getHealth()<<endl;
//     EnemyChar->voidBite(*UserChar);
//     cout<<"Knight new health "<<UserChar->getHealth()<<endl;

// }


int main(){

    //after user makes character
    cout<<"What is your name"<<endl;
    string userName;
    cin>>userName;

    cout<<"What class are you picking(Enter 1, 2, 3, or 4)"<<endl;
    cout<<"1.Knight"<<endl;
    cout<<"2.Rogue"<<endl;
    cout<<"3.Archer"<<endl;
    cout<<"4.Mage"<<endl;
    int classSelect=0;
    cin>>classSelect;
    while (cin.fail() || classSelect < 1 || classSelect > 4) {
        cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
        cin.clear(); 
        cin>>classSelect;
    }

    UserCharacter* userChar = nullptr;
    if(classSelect==1){

        userChar = new UserCharacter(userName, "Knight", 100, 6, 1, 6, 1, 0, 0);
    }else if(classSelect==2){

        userChar = new UserCharacter(userName, "Rogue", 100, 6, 1, 1, 6, 0, 0);
    }else if(classSelect==3){

        userChar = new UserCharacter(userName, "Archer", 100, 3, 2, 1, 5, 0 , 0);
    }else{

        userChar = new UserCharacter(userName, "Mage", 100, 1, 10, 1, 1, 0 , 0);
    }


    Voidling* tempEnemyVoidLing=new Voidling();
    KaiSon* tempEnemyKaiSon=new KaiSon();

                //enemy                                     //enemy //user    //enemy
    BattleDriver<Voidling>* tempBattle1 = new BattleDriver<Voidling>(userChar,tempEnemyVoidLing);
    tempBattle1->startBattle();
    BattleDriver<KaiSon>* tempBattle2 = new BattleDriver<KaiSon>(userChar,tempEnemyKaiSon);
    tempBattle2->startBattle();
    


    // if(ActualUserClass=="Knight"){
    //     BattleDriver<Knight,Voidling>* tempBattle = new BattleDriver<Knight,Voidling>((tempKnightUser),tempEnemy);
    //     tempBattle->startBattle();
    // }
    // else if(ActualUserClass=="Archer"){
    //     BattleDriver<Archer,Voidling>* tempBattle = new BattleDriver<Archer,Voidling>(tempArcherUser,tempEnemy);
    //     tempBattle->startBattle();
    // }else if(ActualUserClass=="Mage"){
    //     BattleDriver<Mage,Voidling>* tempBattle = new BattleDriver<Mage,Voidling>(tempMageUser,tempEnemy);
    //     tempBattle->startBattle();
    // }else{
    //     BattleDriver<Rogue,Voidling>* tempBattle = new BattleDriver<Rogue,Voidling>(tempRogueUser,tempEnemy);
    //     tempBattle->startBattle();
    // }



    // cout<<"Knight health "<<tempUser->getHealth()<<endl;
    // cout<<"Voidling health "<<tempEnemy->getHealth()<<endl;
    // tempUser->slash(*tempEnemy);
    // cout<<"Voidling new health "<<tempEnemy->getHealth()<<endl;
    // tempEnemy->voidBite(*tempUser);
    // cout<<"Knight new health "<<tempUser->getHealth()<<endl;


    return 0;
}
