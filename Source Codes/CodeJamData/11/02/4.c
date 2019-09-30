#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 101

typedef struct{
	uint8_t with[26];
} Combination;

//Assume in->stdin, out->stdout
int main(int argc, char* argv[]){
	int testcases, curcase;
	char element_list[MAX_ELEMENT_SIZE], el;
	Combination combos[26], opposed[26];
	int elist_size, itmp, i;

	//Get number of test cases
	fscanf(stdin, "%d\n", &testcases);

	//Loop over, solve test cases
	for(curcase=1; curcase<=testcases; curcase++){
		//Clear temps for test case
		memset(combos, 0, sizeof(Combination)*26);
		memset(opposed, 0, sizeof(Combination)*26);
		elist_size = 0;

		//Load in combinations
		fscanf(stdin, "%d", &itmp);
		for(; itmp>0; itmp--){
			//Load the combo info
			fscanf(stdin, "%s", element_list);
			combos[element_list[0]-'A'].with[element_list[1]-'A'] = element_list[2];
			combos[element_list[1]-'A'].with[element_list[0]-'A'] = element_list[2];
		}

		//Load in opposed elements
		fscanf(stdin, "%d", &itmp);
		for(; itmp>0; itmp--){
			//Load the opposition info
			fscanf(stdin, "%s", element_list);
			opposed[element_list[0]-'A'].with[element_list[1]-'A'] = 1;
			opposed[element_list[1]-'A'].with[element_list[0]-'A'] = 1;
		}

		//Solve the puzzle as we load
		fscanf(stdin, "%d ", &itmp);
		for(; itmp>0; itmp--){
			//Get next element
			fscanf(stdin, "%c", &el);
			element_list[elist_size] = el;
			elist_size++;

			//Possible for _anything_ to happen?
			if(elist_size <= 1){
				continue;
			}

			//Combinations have precedence
			if(combos[el-'A'].with[element_list[elist_size-2]-'A'] != 0){
				element_list[elist_size-2] = combos[el-'A'].with[element_list[elist_size-2]-'A'];
				elist_size--;
				continue;
			}

			//Check for opposition
			for(i=0; i<elist_size; i++){
				if(opposed[el-'A'].with[element_list[i]-'A'] != 0){
					elist_size = 0;
					break;
				}
			}
		}

		//Print out result
		printf("Case #%d: [", curcase);
		for(i=0; i<elist_size-1; i++)printf("%c, ", element_list[i]);
		if(elist_size > 0)printf("%c", element_list[elist_size-1]);
		printf("]\n");
	}

	return 0;
}
