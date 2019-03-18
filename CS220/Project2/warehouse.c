#include "order.h"
#include "bench.h"
#include <stdio.h>
#include <stdbool.h>



bool checkIfInTempBench(int tempBench[], int bin){
	for(int i=0;i<5;i++){
		if(tempBench[i] == bin){
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		printf("Unable to open order file %s\n",argv[1]);
		return 1;
	}
	int binCount[100] = {0};
	int tempBench[5] ={-1,-1,-1,-1,-1};

	do {
		int pn=nextPartNumber();
		int bin=pn/10;

		if(!checkIfInTempBench(tempBench, bin)){ // checks to see if the current bin is in the workbench
			// if its not in the workbench we need to find a spot to put it.
			if(binInSlot(0) == -1){ // if first space is available put bin here.
				fetchBin(bin, 0);
				binCount[bin]+=1;
				tempBench[0] = bin;

			} else if(binInSlot(1) == -1){
				fetchBin(bin, 1);
				binCount[bin]+=1;
				tempBench[1] = bin;


			} else if(binInSlot(2) == -1){
				fetchBin(bin, 2);
				binCount[bin]+=1;
				tempBench[2] = bin;

			} else if(binInSlot(3) == -1){
				fetchBin(bin, 3);
				binCount[bin]+=1;
				tempBench[3] = bin;

			} else if(binInSlot(4) == -1){
				fetchBin(bin, 4);
				binCount[bin]+=1;
				tempBench[4] = bin;

			} else { // now if we get here our current bin is not on the workbench and there are no spaces available for it.
				// calculate the least probable used bin currently on the bench and remove it.
				int count[5] = {0};
				for(int i=0;i<5;i++){
					count[i] = binCount[tempBench[i]]; // count of each bin
				}

				int smallest = 0;
				int smallestIndex = 0;
				for(int i=0;i<5;i++){ // get smallest count
					if(i==0){
						smallest = count[i];
						smallestIndex = 0;
					} else{
						if(count[i] < smallest){

							smallest = count[i];
							smallestIndex = i;
						}
					}
				}
				// now we have smallest index to remove
				fetchBin(bin, smallestIndex);
				tempBench[smallestIndex] = bin;
				binCount[bin]+=1;
			}
		} else {
			binCount[bin]+=1;
		}
	} while(fetchNextPart());
	closeOrder();
	return 0;
}
