#include <iostream>
#include <string>
#include <fstream>
#include "readInput.h"
using namespace std;

int recursiveLCSLength(string str1, string str2, int str1Len, int str2Len){
    if(str1Len ==0 || str2Len == 0) return 0; // base case

    if(str1[str1Len-1] == str2[str2Len-1]){
        return 1 + recursiveLCSLength(str1, str2,str1Len-1, str2Len-1); // x_i = y_i
    } else {
        return max(recursiveLCSLength(str1, str2, str1Len, str2Len-1), recursiveLCSLength(str1, str2, str1Len-1, str2Len)); // x_i != y_i
    }
}

int main(int argc, char const *argv[]){
    if(argc ==4){
        string filex = argv[1];
        string filey = argv[2];
        string outputFile = argv[3];

        string str1 = readInput(filex);
        string str2 = readInput(filey);

        int str1Len = str1.length();
        int str2Len = str2.length();

        ofstream output;
        output.open(outputFile);
        if(!output){
            cout <<"Error outputing to " << outputFile << endl;
            exit(1);
        }

        output << recursiveLCSLength(str1, str2, str1Len, str2Len) << endl;
        output << "T(n) = 2^n" << endl;
        output.close();
    }
    return 0;
}
