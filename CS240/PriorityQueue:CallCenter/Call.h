// file: Call.h
#ifndef CALL_
#define CALL_


class Call{
    public:
        Call();
        time_t getTimeOfArrival() const;
        int getPriority() const;
        int getTimeToAnswer() const;
        bool operator>(const Call& comparator) const;
        //bool operator==(const Call& lhs);
        bool operator!=(const Call& comparator) const;
        friend std::ostream& operator<<(std::ostream& os, Call pass);


    private:
        time_t timeOfArrival;
        int priority;
        int timeToAnswer;

};
#endif
