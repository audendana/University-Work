#include <iostream>
#include <fstream>
#include <sstream>
#include "Stack.h"
using namespace std;

// returns the file name from the user
string getFileName();

// proccess' reading the file's input
void readFile(ifstream& file);

// takes each line of file and proccess' the operations
// returns evaluated answer
double process(string line);


int main(){
    ifstream file;
    string fileName = getFileName();
    file.open(fileName);
    if(file.is_open()){
        readFile(file);
    } else {
        cout << "Erorr file could not be opened." << endl;
    }
    file.close();

    
}

string getFileName(){

    // gets file name from user
    string fileName;
    cout << "Please enter the file name: ";
    cin >> fileName;
    return fileName;
}

void readFile(ifstream& file){
    string contents;
    double finalVal;
    int lineNum = 1;
    while(!file.eof()){

        // read each line of file individually
        getline(file, contents);

        //vars for error checking
        bool valid = true;
        int operationCount = 0;
        int operandCount = 0 ;
        int notOperands = 0;
        int numSpaces = 0;
        int numDecim = 0;

        istringstream iss(contents);
        string token;


        // get num of operands and num of not operands
        while(iss >> token){
            try{
                std::stod(token);
                operandCount++;
            } catch(invalid_argument& ia){
                notOperands++;
            }
        }

        //check to see if num of operations is 1 less than num of operands
        //we do this to see if there is an invalid amount of operations entered
        if(notOperands != operandCount -1){
            valid = false;
        }

        // check for blank line
        if(contents.length() == 0){
            valid = false;
        }

       // check for alpha chars 
        for(int i=0;i<contents.length();i++){
            if(isalpha(contents[i])){
                valid = false;
            }
        }

        if(valid){
            finalVal = process(contents);
            cout <<"The result of evaluating " << contents << " is " << finalVal << endl;
        } else {
            cout <<"Error one line " << lineNum << endl;
        }
        lineNum++;
    }
}

double process(string line){
    Stack myStack;
    istringstream iss(line);
    string token;

    // get the line from the file and read line token by token
    while(iss >> token){
        try{
            // try to see if token is double if it is add to stack
            double convertedVal = std::stod(token);
            myStack.push(convertedVal);
        } catch (std::invalid_argument& ia){

            // if we get here we know token is not a double and we check to see what
            // operator it is
            if(!myStack.isEmpty()){

                // this part does the computation of the numbers
                // by popping them off the stack applying the operation
                // then pushing the newly evaluated number back onto the stack
                double num1;
                double num2;
                if(myStack.getLength() > 1){
                    num2 = myStack.pop();
                    num1 = myStack.pop();
                    double newNum;
                    if(token == "+"){
                        newNum = num2 + num1;
                        myStack.push(newNum);
                    } else if(token =="-"){
                        newNum = num1 - num2;
                        myStack.push(newNum);
                    } else if(token =="*"){
                        newNum = num1 * num2;
                        myStack.push(newNum);
                    } else if(token == "/"){
                        if(num2 != 0){
                            newNum = num1 / num2;
                            myStack.push(newNum);
                        } else {
                            cout << "Error divide by zero" << endl;
                        }
                    }
                } else {

                }

            }
        }
    }
    double finalVal;
    if(!myStack.isEmpty()){
        finalVal = myStack.pop();
    }

    return finalVal;

}
