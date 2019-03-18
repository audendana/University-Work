// file CallCenter.cpp
#include<iostream>
#include<vector>
#include"CallCenter.h"

CallCenter::CallCenter(){

    // initialize all my data members
    totalCallsAnswered = 0;
    totalCallsEntered = 0;
    elapsedTime = 0;
    totalTimeAnswerAllCalls = 0;
    completedCalls = 0;
    totalTimeTaken = 0;

    priorities.reserve(3);
    for(int i=0;i<priorities.size();i++){
        priorities.push_back(0);
    }

}

// here we pass in the new call we want to add
bool CallCenter::accept(const ItemType& newCall){
    if(waitList.enqueue(newCall)){
        totalCallsEntered++;
        totalTimeAnswerAllCalls+= newCall.getTimeToAnswer();
        return true;
    }
    return false;
}



bool CallCenter::update(){
    time_t timeAnswered;

    // this checks to see if the current call is the highest priority if its not
    // update the current call to the highest priority call;
    // when doing this we reset the elapsed time to 0 because a new call was picked up
    if(!waitList.isEmpty()){
        if(current != waitList.getFront()){
            current = waitList.getFront();
            timeAnswered = time(NULL);
            elapsedTime = 0;
            totalTimeTaken++;
            return true;
        }

        
        // now we check to see if the current call we are on has been answered
        // does this by checking to see if the current calls total time it takes to answer 
        // equals the elapsed time since the call was picked up 
        // current call is always front of the waitlist;
        if(current.getTimeToAnswer() == elapsedTime){
            Call finishedCall = waitList.dequeue();
            completedCalls++;
            totalCallsAnswered++;

            // get the total time in seconds since it was created to the time it was completed
            double seconds = difftime(timeAnswered, finishedCall.getTimeOfArrival()); 

            //convert to minutes
            int timeInMin = seconds / 60;
            waitTime.push_back(timeInMin);


            // add times to correct priority vectors
            int priority = finishedCall.getPriority();
            if(priority == 1){
                waitTimeP1.push_back(timeInMin);
            } else if(priority == 2){
                waitTimeP2.push_back(timeInMin);
            } else if(priority == 3){
                waitTimeP3.push_back(timeInMin);
            }
            totalTimeTaken++;
        return true;
        }
        totalTimeTaken++;
        elapsedTime++;
        return true;
    }
    totalTimeTaken++;
    elapsedTime++;

    return true;

}

PriorityQueue CallCenter::getList(){
    return waitList;
}


void CallCenter::displaySimulationResults(){
    std::cout <<"Simulation Results"<< std::endl;
    std::cout <<"Total Number of Calls Answered: " << totalCallsAnswered << std::endl;
    std::cout <<"Total Number of Calls Entered: " << totalCallsEntered << std::endl;
    std::cout <<"Total Time taken for simulation: " << totalTimeTaken << std::endl;

    // calc avg wait time for all calls, and each priority 
    double avgWaitTime = 0;
    for(int i=0;i<waitTime.size();i++){
        avgWaitTime+= waitTime[i];
    }
    avgWaitTime / waitTime.size();

    std::cout <<"The average wait time for a call is : " << avgWaitTime << std::endl;

    double avgWaitTimeP1 = 0;
    for(int i=0;i<waitTimeP1.size();i++){
        avgWaitTimeP1+= waitTimeP1[i];
    }
    avgWaitTimeP1/ waitTimeP1.size();
    std::cout <<"The average wait time for calls of priority 1: " << avgWaitTimeP1 << std::endl;

    double avgWaitTimeP2 = 0;
    for(int i=0;i<waitTimeP2.size();i++){
        avgWaitTimeP2+= waitTimeP2[i];
    }
    avgWaitTimeP2/ waitTimeP2.size();
    std::cout <<"The average wait time for calls of priority 2: " << avgWaitTimeP2 << std::endl;

    double avgWaitTimeP3 = 0;
    for(int i=0;i<waitTimeP3.size();i++){
        avgWaitTimeP3+= waitTimeP3[i];
    }
    avgWaitTimeP3/ waitTimeP3.size();
    std::cout <<"The average wait time for calls of priority 3: " << avgWaitTimeP3 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

}

void CallCenter::displayCurrentStatus(int time){
    std::cout << "The current simulation time: " << totalTimeTaken<< " minutes" << std::endl;

    // we subtract 1 because the front is the current call
    std::cout <<"Number of calls in waiting list: " << waitList.getSize() -1 << std::endl;
    std::cout << "Number of calls completed: " << completedCalls << std::endl;
    std::cout << std::endl;
}

int CallCenter::getTotalTimeAnswerAllCalls(){
    return totalTimeAnswerAllCalls;
}

int CallCenter::getNumCallsCompleted(){
    return completedCalls;
}

int CallCenter::getNumCallsEntered(){
    return totalCallsEntered;
}
