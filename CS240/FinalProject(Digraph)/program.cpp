// file program.cpp
#include<iostream>
#include "circle.h"

using namespace std;

Circle createCircle();

void displayMenu();
void runProgram(Circle circle);

int main(){
    Circle circle = createCircle();
    runProgram(circle);
    return 0;
}
Circle createCircle(){
    Circle circle;
    cout <<"Adding Members" << endl;
    circle.addMember("Auden");
    circle.addMember("Sam");
    circle.addMember("Gabby");
    circle.addMember("Jarrett");
    circle.addMember("Nikki");
    circle.addMember("Mike");
    cout<< endl;

    cout <<"Adding Friendships" << endl;
    circle.addFriendship("Auden", "Sam");
    circle.addFriendship("Auden", "Gabby");
    circle.addFriendship("Auden", "Nikki");
    circle.addFriendship("Auden", "Jarrett");

    circle.addFriendship("Sam", "Auden");
    circle.addFriendship("Sam", "Gabby");

    circle.addFriendship("Gabby", "Auden");

    circle.addFriendship("Jarrett" ,"Mike");
    circle.addFriendship("Mike", "Jarrett");
    
    circle.addFriendship("Gabby", "Nikki");
    circle.addFriendship("Nikki", "Gabby");
    circle.addFriendship("Nikki", "Auden");
    cout << endl;
    return circle;
}

void runProgram(Circle circle){
    displayMenu();
    int input = 0;
    while(input != 12){
        cout <<"Enter the number of the option you'd like to select: ";
        cin >> input;
        if(input == 1){
            circle.displayMembers();
            cout << endl;
        } else if(input == 2){
            circle.displayNumOfPeopleInCircle();
            cout << endl;
        } else if(input == 3){
            circle.displayNumOfFriendships();
            cout << endl;
        } else if(input == 4){
            string name;
            cout << "Please enter the name of the person to see if they are in the circle: ";
            cin >> name;
            circle.isMember(name);
            cout <<endl;
        } else if(input == 5){
            string name;
            cout <<"Please enter the name of the person so you can see who designated them as a friend: ";
            cin >> name;
            circle.displayPersonsFriends(name);
            cout <<endl;
        } else if(input == 6){
            string name1;
            string name2;
            cout <<"Enter name1: ";
            cin >> name1;
            cout <<"Enter name2: ";
            cin >> name2;
            circle.isP1FriendOfP2(name1, name2);
            cout << endl;
        } else if(input == 7){
            string name1;
            string name2;
            cout <<"Enter name2: ";
            cin >> name2;
            cout <<"Enter name1: ";
            cin >> name1;
            circle.isP2FriendOfP1(name1, name2);
            cout <<endl;
        } else if(input == 8){
            string name1;
            string name2;
            cout <<"Enter name1 the person you want to remove: ";
            cin >> name1;
            cout <<"Enter name2 the person you want to remove name1 from: ";
            cin >> name2;
            circle.removePerson1FromPerson2(name1, name2);
            cout <<endl;
        } else if(input == 9){
            string name;
            cout <<"Enter the name of the person so you can see how many people have designated them as a friend: ";
            cin >> name;
            circle.numOfPeopleFriendsOfPerson(name);
            cout << endl;
        } else if(input == 10){
            string name;
            cout <<"Enter the name of the person you want to remove from the circle of friends: ";
            cin >> name;
            circle.removePersonFromCircle(name);
            cout << endl;
        } else if(input == 11){
            displayMenu();
        } else if(input == 12){
            break;
        } else {
            input =12;
            break;
        }
    }
    return;

}

void displayMenu(){
    cout <<"-------MENU--------" << endl;
    cout <<"1. Display the members of the circle. " << endl;
    cout <<"2. Display number of people in the circle. " << endl;
    cout <<"3. Display number of friendships in the circle. " << endl;
    cout <<"4. Is 'name' a member of the circle. " << endl;
    cout <<"5. Who has 'name' designated as a friend. " << endl;
    cout <<"6. Has 'name1' designated 'name2' as a friend. " << endl;
    cout <<"7. Has 'name2' designated 'name1' as a friend. " << endl;
    cout <<"8. Remove 'name1' as a friend of 'name2'." << endl;
    cout <<"9. How many people have designated 'name' as a friend. " << endl;
    cout <<"10. Remove 'name' from the circle of friends. " << endl;
    cout <<"11. For the Menu again." << endl;
    cout <<"12. Quit()" << endl;
    cout << endl;
}
