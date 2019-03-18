// file: Call.cpp
#include <iostream>
#include <random>
#include "Call.h"


Call::Call(){
    // set time of arrival number of seconds since epoch 1970
    timeOfArrival = time(NULL);

    // make random device rd to pass into our seed generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // have the distribution of 10% 1, 30%, 2, %60 3
    std::discrete_distribution<> d({10,30,60});
    std::uniform_int_distribution<int> distribution(3,8);
    timeToAnswer = distribution(gen);

    // add one because originally discrete distribution starts
    // at 0 not 1 like we want
    priority = d(gen) + 1;
}


time_t Call::getTimeOfArrival() const{
    return timeOfArrival;
}

int Call::getPriority() const{
    return priority;
}

int Call::getTimeToAnswer() const{
    return timeToAnswer;
}


// overide the  > operator
bool Call::operator>(const Call& comparator) const{
    if(priority < comparator.getPriority()){
        return true;
    }

    if(priority == comparator.getPriority()){
        if(timeToAnswer < comparator.getTimeToAnswer()){
            return true;
        }
    }
    return false;
}

//overide the != operator
bool Call::operator!=(const Call& val) const{
    if((val.getPriority() != priority)||
        (val.getTimeOfArrival() != timeOfArrival) ||  
        (val.getTimeToAnswer() != timeToAnswer)){
        return true;
    }
    return false;
}

//overide the << operator for Call
std::ostream& operator<<(std::ostream& os, Call pass){
    os <<"Time of Arrival: " << std::to_string(pass.getTimeOfArrival()) << "/n "
       <<"Priority: " << std::to_string(pass.getPriority()) << "/n "
       <<"Time to Answer: " << std::to_string(pass.getTimeToAnswer()) << "/n ";
    return os;
}
