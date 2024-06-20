#include "../header/storyDriver.hpp"
#include <iostream>
#include <string>
using namespace std;


template <typename T1>
void StoryDriver<T1>::startStory() {
    //Start story by giving backstory on Diallos and the Ancient Realm
    printBorder();
    cout << "Welcome to Shadows Of the Ancient Realm! Let us begin this tale..." << endl;
    printBorder();
    cout << "In the ancient realm of Aldoria, King Diallos ruled with kindness and bravery." << endl;
    cout << "But beneath this noble facade, he had mischievous ambitions to conquer the rest of the continent of Azeroth. " << endl;
    printBorder();
    continueStory();
    printBorder();
    cout << "Driven by his ambition, Diallos found an ancient artifact from centuries ago, the crown of the fallen. " << endl;
    cout << "This crown was said to hold tremendous power to whoever wore it" << endl;
    printBorder();
    continueStory();
    printBorder();
    cout << "Diallos then slipped the crown onto his head, where he was possessed by the ancient void king" << endl;
    cout << ",fully corrupting Diallos to how he is known now as the Ruined King." << endl;
    printBorder();
    continueStory();
    printBorder();
    cout << "The crown granted Diallos the ancient powers of the void king" << endl;
    cout << ",which he used to corrupt his people, turning them into his massive army." << endl;
    printBorder();
    continueStory();
    printBorder();
    cout << "Years after conquering the neighboring towns and kingdoms, Diallos has become one of the strongest rulers in all of Azeroth." << endl;
    cout << "While his army is out doing his bidding, he sits at the top of a spire, looking over his land." << endl;
    printBorder();
    continueStory();
    printBorder();
    cout << "No one has been brave enough to step up and defeat Diallos " << endl;
    cout << ",until an unexpected hero emerges to take on the challenge of scaling the spire and finally confronting the Ruined King." << endl;
    printBorder();
    continueStory();
    printBorder();
    outputNextStorySection();
}

template<typename T1>
void StoryDriver<T1>::printBorder() {
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

template<typename T1>
int StoryDriver<T1>::getResponse() {
    cout << "Please enter your response: " << endl;
    cin >> this->userResponse;
    while (cin.fail() or this->userResponse < 1 or this->userResponse > 2) {
                    cout << "Invalid input. Please enter 1 or 2" << endl;
                    cin.clear(); 
                    cin.ignore();
                    cin>>this->userResponse;
            }
    return this->userResponse;
}

template<typename T1>
int StoryDriver<T1>::continueStory() {
    cout << "Please press 1 to continue: " << endl;
    cin >> this->userResponse;
    while (cin.fail() or this->userResponse < 1 or this->userResponse > 1) {
                    cout << "Invalid input. Please enter 1:" << endl;
                    cin.clear(); 
                    cin.ignore();
                    cin>>this->userResponse;
            }
    return this->userResponse;
}

template<typename T1>
void StoryDriver<T1>::outputNextStorySection() {
    switch (currChapter) {
        case 1:
           printBorder(); 
           cout << "Chapter 1: Start of the Hero's Journey" << endl << endl;
           printBorder();
           printBackstory();
           continueStory();
           currChapter++;
        case 2:
            printBorder();
            cout << "Chapter 2: Portal to the Ancient Realm" << endl << endl;
            printBorder();
            cout << "You rush to the cave , where you see the eerie entrance." << endl;
            cout << "Once you are inside, you see no sign of the archaeologists." << endl;
            printBorder();
            continueStory();
            cout << "you find what seems like this is one of the few artifacts that have been uncovered by the archaeologists." << endl;
            cout << endl;
            printBorder();
            caveItemSelection();
            printBorder();
            continueStory();
           //Continue with story in the cave
            printBorder();
            cout << "You decide to continue traveling deeper into the cave, where the entrance suddenly collapses!" << endl;
            cout << "There is only one way to go now, so you decide to keep walking through the cave. There are two pathways to venture into the cave." << endl;
            printBorder();
            cout << "Would you like to continue on Left or Right?" << endl;
            cout << "1. Go Left." << endl;
            cout << "2. Go Right." << endl << endl;
            cout << "Please enter 1 or 2:" << endl;
            if (this->getResponse() == 1){
                cout << "You find a voidling creature! A spawn of Diallos' army.. You must fight, Get Ready!!" << endl;
                CaveBattle();
                // cout <<"You have deafeated the Voidling!!" << endl;
            }
            else {
                printBorder();
                cout << "You continue to venture through the right side of the cave..." << endl;
            }
            cin.clear();
            //Continues venturing into cave
            printBorder();
            continueStory();
             printBorder();
            cout << "You find no traces of any life, but you hear eerie whispers saying “Enter the portal…”." << endl;
            cout << "you decide to follow the voice, where you find a magical portal gleaming in a purple glow." << endl;
            printBorder();
            cout << "You enter the portal, where you are taken through the Realm of Transport!" << endl;
            cout << "You stumble upon a destroyed village, where you collapse on the ground," << endl;
            cout << "but the last thing you remember was hearing a cry for help saying “You must defeat Diallos! You are Azeroth's last hope!”" << endl;
            printBorder();
            continueStory();
            printBorder();
            currChapter++;
        case 3:
            cout << "Chapter 3: The Mysterious Dimension" << endl << endl;
            printBorder();
            cout << "As you lay there trying to piece together what happened, you hear the doorknob being turned." << endl;
            cout << "The door opens, and you see two creatures that look like humans, but their bodies are made of mist and shadow." << endl;
            cout << "They introduce themselves as Carson and Bryce." << endl;
            printBorder();
            continueStory();
            printBorder();
            cout << "You're equally confused as you don't look like the creatures in this dimension, but Carson and Bryce don't seem surprised." << endl;
            cout << "They explain that they found you passed out in the middle of a field." << endl;
            printBorder();
            continueStory();
            printBorder();
            cout << "You ask Carson and Bryce why they look so different." << endl;
            cout << "They reveal that they are Etharians, a race of ethereal beings." << endl;
            printBorder();
            continueStory();
            printBorder();
            cout << "They explain that in this dimension, Etharians used to look like normal humans until Diallos stripped their souls from their bodies." << endl;
            cout << "After assassinating the 45th King Phiholt, Diallos took rule over Ethar and enslaved the Etharians using the power of an ancient crown." << endl;
            cout << "Now, Diallos rules from a spire in the middle of Ethar, guarded by his loyal warriors and imprisoning the most powerful Etharians." << endl;
            printBorder();
            continueStory();
            printBorder();
            cout << "Carson and Bryce reveal that the only hope of escaping Diallos' rule lies in the Spire, most likely at the top floor where the crown is." << endl;
            cout << "They point outside, and you see the Spire looming in the distance." << endl;
            cout << "Carson and Bryce offer to take you to the Spire." << endl;
            printBorder();
            continueStory();
            printBorder();
            cout << "Before you and the two Etharians leave for the Spire, they ask if you would like to train first.." << endl;
            cout << "Would you like to train with Bryce and Carson?" << endl;
            printBorder();
            cout << "1. Yes, train with them.." << endl;
            cout << "2. No, Travel to the Spire now.." << endl;
                if (this->getResponse() == 1){
                    cout << "Your intensive training with Carson and Bryce has paid off! You have gained +5 Health" << endl;
                    userCharPointer->appendMaxHealth(5);
                }
                else {
                    cout << "You decided to continue your journey with Carson and Bryce to the spire..." << endl;
                }
            printBorder();
            cout << "After days of traveling, you finally made it to the Spire. Carson and Bryce wish you luck and have given you the Blessing of the Etharians." << endl;
            userCharPointer->appendStrength(3);
            cout << "The Blessing of the Etharians has granted you +3 Strength!" << endl;
            printBorder();
            cout << "Carson and Bryce said they will be with you until the very end in spirit... Their story has inspired you.." << endl;
            cout << "You have made it to the Spire, " << userCharPointer->getClassName() << " " << userCharPointer->getName() << "! Good luck on your Journey and may you defeat Diallos.."<<endl;
            printBorder();
            continueStory();
            printBorder();
            currChapter++;
            ;
    }
}

template<typename T1>
void StoryDriver<T1>::userDeathStory() {
    printBorder();
    cout << "You have Died... Diallos reigns victorious against the one hero who stood a chance against him." << endl;
    cout << "Diallos absored the Hero's soul, and with it came their power. Diallos became unstoppable and made the entire continent of Azeroth suffer his wrath." << endl;    
    cout << "With no other hero in sight, Diallos eventually became strong enough to consume the world with his corruption and power.." << endl;
    cout << "GAME OVER" << endl;
    printBorder();
}

template<typename T1>
void StoryDriver<T1>::userVictoryStory() {
    printBorder();
    cout << "Congratulations! You have defeated Diallos, the Ruined King!" << endl;
    cout << "With Diallos defeated, peace is restored to the ancient realm of Ethar." << endl;    
    cout << "The souls of the imprisoned Etharians are freed from their torment, and the land begins to heal." << endl;
    cout << "As the hero who vanquished the great evil, you are celebrated as a savior throughout Azeroth." << endl;
    cout << "Your name will be remembered for generations to come as the one who brought hope and light back to the world." << endl;
    cout << "Thank you for playing Shadows Of the Ancient Realm!" << endl;
    printBorder();
}

template<typename T1>
void StoryDriver<T1>::CaveBattle(){
    Voidling* tempEnemyVoidling = new Voidling();
    BattleDriver<Voidling>* tempBattle1 = new BattleDriver<Voidling>(userCharPointer,tempEnemyVoidling);
    tempBattle1->startBattle();

    delete tempEnemyVoidling;
    delete tempBattle1;

    // etharSoul* tempEthar = new etharSoul();
    // BattleDriver<etharSoul>* tempBattle2 = new BattleDriver<etharSoul>(userCharPointer,tempEthar);
    // tempBattle2->startBattle();
        
      
}

template<typename T1>
void StoryDriver<T1>::caveItemSelection(){
                if(userCharPointer->getClassName() == "Knight"){
                cout << "You find a steel sword in pristine condition, Would you like to equip this item?" << endl;
                cout << "1. Yes, Equip Item." << endl;
                cout << "2. No, Leave the item alone." << endl << endl;
                cout << "Please enter 1 or 2:" << endl;
                int response = this->getResponse();
                if ( response == 1) {
                    cout << "You have gained +2 strength with your new sword!" << endl;
                    userCharPointer->appendStrength(2);
                    cin.clear();
                }
                else {
                    cout << "You have decided to leave the sword alone, hopefully for the best.." << endl;
                    cin.clear();
                }
           }
           else if(userCharPointer->getClassName() == "Archer"){
            cout << "You find a large quiver in pristine condition, Would you like to equip this item?" << endl;
                cout << "1. Yes, Equip Item." << endl;
                cout << "2. No, Leave the item alone." << endl << endl;
                cout << "Please enter 1 or 2:" << endl;
                int response = this->getResponse();
                if ( response == 1) {
                    cout << "You have gained +2 strength with your quiver!" << endl;
                    userCharPointer->appendStrength(2);
                    cin.clear();
                }
                else {
                    cout << "You have decided to leave the quiver alone, hopefully for the best.." << endl;
                    cin.clear();
                }
           }
           else if(userCharPointer->getClassName() == "Rogue"){
            cout << "You find a durable pair of leather boots in pristine condition, Would you like to equip this item?" << endl;
                cout << "1. Yes, Equip Item." << endl;
                cout << "2. No, Leave the item alone." << endl << endl;
                cout << "Please enter 1 or 2:" << endl;
                int response = this->getResponse();
                if ( response == 1) {
                    cout << "You have gained +2 speed with your new boots!" << endl;
                    userCharPointer->appendSpeed(2);
                    cin.clear();
                }
                else {
                    cout << "You have decided to leave the boots alone, hopefully for the best.." << endl;
                    cin.clear();
                }
           }
           else if(userCharPointer->getClassName() == "Mage"){
            cout << "You find an ancinet tome of spells in readable condition. Would you like to read this item?" << endl;
                cout << "1. Yes, Read Item." << endl;
                cout << "2. No, Leave the item alone." << endl << endl;
                cout << "Please enter 1 or 2:" << endl;
                int response = this->getResponse();
                if ( response == 1) {
                    cout << "You have gained +2 wisdom from the spell book!" << endl;
                    userCharPointer->appendWisdom(2);
                    cin.clear();
                }
                else {
                    cout << "You have decided to leave the book alone, hopefully for the best.." << endl;
                    cin.clear();
                }
           }
}

template <typename T1>
void StoryDriver<T1>::printBackstory(){
    //Knight Backstory 
           if(userCharPointer->getClassName() == "Knight"){
            cout << "You, Knight " << userCharPointer->getName() << ", are a renowned warrior of the small kingdom of Whiterun. A noble knight, and a brave soul. "<< endl;
            cout << "You have helped slay many of Diallos' army that have attempted to overrun your home." << endl;
            printBorder();
            cout << "The high ranking officers of Whiterun believe that you are skilled enough to take on a special mission on your own." << endl;
            cout << "A group of local archaeologists have gone missing near a mysterious cave near the outskirts of Whiterun." << endl;
            printBorder();
            cout << "You are tasked to investigate the whereabouts of the missing archaeologists and to also report on what they were studying." << endl;
            cout << "You have been preparing for this moment, this is your chance to make a change in Azeroth, good luck Soldier!" << endl;
            printBorder();
           }
           //Archer Backstory
           else if(userCharPointer->getClassName() == "Archer"){
            cout << "You, Archer " << userCharPointer->getName() << ", are a well known hunter that is rather famous for slaying various beasts throughout Azeroth." << endl;
            cout << "During your hunts, you have made a name for yourself by helping out in the fight against Diallos' army." << endl;
            printBorder();
            cout << "Your keen eye and unmatched skill with the bow have saved many villages from Diallos' monstrous creations" << endl;
            cout << "A sign has been posted of a bear that has been lurking in a cave near Whiterun, so you decide to take on the challenge to slay this beast." << endl;
            printBorder();
            cout << "Apparently a group of archaeologists has been conducting research at this cave, so you hope to find them before they encounter the bear." << endl;
            cout << "Your years of experience have paid off so far, good luck on your journey Archer!" << endl;
            printBorder();
           }
           else if(userCharPointer->getClassName() == "Rogue"){
            cout << "You, Rogue " << userCharPointer->getName() <<", are an infamous criminal that is wanted in many kingdoms. Your numerous crimes have yet to catch up to you." << endl;
            cout << "You are known to be a charismatic but tricky thief that takes and kills for your self-gain." << endl;
            printBorder();
            cout << "During your time as a mercenary, you have had a good share of run-ins with Diallos' army and are experienced in defeating them." << endl;
            cout << "A group of local archaeologists have been seen entering a cave near Whiterun, where you have been sent on a mission to assassinate them." << endl;
            printBorder();
            cout << "You are tasked to leave no traces of the murder and to also take anything they were working on." << endl;
            cout << "Your cunning ways have led you to this chance to save the world. Will you change your ways for the greater good? Good luck Rogue!" << endl;
            printBorder();
           }
           else if(userCharPointer->getClassName() == "Mage"){
            cout << "You, Mage "<<  userCharPointer->getName() << ", are a wise and well respected wizard, known for your research in void creatures and of the Ruined King." << endl;
            cout << "Your ambitions of finding ancient artifacts have been successful and have made you a popular mage among the magical society of Azeroth." << endl;
            printBorder();
            cout << "You send a group of archaeologists to this mysterious cave in Whiterun, where you have heard word that there is an ancient artifact." << endl;
            cout << "Word is that the ancient artifact used to belong to an old king from centuries ago, during the time when Diallos was still human." << endl;
            printBorder();
            cout << "You believe this artifact will be the key to defeating Diallos." << endl;
            cout << "This could be your chance to finally defeat the Ruined King. Good luck Mage!" << endl;
            printBorder();
           }
           else {
            cout << "Error with character creation" << endl;
           }
}