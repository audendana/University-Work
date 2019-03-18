// file CallCenter.h
#ifndef CALL_CENTER_
#define CALL_CENTER_
#include <vector>
#include "PriorityQueue.h"

class CallCenter{
    public:
        CallCenter();
        bool accept(const ItemType& newCall);
        bool update();
        void displaySimulationResults();
        void displayCurrentStatus(int time);
        PriorityQueue getList();
        int getTotalTimeAnswerAllCalls();
        int getNumCallsCompleted();
        int getNumCallsEntered();

    private:
        PriorityQueue waitList;
        Call current;
        int totalCallsAnswered;
        int totalCallsEntered;
        int elapsedTime;
        std::vector<int> waitTime;
        std::vector<int> waitTimeP1;
        std::vector<int> waitTimeP2;
        std::vector<int> waitTimeP3;
        int totalTimeAnswerAllCalls;
        int totalTimeTaken;
        std::vector<int> priorities;

        int completedCalls;
};
#endif
