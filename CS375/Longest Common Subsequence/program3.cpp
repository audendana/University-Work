#include <iostream>
#include <string>
#include <fstream>
#include "readInput.h"
using namespace std;
int recursiveLCSMemo(string str1, string str2, int str1Len, int str2Len, int arr[][100]){
    if(str1Len == 0 || str2Len == 0) return 0; // base case

    if(arr[str1Len-1][str2Len-1] != -1){ // if our value is already in our dynamic array we return it because it does not need to be looked for
        return arr[str1Len-1][str2Len-1];
    }

    if(str1[str1Len-1] == str2[str2Len-1]){ // value wasnt in our dynamic array and there was a match so x_i = y_i
        arr[str1Len-1][str2Len-1] = 1 + recursiveLCSMemo(str1, str2, str1Len-1, str2Len-1, arr);
        return arr[str1Len-1][str2Len-1];
    } else { // value wasnt in our dynamic array and there was no match 
        arr[str1Len-1][str2Len-1] = max(recursiveLCSMemo(str1, str2, str1Len, str2Len-1, arr), recursiveLCSMemo(str1, str2, str1Len-1, str2Len, arr));
        return arr[str1Len-1][str2Len-1];
    }
}

int main(int argc, char const * argv[]){
    if(argc == 4){
        string filex = argv[1];
        string filey = argv[2];
        string outputFile = argv[3];

        string str1 = readInput(filex);
        string str2 = readInput(filey);

        int str1Len = str1.length();
        int str2Len = str2.length();
        int arr[str1Len][100]; // initialize col with 100 so we can pass it into function. 100 is the max length string an input can be

        // memset will initialize values to -1 so we can check for undefined
        memset(arr, -1, sizeof(arr)); // sizeof(arr) == sizeof(arr)*str1Len*100

        ofstream output;
        output.open(outputFile);
        if(!output){
            cout << "Error outputing to " << outputFile <<endl;
            exit(1);
        }
        output << recursiveLCSMemo(str1, str2, str1Len, str2Len, arr) << endl;
        output << "T(n) = str1Len * str2Len" << endl;
        output.close();
    }
    return 0;
}
