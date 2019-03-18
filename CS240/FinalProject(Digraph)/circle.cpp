// file circle.cpp
#include <iostream>
#include "circle.h"

Circle::Circle(){

}

bool Circle::addMember(string name){
    if(circleOfFriends.addVertex(name)){
        cout <<"Added " << name << " to the cirlce of friends." << endl;
        return true;
    } else {
        cout <<name <<" was already added to the circle." << endl;
        return false;
    }
}

bool Circle::addFriendship(string friend1, string friend2){
    if(!circleOfFriends.findVertex(friend1) || !circleOfFriends.findVertex(friend2)){
        if(!circleOfFriends.findVertex(friend1)){
            cout <<friend1 << " is not a member of the circle, the friendship cant be added." << endl;
            return false;
        } else {
            cout <<friend2 <<" is not a member of the circle, the friendship cant be added." << endl;
            return false;
        }
    }
    int start = convertNameToNum(friend1);
    int term = convertNameToNum(friend2);
    if(circleOfFriends.addEdge(start, term)){
        cout <<"Added a friendship between " << friend1 << " and " << friend2 << "." << endl;
        return true;
    }
    cout <<"Could not add the friendship between " << friend1 << " and " << friend2 << "."<<endl;
    return false;
}

void Circle::displayMembers(){
    vector<string> people = circleOfFriends.getVertices();
    int count = 1;
    cout <<"Members of the cirlce." << endl;
    for(auto i : people){
        cout << count << ". " << i << endl;
        count++;
    }
}

void Circle::displayNumOfPeopleInCircle(){
    cout <<"The number of people in the circle is: " << circleOfFriends.getNumOfVertices() << endl;
}

void Circle::displayNumOfFriendships(){
    int numOfFriendships = circleOfFriends.getNumOfEdges();
    cout <<"The number of friendships in the circle is: " << numOfFriendships << endl;
}

bool Circle::isMember(string name){
    if(circleOfFriends.findVertex(name)){
        cout <<name << " is a member of the circle" << endl;
        return true;
    }
    cout << name << " is not a member of the circle" << endl;
    return false;
}

void Circle::displayPersonsFriends(string name){
    cout << "People who designated " << name << " as a friend are " << endl;
    int start = convertNameToNum(name);
    list<int> succ = circleOfFriends.getSuccessors(start);
    vector<string> people = circleOfFriends.getVertices();
    int count = 1;
    for(int i : succ){
        cout << count <<". " << people.at(i) << endl;
        count++;
    }
}

bool Circle::isP1FriendOfP2(string name1, string name2){
    int start = convertNameToNum(name1); 
    int term = convertNameToNum(name2);

    if(circleOfFriends.findEdge(start, term)){
        cout <<name1 << " is a friend of " << name2 << endl;
        return true;
    }
    cout <<name1 << " is not a friend of " << name2 << endl;
    return false;
}

bool Circle::isP2FriendOfP1(string name1, string name2){
    int start = convertNameToNum(name2);
    int term = convertNameToNum(name1);
    if(circleOfFriends.findEdge(start, term)){
        cout <<name1 << " has been designated as a friend by " << name2 << endl;
        return true;
    }
    cout <<name1 << " has not been designated as a friend by " << name2 << endl;
    return false;
}

bool Circle::removePerson1FromPerson2(string name1, string name2){
    int start = convertNameToNum(name2);
    int term = convertNameToNum(name1);

    if(circleOfFriends.removeEdge(start, term)){
        cout <<"The friendship between " << name2 << " and " << name1 << " has been removed." << endl;
        return true;
    }

    cout <<"Could not remove the friendship between " << name2 << " and " << name1 << endl;
    return false;
}

void Circle::numOfPeopleFriendsOfPerson(string name){
    int start = convertNameToNum(name);
    int numOfPeople = circleOfFriends.getNumOfPredecessors(start);
    cout << numOfPeople << " people have " << name << " added as a friend." << endl;
}

bool Circle::removePersonFromCircle(string name){
    int start = convertNameToNum(name);
    list<int> nameSucc = circleOfFriends.getSuccessors(start);
    for(int i : nameSucc){
        circleOfFriends.removeEdge(start, i);
    }

    vector<list<int> > edges = circleOfFriends.getEdges();
    for(auto listIn : edges){
        for(auto j : listIn){
            if(count(listIn.begin(), listIn.end(), start) != 0){
                circleOfFriends.removeEdge(j, start);
            }
        }
    }
    circleOfFriends.removeVertex(name);
    cout <<"Removed " << name << " from all friendships and from the circle." << endl;
    return true;
}

int Circle::convertNameToNum(string name){
    vector<string> people = circleOfFriends.getVertices();
    int retVal = distance(people.begin(), find(people.begin(), people.end(), name));
    return retVal;
}

void Circle::quit(){
    return;
}
