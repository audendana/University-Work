// file circle.h
#ifndef CIRCLE_
#define CIRCLE_

#include "digraph.h"
using namespace std;

class Circle{
    public:
        Circle();
        bool addMember(string name);
        bool addFriendship(string friend1, string friend2);
        void displayMembers();
        void displayNumOfPeopleInCircle();
        void displayNumOfFriendships();
        bool isMember(string name);
        void displayPersonsFriends(string name);
        bool isP1FriendOfP2(string name1, string name2);
        bool isP2FriendOfP1(string name1, string name2);
        bool removePerson1FromPerson2(string name1, string name2);
        void numOfPeopleFriendsOfPerson(string name);
        bool removePersonFromCircle(string name);
        int convertNameToNum(string name);
        void quit();

    private:
        Digraph circleOfFriends;


};
#endif

