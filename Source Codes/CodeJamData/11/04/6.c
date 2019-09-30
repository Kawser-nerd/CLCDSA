#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LIST_SIZE 1001

//Input stdin, output stdout. Obvious use of fd's!
int main(int argc, char* argv[]){
	int testcases, curcase;
	int totalsize, inorder;
	int itmp, i;

	//Get count of test cases
	fscanf(stdin, "%d", &testcases);

	//Solve all test cases
	for(curcase=1; curcase<=testcases; curcase++){
		//Reset temps for test case
		inorder = 0;

		//Get number of integers
		fscanf(stdin, "%d\n", &totalsize);

		//Scan in numbers, taking into account those already in order
		for(i=1; i<=totalsize; i++){
			fscanf(stdin, "%d", &itmp);
			if(i == itmp)inorder++;
		}

		//Calculate expected number of hits...
		printf("Case #%d: %d.000000\n", curcase, (totalsize-inorder));
	}

	return 0;
}
