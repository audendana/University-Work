// map.cpp
#include<iostream>
#include "map.h"

map::map(){
    head = nullptr;
    tail = nullptr;
    sizeOfMap = 0;
}


//Destructor frees memory space
map::~map(){
    std::cout <<"Destructor called." << std::endl;
    Node* temp = head;
    Node* current;
    while(temp != nullptr){
        current = temp->next;
        delete temp;
        temp = current;
    }
    tail = nullptr;
    sizeOfMap = 0;
}



// next time for assignment 6 you need to create a new node for the copy list
// it needs its own space, the way it is now makes it just point to the same space
// in memory.
map::map(const map& origClass){
    std::cout <<"Copy Constructor called." << std::endl;
    head = nullptr;
    tail = nullptr;
    sizeOfMap= 0;
    Node* temp = origClass.head;
    while(temp != nullptr){
        add(temp->data);
        temp = temp->next;
    }
}

map& map::operator=(const map& objToCopy) {
    std::cout <<"Operator= (copy assignment) constructor called." << std::endl;
    if(this != &objToCopy){
        Node* del = head;
        Node* current;
        while(del != nullptr){
            current = del->next;
            delete del;
            del = current;
        }

        head = nullptr;
        tail = nullptr;
        sizeOfMap = 0;
        Node* temp = objToCopy.head;
        while(temp != nullptr){
            add(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}


// returns true if head == nullptr
bool map::empty() const{
    if(head == nullptr){
        return true;
    }
    return false;
}


// returns sizeOfMap datamember
int map::size() const{
    return sizeOfMap;
}


// appends element if key is not found
bool map::add(ElementType element){
    if(!find(element.first)){
        Node* temp = new Node;
        temp->next = nullptr;
        temp->data = element;
        if(empty()){
           head = temp; 
           tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        sizeOfMap++;
        return true;
    } else {
        return false;
    }
}


// if map is not empty compares map elements to key to find match
bool map::find(KeyType key) const{
    if(!empty()){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data.first == key){
                return true;
            } else {
                temp = temp->next;
            }
        }
    }
    return false;
}


// if empty or key not found return null ptr
// otherwise loop through map and search for match
// if match return the valuetype
ValueType map::retrieve(KeyType key) const{
    if(empty()){
        return nullptr;
    } else {
        if(!find(key)){
            return nullptr;
        } else {
            Node* temp = head;
            while(temp != nullptr){
                if(temp->data.first == key){
                    return temp->data.second;
                } else {
                    temp = temp->next;
                }
            }
        }
    }
    return nullptr;
}


// return false if empty or key not found
// otherwise check if key is head
// then loop through list till match
// delete node and adjust the pointers
bool map::remove(KeyType key){
    if(!find(key) || empty()){
        return false;
    }
    
    if(head->data.first == key){
        Node* temp = head;
        head = head->next;
        delete temp;
        if(head == nullptr){
            tail = nullptr;
        }
        sizeOfMap--;
        return true;
    }

    Node* temp = head;

    while(temp->next != nullptr){
        if(temp->next->data.first == key){
            Node* next = temp->next->next;
            delete temp->next;
            temp->next = next;
            sizeOfMap--;
            if(next == nullptr){
                tail = temp;
            }
            return true;
        }

        temp = temp->next;

    }
    return false;
}


// displays the map to cout
void map::displayAll() const{
    std::cout <<"displayCalled" << std::endl;
    if(empty()){
        std::cout <<"Map is empty."<<std::endl;
    } else {
        Node* temp = head;
        int count = 1;
        while(temp != nullptr){
            std::cout<< count<< ". Key: " << temp->data.first;
            std::cout <<", Value: " << *temp->data.second << std::endl;
            temp = temp->next;
            count++;
        }
    }

}
