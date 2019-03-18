# Project 2 - Warehouse Simulations

## Project Description

For this project, we will be writing a C program to simulate a warehouse environment.  The job in the warehouse is to assemble kits to send out to customers.  Each kit is made up of many different parts.  Parts are kept in bins in the warehouse.  There are 1000 different kinds of parts in this warehouse, each of which has a part number between 0 and 999. There are 100 bins in the warehouse, bin 0 through 99, and each bin has 10 different kinds of parts. To make things easy, the parts are put sequentially into the bins, so bin 0 has part numbers 0-9, bin 1 has part numbers 10-19, and so on, up to bin 99, which has part numbers 990-999.

The parts that go into each kit are defined by orders that come into the warehouse.  The orders consist of a list of part numbers.  Each part number on an order indicates that you should take one part from the bin that holds that part, and put it in the kit.  The same part may appear multiple times in an order, but you need to put the parts into the kit in the order specified on the order.  For instance, if the order specifies “10 15 10 10 7 9 15 12”, then the kit needs to have one part number 10 from bin 1, followed by one part number 15, followed by two more part number 10’s, followed by one part number 7, and one part number 9, both from bin 0, and  one more part number 15 from bin 1, and finally part number 8 from bin 0.  Customers pay an average of 10 cents per part, so in this example kit, there are 8 parts, so the total revenue is $0.80. You may assume that there are always enough copies of a specific part number in a bin to allow you to fulfill any order.

But here is the trick.  The workbench at which you assemble the kits has exactly 5 slots, where each slot can hold a single bin. Therefore, the workbench can only hold 5 bins at a time.  It starts out with no bins, but once you have filled all five slots on the workbench, and you need a bin that is not already on the workbench, you need to send a bin that *is* on the workbench back to the warehouse and replace it with the new bin that you need.  For instance, for the above order, you first need to fetch bin 1 and put it in a slot on the workbench to fill the first order entry. Then fetch bin 0 to another slot to complete the order.  It costs 10 cents to fetch a bin, and another 5 cents to return a bin. In the above scenario, we needed to fetch two bins but with this simple order, we didn’t need to return any bins, so the total cost was $0.20 to assemble this kit, and the total revenue is only 80 cents, so the net revenue is $0.60. (This is where your salary comes from, so the higher the net profit, the more you make!)

We make money in our warehouse because most kits consist of the same parts over and over again.  In fact, the probability is very high that the next part that goes into the kit is a part that we retrieved for the kit recently. Your job is, knowing that most kits use the same parts, to figure out how to best use the slots on the workbench so that you can maximize your profit.

## Files provided to you

You have been provided with the basic infrastructure for the C code to simulate the warehouse described above. The initial repository contains the following files:

- **warehouse.c** – C source code that contains the main function which simulates the warehouse.  This is the file and function that you need to modify.  The main function, as it is delivered, performs the following tasks:

  -	includes order.h and bench.h.  This provides the prototypes for the functions in order.c and bench.c that you will need to invoke from your warehouse main code.
  - Checks the command line argument to make sure it includes the name of an order file.
  - Invokes the openOrder function to start reading the order file.
  - While there are more part numbers in the order for the kit, main will:
      - Get the next part number in the order, and figure out which bin the part is in.
      - Check to see if that bin is already in slot 0 of the work bench. If not, if there is already a bin in slot 0, return the bin, and fetch the required bin.
      - Invoke the fetchNextPart function which will get the existing part from the bin on the workbench, and put it in the kit, and then check to see if there is another part number in the order. If so, fetchNextPart will return a “1” (true) value.
   - When the order is complete, invokes the closeOrder function which will print out the total cost and revenue for this kit.

- **order.h** and **order.c** – The order.h file is a header file that contains prototypes for the functions that deal with orders for kits. The definition of those functions is in order.c.  Feel free to look over these files to see how they work, but *do not modify these files*. There are four functions of interest, all of which are invoked by the main function in warehouse.c (so you can see how they are used.)

  - `openOrder` – This function takes a character string (an array of characters) that contains the name of an order file as an argument, opens that file, and reads the first part number in the order. It returns a 1 (true) if successful, and a 0 if there is a problem.
  - `nextPartNumber` – This function returns the current part number in the order.
  - `fetchNextPart` – This function virtually picks the current part number from a bin on the bench and puts it into the kit. If the current part number is not in one of the bins on the bench, this function prints a message and halts the program. If the bin is on the bench, the function then checks to see if there is another part number in the order. If there is one, the function reads the part number and returns a 1 (true) value. If not, the function returns a 0 (false) value.
  -	`closeOrder` – This function prints a message that indicates the cost and net earnings for the kit and closes the order file.

- **bench.h**, **benchOrder.h**, and **bench.c** – These files contain the code to manage the workbench in the warehouse. The bench.h file contains prototypes for the functions in bench.c that you will need to use in warehouse.c.  The benchOrder.h file contains prototypes for functions in bench.c that are used in order.c, but are not needed in warehouse.c. The definitions for both sets of functions are in bench.c. Feel free to look over this code to see how things work, but *do not modify this code*. The bench.h file contains a pre-processor #define for NUMSLOTS to define the number of slots available on the workbench.  There are also prototypes for two important functions:

  - `fetchBin` – A function that takes a bin number, and a slot number (between 0 and NUMSLOTS-1) as arguments. If there is already a bin in the specified slot, that bin is returned (and the return charge of $0.05 is added to the cost of this kit). Then, the requested bin is virtually fetched (adding another $0.10 to the cost of the kit) and put into the specified slot on the work bench. This function also prints the configuration of bins on the bench each time it changes.
  - `binInSlot` – This function returns the bin number of the bin currently in the slot specified as the argument. If there is no bin in that slot, a -1 value is returned.

- **order1.txt**, **order2.txt**, and **order3.txt** – These are sample order files you can use to test your code.

- **Makefile** – a make file that contains several targets, as follows:

  - `test` : A pseudo-target to invoke the warehouse executable file for order1.txt, and again for order2.txt
  - `warehouse` :  Creates the warehouse executable file using both the code in warehouse.c and the code in order.c and bench.c
  - `clean `: A pseudo-target to remove the warehouse executable file.

## Working the Project

The repository, as delivered, already implements a very simple (and not very efficient) technique to manage the slots on the workbench in the warehouse. The existing code only uses slot 0, and whenver the required bin is *not* in slot 0, then the bin that is in that slot is returned, and the required bin is fetched from the warehouse. You can make and test this very simple implementation, and discover that you actually *lose* money on the three example orders provided to you if you use this strategy. In fact, this is about the worst you can do.

Your job is to modify the code in warehouse.c to implement a more efficient strategy that will make more money. The trick is to send back the bin that is *least* likely to be needed again in the near future.  If you can do so, then you can reduce the cost of kits, and decrease your cost (or increase your profit).

You may add new functions and / or variables to warehouse.c, and change the code in the main function.  The functions in order.c are intentionally designed to prevent you from looking ahead on the order list. You must fill each order entry as it arrives, before looking at the next order entry.  You may not modify the functions in bench.c or order.c (which keeps track of the cost and benefit of packing a kit.)  I have given three sample orders in the files “order1.txt”, “order2.txt” and “order3.txt”.  Your program should run with any valid order (arbitrary list of part numbers between 0 and 999), but any orders I test with will have the property that part numbers tend to be sequential, but when the sequence is not followed, there is a high probability that the next part number showed up recently on the order.




## Implementation
- First we create an array of ints called binCount[100]. Each time a part from a bin is used we increment binCount[n] by 1.
- Create temporary workbench to keep track of bins.  tempBench[5].
- As we read in the part and get the bin we check to see if the current bin is already in our workbench.
- If its not in our workbench we find the next available space for it.
- If no space is available for it then we need to find a way to remove the bin that will save us the most money.
- To do this I created a list of the total counts of parts used for each bin currently on the workbench.
- The bin with the least used parts is removed and replaced with the new bin.

## Testing
- You can run this program with my own print testing by doing
  ```
  make warehouseWithPrintTest
  ./warehouseWithPrintTest.c order1.txt
  ```
