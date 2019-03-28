#include <iostream>
#include <string>
#include <fstream>
#include "readInput.h"
using namespace std;

void lcs(string str1, string str2, string outputFile){
    int m = str1.length();
    int n = str2.length();
    
    int LCS[m+1][n+1];   // create matrix
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){  // c[i,j] = 0 if i=0 or j=0
                LCS[i][j] = 0;
            } else if(str1[i-1] == str2[j-1]){ // c[i,j] = c[i-1,j-1] if i,j >0 & x_i = y_i
                LCS[i][j] = LCS[i-1][j-1]+1;
            } else {
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]); // c[i,j] = max(c[i,j-1], c[i-1,j]) if i,j >0 & x_i != y_i
            }
        }
    }
    
    int indexOfLCS = LCS[m][n];  // counter for printing
    int lenOfLCS = indexOfLCS; // actual length of LCS
    string lcsString;
    lcsString.resize(indexOfLCS+1); // resizes string to fit the right size;
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){ // if x_i = y_i we know its shared so add it to the LCS string.
            lcsString[indexOfLCS-1] = str1[i-1]; // then decrement counters
            i--;
            j--;
            indexOfLCS--;
        } else if(LCS[i-1][j] > LCS[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    
    if(m <=10 && n <=10){
        ofstream output;
        output.open(outputFile);
        if(!output){
            cout << "Error outputting to " << outputFile << endl;
            exit(1);
        }

        for(int a=0;a<=m;a++){
            for(int b=0;b<=n;b++){
                output << LCS[a][b] << " ";
            }
            output << endl;
        }

        output << "The LCS of " << str1 << " and " << str2<< " is " << lcsString << endl;
        output <<"The length of LCS: " << lenOfLCS << endl;
        output <<"T(n) = m*n" << endl;
        output.close();
    } else {
        ofstream output;
        output.open(outputFile);
        if(!output){
            cout << "Error outputting to " << outputFile << endl;
            exit(1);
        }
        output <<"The length of LCS: " << lenOfLCS << endl;
        output <<"T(n) = m*n" << endl;
        output.close();
    }
}

int main(int argc, char * const argv[]){
    if(argc == 4){
        string filex = argv[1];
        string filey = argv[2];
        string outputFile = argv[3];

        string filexLine = readInput(filex);
        string fileyLine = readInput(filey);

        lcs(filexLine, fileyLine, outputFile);

    }
}
