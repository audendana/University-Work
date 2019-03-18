//map.h
#ifndef MAP_
#define MAP_

#include"mapInterface.h"

class map{
    public:
        map();
        ~map(); // Destructor
        map(const map& origClass); // Copy Constructor
        map& operator=(const map& objToCopy); // Operator=
        bool empty() const; // returns true if empty false otherwise
        int size() const; // returns size of map
        bool add(ElementType element); // adds element, returns true if successful
        bool find(KeyType key) const; // returns true if key is found in map
        ValueType retrieve(KeyType key) const; // returns valuetype 
                                               // of key if found, otherwise nullptr
        bool remove(KeyType key); // returns true if remove successful
        void displayAll() const; // display Key and value pairs
    private:
        class Node{
            public:
                Node* next;
                ElementType data;
        };

        Node* head;
        Node* tail;
        int sizeOfMap;


};

#endif
