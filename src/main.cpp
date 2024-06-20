#include <string>
#include <iostream>
using namespace std;

#include "../src/SpireDriver.cpp"
#include "../src/storyDriver.cpp"




int main(){

    //after user makes character
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Hello adventurer what is your name?"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    string userName;
    cin>>userName;

    cout<<"-------------------------------------------------"<<endl;
    cout<<"What class are you picking(Enter 1, 2, 3, or 4)"<<endl;
    cout<<"1.Knight"<<endl;
    cout<<"2.Rogue"<<endl;
    cout<<"3.Archer"<<endl;
    cout<<"4.Mage"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    
    int classSelect=0;
    cin>>classSelect;
    while (cin.fail() || classSelect < 1 || classSelect > 4) {
        cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
        cin.clear(); 
        cin.ignore();
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

    cout<<"-------------------------------------------------"<<endl;
    cout<<"Enter 1 to play through the story then spire."<<endl;
    cout<<"Enter 2 to skip the story and go stright to spire"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    int gameChoice=0;
    cin>>gameChoice;
    while (cin.fail() || gameChoice < 1 || gameChoice > 2) {
        cout << "Invalid input. Please enter 1 or 2" << endl;
        cin.clear(); 
        cin.ignore();
        cin>>gameChoice;
    }

    if(gameChoice==1){
    StoryDriver<UserCharacter>* story= new StoryDriver<UserCharacter>(userChar);
    story->startStory();
    delete story;
    }
    cout<<"-------------------------------------------------"<<endl;
    cout<<"You have entered the spire"<<endl;
    SpireDriver<UserCharacter>* spire = new SpireDriver<UserCharacter>(userChar);
    spire->Spire_Runner();

    delete spire;

    
    return 0;
}