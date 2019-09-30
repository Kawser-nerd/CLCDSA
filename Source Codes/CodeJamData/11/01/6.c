#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ORANGE 0
#define BLUE   1

typedef struct{
	uint8_t robot;
	int position;
} PushType;

typedef struct{
	int position;
	int t;
} InfoType;

inline int maxi(int a, int b){ return a>b?a:b; }
inline int absi(int a){ return a<0?-a:a; }
inline int get_robot(char c){ return c=='O'?ORANGE:BLUE; }

//Assume input comes from stdin, output to stdout...
int main(int argc, char* argv[]){
	int casecount, terms, lastevent = 0, curcase, place;
	char color;
	InfoType robots[2];

	//Read case counts
	fscanf(stdin, "%d\n", &casecount);

	//Solve all cases
	for(curcase=1; curcase<=casecount; curcase++){
		//Clear temp for cases
		robots[0] = robots[1] = (InfoType){ 1, 0 };
		lastevent = 0;

		//Load the case, solving it as we go
		fscanf(stdin, "%d ", &terms);
		for(; terms>0; terms--){
			fscanf(stdin, "%c %d ", &color, &place);

			//Find minimum time to solve press - must be after previous, reachable
			lastevent = maxi(absi(robots[get_robot(color)].position - place)+1+robots[get_robot(color)].t, lastevent+1);
			robots[get_robot(color)].position = place;
			robots[get_robot(color)].t = lastevent;
		}

		//Print result
		printf("Case #%d: %d\n", curcase, lastevent);
	}
}
