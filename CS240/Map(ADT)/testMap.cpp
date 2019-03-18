// program.cpp
#include<iostream>
#include"map.h"

int main(){
    map myMap;

    std::cout << "isEmpty(): " << myMap.empty() << std::endl;
    std::cout <<"size(): " << myMap.size() << std::endl;

    ElementType pair1 = std::make_pair(1, new string("Pair1"));
    ElementType pair2 = std::make_pair(2, new string("Pair2"));
    ElementType pair3 = std::make_pair(3, new string("Pair3"));
    ElementType pair4 = std::make_pair(4, new string("Pair4"));
    ElementType pair5 = std::make_pair(5, new string("Pair5"));
    ElementType dup = std::make_pair(1, new string("Pair2"));
    
    std::cout <<"add(pair1): " << myMap.add(pair1) << std::endl;
    std::cout <<"add(pair2): " << myMap.add(pair2) << std::endl;
    std::cout <<"add(pair3): " << myMap.add(pair3) << std::endl;
    std::cout <<"add(pair4): " << myMap.add(pair4) << std::endl;
    std::cout <<"add(pair5): " << myMap.add(pair5) << std::endl;
    std::cout <<"add(dup): " << myMap.add(dup) << std::endl;
    std::cout <<"size(): " << myMap.size() << std::endl;
    myMap.displayAll();

    std::cout <<"remove(4): " << myMap.remove(4) << std::endl;
    std::cout <<"remove(5): " << myMap.remove(5) << std::endl;

    myMap.displayAll();

    std::cout <<"remove(1): " << myMap.remove(1) << std::endl;
    ElementType pair6 = std::make_pair(6, new string("Pair6"));
    std::cout <<"add(pair6): " << myMap.add(pair6) << std::endl;
    myMap.displayAll();
    std::cout <<"size(): " << myMap.size() << std::endl;

    std::cout <<"find(1): " << myMap.find(1) << std::endl;
    std::cout <<"find(6): " << myMap.find(6) << std::endl;

    std::cout <<"retrieve(6): " << *myMap.retrieve(6) << std::endl;
    std::cout <<"retrieve(1): " << myMap.retrieve(1) << std::endl;

    std::cout <<std::endl;
    map map2 = myMap;
    map2.displayAll();

    std::cout <<std::endl;
    map map3;
    map3 = map2;
    std::cout<<"Displaying map3 operator=" << std::endl;
    map3.displayAll();
}
