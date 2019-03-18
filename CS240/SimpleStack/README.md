#CS240
# Simple Stack Implementation Using Linked Lists.

## Implementation
 - First we define a private node class in Stack.h
 - This node class will be used as our linked list.
 - Stack.h must implement the functions
   1. push() - adds element to the top of the stack.
   2. pop() - pops element(removes) from the top of the stack.
   3. peak() - returns element at the top of the stack.
   4. isEmpty() - checks to see if the stack is empty. If empty return true else return false.
   5. getLength() - returns the length of the stack as an int.
   6. display() - prints the contents of the stack to terminal output.

## Testing
- You can run this program by
  ```
  make
  ./run

  ```
  Then entering the file name of either Test1.txt, Test2.txt, Test3.txt
