// file: PriorityQueue;
#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_
#include "Call.h"

typedef Call ItemType;

class PriorityQueue{
    public:
        PriorityQueue();
       ~PriorityQueue();
        bool isEmpty() const;
        int getSize() const;
        bool enqueue(const ItemType& newCall);
        ItemType dequeue();
        ItemType getFront();
        void display();
        
    private:
        class Node{
            public:
                Node* next;
                ItemType data;
        };

        Node* front;
        int size;
};
#endif
