#include <iostream>
#include "PriorityQueue.h"

using namespace std;
PriorityQueue::PriorityQueue(){
    front = nullptr;
    size = 0;
}


//destructor
PriorityQueue::~PriorityQueue(){
    std::cout <<"Decon called" <<std::endl;
    Node* current = front;
    Node* temp;
    while(current != nullptr){
        temp = current->next;
        delete current;
        current = temp;
    }
} 

// checks if queue is empty
bool PriorityQueue::isEmpty() const{
    if(front == nullptr){
        return true;
    }
    return false;
}


// returns size 
int PriorityQueue::getSize() const{
    return size;
}


// adds a new element to the front of the list. (replaces head)
bool PriorityQueue::enqueue(const ItemType& newCall){

    //create new node
    Node* temp = new Node;
    temp->data = newCall;
    temp->next = nullptr;

    // check to see if its empty first
    if(this->isEmpty()){
        front = temp;
        size++;
        return true;
    } else {

        // if the queue is not empty check to see if the new node is higher priority than 
        // the node with top priority 
        if(newCall > front->data){
            temp->next = front;
            front = temp;
            size++;
            return true;
        } else {
            Node* start = front;
            while(start->next != nullptr && start->next->data > newCall){
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
            size++;
            return true;
        }
        return false;
    }
    return false;
}


// remove highest priority node
ItemType PriorityQueue::dequeue(){
   Node* temp = new Node;
   temp = front;
   ItemType retVal = temp->data;
   front = front->next;
   delete temp;
   size--;
   return retVal;
}


// return highest priority node
ItemType PriorityQueue::getFront(){
    return front->data;
}

void PriorityQueue::display(){
        Node* start = front;
        int count =1;
        while(start != nullptr){
            std::cout << count << ". " << start->data << std::endl;
            start = start->next;
            count++;
        }

}
