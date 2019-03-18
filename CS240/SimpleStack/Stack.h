// file: Stack.h
#ifndef STACK_
#define STACK_

typedef double ItemType;

class Stack{
    public:
        Stack();
        bool push(const ItemType& newItem);
        ItemType pop();
        ItemType peak() const;
        bool isEmpty() const;
        int getLength() const;
        ~Stack();
        void display();

    private:
        class Node{
            public:
                Node* next;
                ItemType data;
        };
        Node* top;
        Node* bot;
        int size;
};
#endif
