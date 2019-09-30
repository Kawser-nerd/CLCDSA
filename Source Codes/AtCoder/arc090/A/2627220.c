#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 500

int main() {
	char sInput[MAX_STRING+1]="";
	char* psInput;

	int i=0;
	int nA=0;
	int nB=0;
	int nC=0;
	int nHands=0;
	int nMax=0;
	int nColumns=0;
	int nUpPoints[101];
	int nDownPoints[101];
	int nSubTotal=0;
	int nMaxTotal=0;

	// read line 1
	gets(sInput);
	nColumns = atoi(sInput);
	// read line 2
	gets(sInput);
	psInput = strtok(sInput," ");
	for (i=0;i<nColumns&&psInput;i++){
		nUpPoints[i] = atoi(psInput);
		nSubTotal=nSubTotal+nUpPoints[i];
		psInput = strtok(NULL," ");
	}
	// read line 3
	gets(sInput);
	psInput = strtok(sInput," ");
	for (i=0;i<nColumns&&psInput;i++){
		nDownPoints[i] = atoi(psInput);
		psInput = strtok(NULL," ");
	}
	nSubTotal=nSubTotal+nDownPoints[nColumns-1];
	nMaxTotal=nSubTotal;

	for(i=nColumns-1;i>0;i--){
		nSubTotal=nSubTotal-nUpPoints[i]+nDownPoints[i-1];
		if ( nMaxTotal<nSubTotal){
			nMaxTotal=nSubTotal;
		}
	}


	printf("%d\n",nMaxTotal);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccjpB7Na.o: In function `main':
Main.c:(.text.startup+0x53): warning: the `gets' function is dangerous and should not be used.