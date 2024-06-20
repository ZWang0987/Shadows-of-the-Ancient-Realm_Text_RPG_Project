#include "../header/userCharacter.hpp"

UserCharacter::UserCharacter(const string& name, const string& className, double health, double strength, double wisdom, double defense, double speed, int gold, int xp)
    : Character(name, health, strength, wisdom, defense, speed), className(className), currentGold(gold), currentXp(xp), currentLevel(1), maxHealth(100) {
    for(int i = 0; i < 8; i++) {
        userItems[i] = "";
    }
}

UserCharacter::~UserCharacter() {
    // Nothing specific to clean up or allocated in memory
}

void UserCharacter::appendXP(const int& xp){
    currentXp += xp;
}

void UserCharacter::levelUp(){
    currentLevel++;
    static int levelUpSelection;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"You leveled up to LV:"<<getLevel()<<endl;
    cout<<"Select a stat to improve!"<<endl;
    cout<<"1.Health/MaxHealth"<<endl;
    cout<<"2.Strength"<<endl;
    cout<<"3.Wisdom"<<endl;
    cout<<"4.Defense"<<endl;
    cout<<"5.Speed"<<endl;
    cout<<"-------------------------------------------------"<<endl;

    cin>>levelUpSelection;
    while (cin.fail() || levelUpSelection < 1 || levelUpSelection > 5) {
        cout << "Invalid input. Please enter 1, 2, 3, 4, or 5." << endl;
        cin.clear();
        cin.ignore();
        cin>>levelUpSelection;
    }

    if(levelUpSelection==1){
        appendMaxHealth(2);
        appendCurrentHealth(2);
    }else if(levelUpSelection==2){
        appendStrength(2);
    }else if(levelUpSelection==3){
        appendWisdom(2);
    }else if(levelUpSelection==4){
        appendDefense(2);
    }else{
        appendSpeed(2);
    }

    currentXp+=-100;

}

void UserCharacter::appendGold(const int& gold){
    currentGold += gold;
}

int UserCharacter::getGold(){
    return currentGold;
}

int UserCharacter::getXp(){
    return currentXp;
}

int UserCharacter::getLevel(){
    return currentLevel;
}

void UserCharacter::addItem(const string& itemName){
    for(int i = 0; i < 8; i++) {
        if (userItems[i] == "") {
            userItems[i] = itemName;
            break;
        }
    }
}

void UserCharacter::removeItem(const string& itemName){
    for(int i = 0; i < 8; i++) {
        if(userItems[i] == itemName){
            userItems[i] = "";
            break;
        }
    }
}

void UserCharacter::appendMaxHealth(const double& health){
    maxHealth += health;
}

double UserCharacter::getMaxHealth() {
    return maxHealth;
}

string UserCharacter::getClassName() {
    return className;
}

void UserCharacter::printInventory(){
    cout << "---------USER INVENTORY----------" << endl;
    cout << "items: \n";
    for(int i = 0; i < 8; i++) {
        cout << i + 1  << ". " << userItems[i] << "\n";
    }
}

void UserCharacter::useItem() {
    printInventory();
    cout << "Choose an item to use or 9 to exit. " << endl;
    int choice;
    cin >> choice;
    while((choice < 1 || choice > 9 ) || cin.fail()) {
        cout << "Invalid selection, please choose 1-9" << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    if (choice == 9){
        cout << "Exiting..." << endl;
        cout<<"-------------------------------------------------"<<endl;
    }
    else if(userItems[choice - 1] == "Health pot") {
        if(getHealth() == maxHealth) {
            cout <<"Health is already full." << endl;
        }
        else if (getHealth() < maxHealth) {
            int healAmount = maxHealth/4;
            if(getHealth() + healAmount >= maxHealth) {
                healAmount = maxHealth - getHealth();
                appendCurrentHealth(healAmount);
                cout << "You healed to full health!" << endl;
                
            }
            else{
                appendCurrentHealth(healAmount);
                cout << "You healed " << healAmount << " health!" << endl;
                
            }
            removeItem("Health pot");
        }
        
    }
    else if (userItems[choice - 1] == "Health buff") {
        appendMaxHealth(10);
        removeItem("Health buff");
    }
    else if (userItems[choice - 1] == "Strength buff") {
        appendStrength(1);
        removeItem("Strength buff");
    }
    else if (userItems[choice - 1] == "Wisdom enhancement") {
        appendMaxHealth(1);
        removeItem("Wisdom enhancement");
    }
    else if (userItems[choice - 1] == "Speed boost") {
        appendStrength(1);
        removeItem("Speed boost");
    }
    

}