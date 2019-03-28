# Programming Assignment 1
## Project Description


### This is our recurrence equation

1. c[i,j] = 0 if i=0 or j=0
2. c[i,j] = c[i-1,j-1]+1 if x_i = y_j and i,j >0
3. c[i,j] = max(c[i,j-1], c[i-1,j]) if x_i != y_j and i,j>0


### readInput.cpp
    * This is my helper file just to read input so there is less code duplication.
    * the readInput() function returns the 1 line read in from the inputed file.


### Program 1
    * Write a program the solve LCS with Bottom Up Approach(no recursion).
    * We are given 2 input files each containing 1 line with a string.
    * Pass Input files into readInput()
    * Call LCS function
    * Create an int array of size[str1.length()+1][str2.length()+1]
    * Use for loops to implement our recurrence equation
    * After building our LCS Matrix from the bottom up we know the Len of LCS is stored in the array[str1.length()][str2.length()] index.
    * Then we do a top down loop to get each individual match and add it to a string so we can print the LCS.
    * If our input strings are less than or equal to length 10 print:
        - LCS Matrix
        - LCS String
        - LCS Len
        - Time Complexity
    * If theyre greater than 10 print:
        - LCS Len
        - Time Complexity

### Program 2
    * This program recursively solves the LCS without memoization.
    * This is the slowest approach.
    * Implements the recurrence equation recursively.
    * Outputs:
        - LCS Len
        - Time Complexity

### Program 3
    * This program recursively solves the LCS from top down approach with memoization
    * Implements the same recurrence equation recursively but this time with a extra array for memoization to help solve sub problems faster.
    * Outputs:
        - LCS Len
        - Time Complexity

### Compiling
* literally run make
* if you want to test program1 for example do
```
  make
  ./program1 file1.txt file2.txt output1.txt
```
