#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LIST_SIZE 1001

//Input stdin, output stdout. Obvious use of fd's!
int main(int argc, char* argv[]){
	int testcases, curcase;
	int totalsize, list[MAX_LIST_SIZE];
	uint32_t xor_all;
	int itmp, i;
	int minval = -1, total;

	//Get count of test cases
	fscanf(stdin, "%d", &testcases);

	//Solve all test cases
	for(curcase=1; curcase<=testcases; curcase++){
		//Reset temps for test case
		xor_all = 0;
		minval = -1;
		total = 0;

		//Get number of integers
		fscanf(stdin, "%d\n", &totalsize);

		//Scan in numbers, saving overall XOR to determine yes/no, and candy to give away
		for(i=0; i<totalsize; i++){
			fscanf(stdin, "%d", &itmp);
			if(minval == -1)minval = itmp;
			else if(itmp < minval)minval = itmp;
			total += itmp;
			xor_all = xor_all ^ itmp;
		}

		//Is it possible to not cause crying?
		if(xor_all != 0){
			printf("Case #%d: NO\n", curcase);
			continue;
		}

		//Don't cause crying, but impossibly greedy!
		printf("Case #%d: %d\n", curcase, total-minval);
	}

	return 0;
}
