#include <stdio.h>
#include <stdlib.h>

FILE *ifp;
FILE *ofp;

int T;
int X, R, C;

int process();
void output(int, int);

int main(void){
	int i, j;

	ifp = fopen("D-small-attempt3.in", "r");
	ofp = fopen("output.txt","w");

	fscanf(ifp, "%d", &T);
	
	for(i=0;i<T;i++){
		fscanf(ifp, "%d %d %d", &X, &R, &C);
		output(i+1, process());
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

int process(){
	if((R*C)%X!=0)
		return 0;

	switch(X){
	case 3:
		if(R*C==3)
			return 0;
		break;
	case 4:
		if(R*C==4 || R*C==8)
			return 0;
		break;
	}

	return 1;
}

void output(int t, int res){
	fprintf(ofp, "Case #%d: %s\n", t, res?"GABRIEL":"RICHARD");
	//fprintf(ofp, "Case #%d: (%d,%d,%d) %s\n", t, X,R,C, res?"GABRIEL":"RICHARD");
}