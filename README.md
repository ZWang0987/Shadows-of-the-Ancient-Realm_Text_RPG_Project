# Shadows of the Ancient Realm
**Authors: Zexuan Wang, Andy Payan, Parsa Tehrani, Justin Shiu**
> 
> https://github.com/apaya22
> 
> https://github.com/parsat12
> 
> https://github.com/jshiu004
> 
> https://github.com/ZWang0987


## Project Description

**Why is it important or interesting**
-This project is important for us due to our interest in becoming future game developers. This would be our first step into the field of video game development. In addition, we also share the same interest by having played many turn-based RPGs in the past such as Pokemon and Final Fantasy. 

**Languages, tools and tech**
-Our chosen IDE will be VScode as this is what we are most comfortable and familiar with. Along with VScode, we will code in C++ as that is our shared primary coding language. 

**Input/Outputs**
-Like any turn-based RPG, we will need user input. These inputs will be entered by the user through the terminal. These inputs will be for various things  character selection, story path choices, and battle actions. Based on the user input, different outputs will be displayed to the terminal. For example, if the user chooses to go right instead of left 

The output will display "_characterName_ walks down the right path". User actions such as attacks or moves will also be displayed back to the user. During combat, we will display the user's health, attack choices, and item choices along with the enemy's health and next attack. This is all in the hope of providing a real RPG-like experience without the fancy graphics. 

**Features**
-All of the displays would be through text, however, we are going to aim for a dynamic approach where live user inputs will result in live outputs. In addition, since this would be a text-turned-based RPG we will aim to have the user's actions affect the storyline. The story will be linear as the character starts in a town and ventures to an ancient realm to defeat the big evil, but throughout the story, we will prompt the user to choose certain actions that will result in a different ending or acquire certain items. For example, if the user chooses to help the poor man he will be rewarded with a legendary sword, or the user can save his money. After everything is put together we should have a playable text-turned-based RPG with an amazing story that is reflected upon the user's actions. 

 > ## Phase II
>
**TA CHECK-IN TIME: 9:40am - 9:50am, Friday, May 10, 2024**
>
**GRADER CHECK-IN TIME: 10:00am - 10:15am, Friday, May 10, 2024**
## User Interface Specification

### Navigation Diagram(Parsa/Justin)
![Screenshot 2024-05-06 193338](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165938580/391ee0ef-a186-4ee5-8b6c-ee9d6434f794)

This Navigation Diagram represents the path users can take in this project. Each choice leads to the next step in the program. The user chooses a character and then the story starts. Once the story starts, there will be actions that the user can choose from to progress in the story. Eventually, the story will come to an end and the program will finish.

### Screen Layouts(Parsa/Justin)
**Welcome Screen**

<img width="325" alt="Screenshot 2024-05-06 at 9 06 51 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/0631a4ae-319b-449c-9b46-c8b49267932b">

This is the welcome screen where user is prompted to select a character for the game. They will pick the character and that will be their role for the rest of the game

**Storyline text**

<img width="210" alt="Screenshot 2024-05-06 at 9 14 14 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/fc59ca61-7a95-45bd-8d0c-0bf9fce4ec31">

This is the storyline screen which will output text regarding the storyline

**User action selection**

<img width="331" alt="Screenshot 2024-05-06 at 9 16 51 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/2c8419b1-af2a-4e22-9f56-0a8d8fc04643">

This is where the player will select an action

**Possible actions**

<img width="615" alt="Screenshot 2024-05-06 at 9 19 31 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/a0e6c7a9-882c-4bd0-819b-493618f599d8">

Here are the different actions the user can select

**Enemy Response**

<img width="493" alt="Screenshot 2024-05-06 at 9 21 01 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/e11f641c-1488-4d25-a9c2-772d2b6d6582">

The enemy will respond with an action of their own

**Winning Screen**

<img width="346" alt="Screenshot 2024-05-06 at 9 23 12 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/0bb09b7d-d60f-4beb-86d8-ada715834452">

This is shown when the story ends and you have won

**Losing Screen**

<img width="303" alt="Screenshot 2024-05-06 at 9 24 20 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165940170/6ecd2a7b-ce0d-403f-a1e9-2a3cdb51161c">

This is shown when the you die in battle and you lose the game









## Class Diagram(Andy/Z)
<img width="1073" alt="Screenshot 2024-05-21 at 5 03 35 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/342df133-7f2d-479e-bbab-f05b23b6e87b">

>
**Drivers** We have implemented different Driver classes for our design and game.
>
**Game_Driver** With that, we have the Game_Driver class that will hold a pointer to the user's character, Story_Driver, Battle_Driver, and Spire_Driver. This driver is used to start/end the game. In addition, Game_Driver will use aggregation with Story_Driver, Battle_Driver, and Spire_Driver as if the game is destroyed the story battle and spire stage should be as well. 
>
**Story_Driver** The Story-Driver class will drive the storyline of the game before the actual spire stages of the game. This class will mainly be used to output to the terminal while taking user inputs for story responses. With those inputs, we will then again output new story text. This class will also move through the story until we reach the spire stages.
>
**Battle_Driver** The Battle-Driver class will drive the combat during the spire stages of the game. This class will only be used to manage combat between the user character and an enemy. If combat starts, it will end when one character reaches zero health. If the user dies then the game ends, if the enemy dies the character shall be rewarded with gold and XP. This class will also manage outputs to the console regarding combat such as asking for which attack to use and the outcome of attacks.
>
**Spire_Driver** The Spire_Driver class will drive the majority of our game. The spire is where the player will enter after the story is introduced. The spire will be X amount of floors the player will have to climb through. Each floor will have different encounters such as a resting room, merchant, encounter,,,etc. The floor selection will depend on the user input. After each floor, the user should be prompted left, right, or middle. This driver will handle which path the user chose and then output or start the following room encounter. 
>
><img width="1336" alt="Screenshot 2024-05-21 at 5 31 57 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/daf901f6-b5a1-4c38-bc99-8ba11e490ea9">

**Character(class)** This is the super class, character. This is the class that the subclasses user character and enemy characters will inherit from. This class contains definitions for functions and variables that each inherited character must have, such as the private variables of name, current and max health, strength, wisdom, defense, and speed. Along with this all classes that inherit from character must have append and get functions for these values. 
>
><img width="751" alt="Screenshot 2024-05-21 at 5 40 57 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/fc90ea24-f6e3-4d52-8f52-c9207a2dca56">

**User_Character(class)** This is a class that inherits character class. This class contains functions and values that are inherited from character, such as the append and get functions. Every user_character will have an array of size 8 holding strings of item names along with current gold xp, and level. Each user character will also have its own constructor, append and get functions for current xp, gold, and items, and a level-up function. The composite subclasses from User_character are the types of characters the user can choose from, ranging from knight, archer, rouge, and mage. Each User_character subclass has it's own unique constructer and 6 unique functions that will act as their abilities during combat. 
>
><img width="826" alt="Screenshot 2024-05-21 at 5 48 14 PM" src="https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/747ed5d7-a10f-479c-94c7-465c74947013">

**Enemy_Character(class)** This is a class that inherits character class This class contains functions and values that are inherited from character. Every enemy character will have a value for dropped gold and XP. Each enemy character will also have its own constructor, append and get functions for their xp and gold values. Different enemies will derive from the enemy class. This will allow for easier creation of enemies. Each enemy will come with thier unique rank, name, skills, and constructor. In additon each subenemy will work like the subcharacter classes excpet will not be controlled by the user during combat. 
>
**S.O.L.I.D Principles**
>
**Open Closed Principle** We used OCP for our character classes. This was done by having the Character class as the head class, then User_Character and Enemy_Character inherited from the Character class. Then with User/Enenmy_Character, we have separate classes that are the actual playable and useable characters. The relationship here is User/Enenmy_Character extends the Character class via inheritance/polymorphism. Then each user/enemy such as Knight or Diallos shares compositions with the User/Enenmy_Character class. To make each character we made a whole new class rather than edit the existing class. The way of this structure we allow new functionality to be added with changing existing functions.
>
**Liskov's Substitution Principle** We used LSP in our character class, via our sub-character classes behaving like the base class. In addition, the character class is meant to be replaceable with their subtypes without affecting correctness. We also used LSP in our Driver classes as each driver class in theory behaves like the game driver. These drivers essentially start a section of the game, progress through, then end.
>
**Interface Segregation Principle** We used ISP in our character and driver classes as these classes do have to implement interfaces that they do not use. In addition, the subclasses do not have empty functions from their base classes.



 > ## Phase III
 **New Class Diagram along with description and solid principles are added in phase2 section, along will full class diagram attached in the files portion**


 
 > ## Final deliverable
 >
 
 
 ## Screenshots
 > Screenshots of the input/output after running the game:
>![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/eee5a1e4-37ff-4152-82e6-818e6ef71924)
> 
> ![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/1c6dfb41-c1e4-47a8-a4a7-b3e7cbb9b9e8)> 
> ![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/38babbff-88c0-4e5c-8a87-1ef9d7333c43)
> 
> ![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/d4b66cb5-b890-45c3-b2d9-3255f2f21190)> 
> ![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/47b5fb1d-c01c-4ae4-897a-1e8bff954c5d)
> 
> ![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/e6cb889c-0775-4dc3-ac12-2fe1b02687b9)
> 
> ![image](https://github.com/cs100/final-project-ptehr002-jshiu004-apaya014-zwang577/assets/165939569/51e220ae-c6fd-43f1-aa29-0408de193a78)
> 






 ## Testing
For our tests, we made sure to thoroughly test the functions that append, get, and print various variables used during the game. The characters were a huge focus of testing just to make sure the user would have no issues with the functions it uses, such as the battles and get functions. Our tests ensure a clean gaming experience for the user, as well as making sure everything is being printed correctly.  
## Installation/Usage
In order to run the game and to start playing, you must run:
> cmake .
> 
> make
> 
> ./bin/main
