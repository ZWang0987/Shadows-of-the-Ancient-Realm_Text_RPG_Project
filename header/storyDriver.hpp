#ifndef STORYDRIVER_HPP
#define STORYDRIVER_HPP

#include <string>


using namespace std;

template <typename T1>
class StoryDriver {
    private:
        int currChapter;
        int userResponse; 
        string characterType;  
        T1* userCharPointer;
    public:
        StoryDriver(T1* userChar) : currChapter(1), userResponse(0), characterType(userChar->getClassName()), userCharPointer(userChar) {}
        ~StoryDriver(){}
        void startStory();
        void printBorder();
        int continueStory();
        int getResponse();
        void outputNextStorySection();
        void userDeathStory();
        void userVictoryStory();
        void CaveBattle();
        void caveItemSelection();
        void printBackstory();
};

#endif
