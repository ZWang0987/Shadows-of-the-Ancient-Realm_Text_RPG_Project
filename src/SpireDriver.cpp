#include "../header/SpireDriver.hpp"
#include "../src/Ragnar.cpp"
#include "../src/Dellio.cpp"
#include "../src/etharSoul.cpp"
#include "../src/fallenEthar.cpp"
#include "../src/VoidWalker.cpp"
#include "../src/Diallos.cpp"
#include "../src/character.cpp"
#include "../src/userCharacter.cpp"
#include "../src/enemyCharacter.cpp"
#include "../src/Voidling.cpp"
#include "../src/KaiSon.cpp"
#include "../src/battleDriver.cpp"

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T1>
SpireDriver<T1>::SpireDriver(T1* character): currentSpireLevel(1), hero(character) {}

template <typename T1>
SpireDriver<T1>::~SpireDriver() {
    delete hero;
}

template<typename T1>
void SpireDriver<T1>::Spire_Runner() {
    while(currentSpireLevel < 26) {
        cout<<"-------------------------------------------------"<<endl;
        cout << "Spire Level " << currentSpireLevel << endl;
        if(currentSpireLevel == 25) {
            finalBossRoom();
        }
        else if(currentSpireLevel == 10 || currentSpireLevel == 15 || currentSpireLevel == 20) {
            miniBossRoom();
        }
        else {
            printUserStats();
            cout << "Would you like to check your inventory? 1 for yes or 2 for no " << endl;
            int choice;
            cin >> choice;
            while((choice != 1 && choice != 2) || cin.fail()) {
                cout << "Invalid selection, please enter 1 for yes or 2 for no" << endl;
                cin.clear();
                cin.ignore();
                cin >> choice;
            }
            if(choice == 1) {
                hero->useItem();
            }
            vector<int> roomOptionsList = printNextSpireLevelOption();
            int userSelection;
            cin >> userSelection;
            while((userSelection != 1 && userSelection != 2 && userSelection != 3) || cin.fail()) {
                cout << "Invalid selection, please choose 1, 2, or 3" << endl;
                cin.clear();
                cin.ignore();
                cin >> userSelection;
            }
            if(roomOptionsList[userSelection - 1] == 1) {

                vendorRoom();
            }
            else if(roomOptionsList[userSelection - 1] == 2) {
                lootRoom();
            }
            else if(roomOptionsList[userSelection - 1] == 3) {
                loreRoom();
            }
            else if(roomOptionsList[userSelection - 1] == 4) {
                basicCombatEncounter();
            }
            else if(roomOptionsList[userSelection - 1] == 5) {
                restingRoom();
            }
            
        }
        if(hero->getHealth() <=0) {
            cout << "You have Died... Diallos reigns victorious against the one hero who stood a chance against him." << endl;
            cout << "Diallos absored the Hero's soul, and with it came their power. Diallos became unstoppable and made the entire continent of Azeroth suffer his wrath." << endl;    
            cout << "With no other hero in sight, Diallos eventually became strong enough to consume the world with his corruption and power.." << endl;
            cout << "GAME OVER" << endl;
            break;
        }

        hero->appendXP(50);
        if(hero->getXp() >= 100) {
            cout << "You have leveled up!" << endl;
            hero->levelUp();
        }
        currentSpireLevel++;

    }
    cout << "Congratulations! You have defeated Diallos, the Ruined King!" << endl;
    cout << "With Diallos defeated, peace is restored to the ancient realm of Ethar." << endl;    
    cout << "The souls of the imprisoned Etharians are freed from their torment, and the land begins to heal." << endl;
    cout << "As the hero who vanquished the great evil, you are celebrated as a savior throughout Azeroth." << endl;
    cout << "Your name will be remembered for generations to come as the one who brought hope and light back to the world." << endl;
    cout << "Thank you for playing Shadows Of the Ancient Realm!" << endl;
}

template<typename T1>
vector<int> SpireDriver<T1>::printNextSpireLevelOption() {
    srand(time(0));
    vector<int>listOfRoomOptions;
    string allRoomOptions;
    string roomOption;
    for(int i = 0; i < 3; i++) {
        if(i == 0) {
            allRoomOptions += "Go Left: ";
        }
        else if(i == 1) {
            allRoomOptions += "Go Middle:  ";
        }
        else if(i == 2) {
            allRoomOptions += "Go Right: ";
        }

        int randomEventChooser = (rand()%6) + 1;
        if(randomEventChooser == 1) {
            roomOption = "Meet a shop vendor \n";
            listOfRoomOptions.push_back(1);
        }
        else if(randomEventChooser == 2) {
            roomOption = "Enter a loot room \n";
            listOfRoomOptions.push_back(2);
        }
        else if(randomEventChooser == 3) {
            roomOption = "Meet an ally \n";
            listOfRoomOptions.push_back(3);
        }
        else if(randomEventChooser == 4 || randomEventChooser == 6) {
            roomOption = "Encounter an enemy \n";
            listOfRoomOptions.push_back(4);
        }
        else if(randomEventChooser == 5) {
            roomOption = "Go to a resting room \n";
            listOfRoomOptions.push_back(5);
        }
        allRoomOptions += roomOption;
    }
    cout << "Please choose an option: \n" << "------------------------------------------------- \n" << allRoomOptions << endl;
    cout << "Click 1 to go left, 2 to go middle, 3 to go right" << endl;
    cout << "------------------------------------------------- \n";
    return listOfRoomOptions;
}

template<typename T1>
void SpireDriver<T1>::printUserStats() {
    cout << "---------PLAYER STATS----------" << endl;
    cout << "Health: " << hero->getHealth() << endl;
    cout << "Strength: " << hero->getStrength() << endl;
    cout << "Widom: " << hero->getWisdom() << endl;
    cout << "Defense: " << hero->getDefense() << endl;
    cout << "Speed: " << hero->getSpeed() << endl;
    cout << "Current Level: " << hero->getLevel() << endl;
    cout << "Current XP: " << hero->getXp() << endl;
    cout << "Current Gold: " << hero->getGold() << endl;
}

template<typename T1>
void SpireDriver<T1>::printUserInventory() {
    cout << "---------USER INVENTORY----------" << endl;
    cout << "items: ";
    hero->printInventory();
}

template<typename T1>
void SpireDriver<T1>::restingRoom() {
    srand(time(0));
    int randomMessageChooser = (rand()*5) + 1;
    if(randomMessageChooser == 1) {
        cout << "Welcome to the resting room. Feel free to take a little break and recover from all your battles." << endl;  
    }
    else if(randomMessageChooser == 2) {
        cout << "Greetings! Please take some time to heal and prepare for the fights to come." << endl;
    }
    else if(randomMessageChooser == 3) {
        cout << "Woah there! You look like you need a break. Have a seat." << endl;
    }
    else if(randomMessageChooser == 4) {
        cout << "Take a moment and recover friend, you look like you need it." << endl;
    }
    else if(randomMessageChooser == 5) {   
        cout << "Time to heal! Take a little break and recuperate." << endl;
    }

    if(hero->getHealth() == hero->getMaxHealth()) {
        cout <<"Looks like your health is already full. Time to move on!" << endl;
    }
    else if (hero->getHealth() < hero->getMaxHealth()) {
        int healAmount = hero->getMaxHealth()/4;
        if(hero->getHealth() + healAmount >= hero->getMaxHealth()) {
            healAmount = hero->getMaxHealth() - hero->getHealth();
            hero->appendCurrentHealth(healAmount);
            cout << "You healed to full health!" << endl;
        }
        else{
            hero->appendCurrentHealth(healAmount);
            cout << "You healed " << healAmount << " health!" << endl;

        }
    }
}

template<typename T1>
void SpireDriver<T1>::lootRoom() {
    cout << "------------------------------------------------- \n";
    cout << "You have entered the Loot Room and there is a loot chest in front of you" << endl;
    cout << "Would you like to open the chest? Select 1 for Yes or 2 for No" << endl;
    int userChoice;
    cin >> userChoice;
    while((userChoice != 1 && userChoice != 2) || cin.fail()) {
        cout << "Invalid choice, please choose 1 for Yes or 2 for No" << endl;
        cin.clear();
        cin.ignore();
        cin >> userChoice;
    }
    if(userChoice == 2) {
        cout << "You have chosen not to open the chest you can now continue" << endl;
    } 
    else if(userChoice == 1) {
        srand(time(0));
        int chestOutcome = (rand() % 4) + 1;
        if(chestOutcome == 1 || chestOutcome == 2) {
            if(hero->getMaxHealth() - hero->getHealth() < hero->getMaxHealth() * .8) {
                int healAmount = hero->getMaxHealth()/4;
                if(hero->getHealth() + healAmount >= hero->getMaxHealth()) {
                    healAmount = hero->getMaxHealth() - hero->getHealth();
                    hero->appendCurrentHealth(healAmount);
                    cout << "You received a healing potion that restored your health!" << endl;
                }
                else{
                    hero->appendCurrentHealth(healAmount);
                    cout << "You received a healing potion that increased your current health by " << healAmount << "!" << endl;
                }
                
            }
            else {
                hero->appendStrength(1);
                hero->appendWisdom(1.0);
                hero->appendSpeed(1.0);
                hero->appendDefense(1.0);
                cout << "You have received a magic potion that has increased all your stats by 5 points" << endl;
            }
            cout << "------------------------------------------------- \n";
        }
        else if(chestOutcome == 3 || chestOutcome == 4) {
            cout << "OH NO, the chest was a trap. An enemy mimic is hiding in there and you will now have to fight it" << endl;
            basicCombatEncounter();
        }
    }
}

static int visits = 1;
template<typename T1>
void SpireDriver<T1>::loreRoom() {
    if(visits == 1) {
        cout << "Greetings. My name is Mortis. Would you like to know a little secret?"<<endl;
        cout<<"No? Too bad. I'm gunna say it anyway. When I was younger,"<<endl;
        cout<<"I loved this realm. It was beautiful. But ever since the Ruthless Ruined"<<endl;
        cout<<"King took over, life here has sucked.I'm really hoping that one day, there is a "<<endl;
        cout<<"hero out there. Someone who will stand up to this tyranny and unjustness and fights"<<endl;
        cout<<"for the better of the Ether realm. But until that day comes, we are stuck here." << endl;
        cout<<"Living a horrible life. Anyways... I hope your day is going better! Haha.. ha.. " << endl;
    }
    else if(visits == 2) {
        cout << "Hello. My name is Ptehr. I was the one who built the spire with Jshiu."<<endl;
        cout << "Jshiu and I poured our heart and soul into this."<<endl;
        cout << "...Sure we got it done in a day, but it was honest work."<<endl;
        cout << "Anyways, this spire use to look a lot less evil until Diallos took over"<<endl;
    }
    else if(visits == 3) {
        cout << "Yoooo what's up? My name's Apaya. I use to be a librarian here."<< endl;
        cout << "Now im just a reguar Etharian dude under the rule of Diallos."<< endl;
        cout << "Do I enjoy it? Hell No, but it comes with its perks...At least we get hot water."<< endl;
        cout << "Anyways I heard you were here to save us. If you do ill make sure to write you."<< endl;
        cout << "down in the records."<< endl;
    }   
    else if(visits == 4) {
        cout << "SUP SUP, I'm zwang...I use to train the army here. You look pretty" << endl;
        cout << "strong, maybe even strong enough to defeat Diallos. Watch out though" << endl;
        cout << "Dellio is his brother is really bulky like a tank." << endl;
        cout << "Ragnar and KaiSon are their most loyal servants." << endl;
        cout << "Ragnar like to hit things and get hit." << endl;
        cout << "Kaison is a fast glass cannon." << endl;
        cout << "Goodluck champ, you got this." << endl;
    }
    else if(visits == 5) {
        cout << "WOAHHH, GET OUT IM SHOWERING." << endl;
        
    }
    else {
        cout << "sadfasweqasdfrgwethcklvjnoiasrtioerghndfsknvasdf" << endl;
        cout << "ocivjaoisuehrqwiohbvasiochvaisdfhbwioeqhfbosdyvs" << endl;
        cout << "plsadcokawemfinvoiaernfoapudvhiohdfnvaiohrbfosdr" << endl;
        cout << "hmm you can't read or understand this text" << endl;
    }
    visits++;
}

template<typename T1>
void SpireDriver<T1>::vendorRoom() {
    cout << "------------------------------------------------- \n";

    cout << "Welcome to my shop! My name is Pippendopolous. Here is my selection of spectacular items: " << endl;
    string items[] = {"Health pot", "Health buff", "Speed boost", "Wisdom enchancement", "Strength buff"};
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << items[i] << " - 10 gold" << endl;
    }
    
    cout << "Which item would you like to purchase? (6 to leave)" << endl;
    int choice;
    cin >> choice;
    while((choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) || cin.fail()) {
        cout << "Invalid selection, please choose 1-6" << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    cout << endl;
    if(choice == 1) {
        if(hero->getGold() < 10) {
            cout << "Sorry you cannot afford this item." << endl;
        }
        else {
            cout << "Great choice! Enjoy!" << endl;
            hero->addItem("Health pot");
            hero->appendGold(-10);
        }
    }
    else if (choice == 2) {
        if(hero->getGold() < 10) {
            cout << "Sorry you cannot afford this item." << endl;
        }
        else {
            cout << "Magificent selection my friend. Come back soon!" << endl;
            hero->addItem("Health buff");
            hero->appendGold(-10);
        }
    }
    else if (choice == 3) {
        if(hero->getGold() < 10) {
            cout << "Sorry you cannot afford this item." << endl;
        }
        else {
            cout << "Thank you, come again!" << endl;
            hero->addItem("Speed boost");
            hero->appendGold(-10);
        }
    }
    else if (choice == 4) {
        if(hero->getGold() < 10) {
            cout << "Sorry you cannot afford this item." << endl;
        }
        else {
            cout << "Ooooo, you want to be smarter huh?" << endl;
            hero->addItem("Wisdom enhancement");
            hero->appendGold(-10);
        }
    }
    else if (choice == 5) {
        if(hero->getGold() < 10) {
            cout << "Sorry you cannot afford this item." << endl;
        }
        else {
            cout << "You are a strong one eh? Haha!" << endl;
            hero->addItem("Strength buff");
            hero->appendGold(-10);
        }
    }
    else {
        cout <<"You don't want anything? That's a shame. Hopefully you will come back and give me some business! Hahaha" << endl;
    }

}

template<typename T1>
void SpireDriver<T1>::basicCombatEncounter() {
    srand(time(0));
    int enemySelection = (rand()%4) + 1;
    if(enemySelection == 1) {
        etharSoul* opponent = new etharSoul();
        BattleDriver<etharSoul>* battle = new BattleDriver<etharSoul>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
    else if(enemySelection == 2) {
        fallenEthar* opponent = new fallenEthar();
        BattleDriver<fallenEthar>* battle = new BattleDriver<fallenEthar>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
    else if(enemySelection == 3) {
        VoidWalker* opponent = new VoidWalker();
        BattleDriver<VoidWalker>* battle = new BattleDriver<VoidWalker>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
    else if(enemySelection == 4) {
        Voidling* opponent = new Voidling();
        BattleDriver<Voidling>* battle = new BattleDriver<Voidling>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
}

template<typename T1>
void SpireDriver<T1>::miniBossRoom() {
    if(currentSpireLevel == 10) {
        Ragnar* opponent = new Ragnar();
        BattleDriver<Ragnar>* battle = new BattleDriver<Ragnar>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
    else if(currentSpireLevel == 15) {
        KaiSon* opponent = new KaiSon();
        BattleDriver<KaiSon>* battle = new BattleDriver<KaiSon>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
    else if(currentSpireLevel == 20) {
        Dellio* opponent = new Dellio();
        BattleDriver<Dellio>* battle = new BattleDriver<Dellio>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
}

template<typename T1>
void SpireDriver<T1>::finalBossRoom() {
    if(currentSpireLevel == 25) {
        Diallos* opponent = new Diallos();
        BattleDriver<Diallos>* battle = new BattleDriver<Diallos>(hero, opponent);
        battle->startBattle();
        delete opponent;
        delete battle;
    }
}

template<typename T1>
void SpireDriver<T1>::setSpireLevel(int level) {
    currentSpireLevel = level;
}