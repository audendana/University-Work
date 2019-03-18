#include <iostream>
#include "CallCenter.h"
#include <random>


// decides if a new call has arrived based on the arrival rate
bool newCallArrived(double arrivalRate);

// get length of simulation from user
int getLengthOfSim();

// get arrival rate from user
double getArrivalRate();

int main(){
    CallCenter center;

    int simLength = getLengthOfSim();
    double arrivalRate = getArrivalRate();


    // check to see if invalid entry was made
    if(arrivalRate == -1 || simLength == -1){
        if(arrivalRate == -1){
            std::cout <<"Invalid arrivalRate" << std::endl;
        } else {
            std::cout <<"Invalid simulation length" << std::endl;
        }
    } else {

        // loop through for total time of simulation.
        // each loop equals 1 minute
        for(int i=0;i<simLength;i++){

            //if we get a new call create an instance and pass it
            if(newCallArrived(arrivalRate)){
                Call newCall;
                center.accept(newCall);
            }

            // call update
            center.update();

            // check to see if 5 mintues have passed
            if((i%5) == 0){
                center.displayCurrentStatus(i);
            }
        }
        int time = center.getTotalTimeAnswerAllCalls();        

        // finish answering all calls
        for(int simLength;simLength<center.getTotalTimeAnswerAllCalls(); simLength++){
            if((simLength%5) == 0){
                center.displayCurrentStatus(simLength);
            }
            center.update();
            if(center.getNumCallsCompleted() == center.getNumCallsEntered()){
                break;
            }
        }
    }

    center.displaySimulationResults();
}

int getLengthOfSim(){
    int length =0;
    std::cout <<"Enter the length of simulation: ";

    std::cin >> length;
    if(length < 30){
        length = -1;
    }
    return length;
}

double getArrivalRate(){
    double arrivalRate = 0;
    std::cout <<"Enter the arrival rate of new calls(number between .1 and 1): ";
    std::cin >> arrivalRate;
    if((arrivalRate < .1) || (arrivalRate >1)){
        arrivalRate = -1;
        return arrivalRate;
    }
    return arrivalRate;
}

bool newCallArrived(double arrivalRate){

    //create random device to pass to seed generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // multiply the arrival rate by 100 so its in integer form
    double realVal = arrivalRate * 100;

    // get the value that it doesnt arrive (1-p)
    double val2 = 100 - realVal;
    
    // pass them into the distribution(p, 1-p)
    std::discrete_distribution<> d({realVal, val2});
    int val3 = d(gen);
    

    // 0 means we create a new call
    if(val3 == 0){
        return true;
    } else {
        return false;
    }
}
