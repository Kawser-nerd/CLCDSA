#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 500

int compar(const int *val1, const int *val2);

int main() {
	char sInput[MAX_STRING+1]="";
	char* psInput;

	int i=0;
	int nX[3];
	int nA=0;
	int nB=0;
	int nC=0;
	int nHands=0;
	int nMax=0;

	// read line 1
	gets(sInput);
	psInput = strtok(sInput," ");
	nX[0] = atoi(psInput);
	psInput = strtok(NULL," ");
	nX[1] = atoi(psInput);
	psInput = strtok(NULL," ");
	nX[2] = atoi(psInput);

	// sort
    qsort(nX, 3, sizeof(int),
        (int (*)(const void *, const void *))compar
    );
//		printf("%d,%d,%d\n",nX[0],nX[1],nX[2]);

	while (nX[0]!=nX[2] || nX[1]!=nX[2]){
		if(nX[0]<nX[2]&&nX[1]<nX[2]){
			nX[0]=nX[0]+1;
			nX[1]=nX[1]+1;
			nHands++;
		} else if (nX[0]<nX[2]&&nX[1]==nX[2]) {
			nX[0]=nX[0]+2;
			nHands++;
		} else if (nX[0]>nX[2]&&nX[0]>nX[2]) {
			nX[1]=nX[1]+1;
			nX[2]=nX[2]+1;
			nHands++;
		}
	}


	printf("%d\n",nHands);

    return 0;
}
int compar(const int *val1, const int *val2) {
    if ( *val1 < *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccsfWeO0.o: In function `main':
Main.c:(.text.startup+0x40): warning: the `gets' function is dangerous and should not be used.