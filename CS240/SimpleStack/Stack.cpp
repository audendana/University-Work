// file: Stack.cpp
#include <iostream>
#include "Stack.h"

using namespace std;
Stack::Stack(){
    top = nullptr;
    bot = nullptr;
    size = 0;
}


// preppends element to stack
bool Stack::push(const ItemType & newItem){
    Node* placeHldr = new Node;
    placeHldr->next = nullptr;
    placeHldr->data = newItem;

    if(top == nullptr){
        top = placeHldr;
        bot = placeHldr;
        size++;
        return true;
    }

    if(top != nullptr){
        placeHldr->next = top;
        top = placeHldr;
        size++;
        return true;
    }
    return false;
}


// returns and removes top element of stack
ItemType Stack::pop() {
    ItemType retVal;
    Node* placeHldr = top;
    retVal = placeHldr->data;
    top = top->next;
    delete placeHldr;
    size--;
    return retVal;
}


// returns top element of stack
ItemType Stack::peak() const{
        return top->data; 
}


// checks to see if stack is empty returns true if it is
bool Stack:: isEmpty() const{
    if(top == nullptr){
        return true;
    }
    return false;
}


// returns stacks length
int Stack::getLength() const{
    return size;
}

//Deconstructor for the stack freeing memory
Stack::~Stack(){
    Node* temp1 = top;
    Node* temp2;
    while(temp1 != nullptr){
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }
    size = 0;
    bot = nullptr;
}


// Displays all values in the stack
void Stack::display(){
    if(top == nullptr){
        return;
    }
    Node* looper = top;
    int count = 1;
    while(looper != nullptr){
        cout << count << ". " << looper->data << endl;
        looper = looper->next;
        count++;
    }
}
