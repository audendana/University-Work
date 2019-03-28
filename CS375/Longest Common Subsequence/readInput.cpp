#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string readInput(string fileName){
    string retVal;
    ifstream file;

    file.open(fileName);
    if(!file){
        cout << "Error reading " << fileName << endl; 
        exit(1);
    }

    getline(file, retVal);
    file.close();
    return retVal;
}
