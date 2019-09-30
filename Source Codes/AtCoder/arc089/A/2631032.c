#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 30

	int anTime[100001];
	int anX[100001];
	int anY[100001];

int main() {
	char sInput[MAX_STRING+1]="";
	char* psInput;

	int i=0;
	int nPointNumber=0;
	int nFailed=0;
	int nTimeCounter=1;
	int nLeftTime=0;
	int nXDistance=0;
	int nYDistance=0;
	int nSumDistance=0;
	int nTempNumber=0;

	// read line 1
	gets(sInput);
	nPointNumber = atoi(sInput);

	anTime[0]=0;
	anX[0]=0;
	anY[0]=0;

	// read line 2 ~
	for (i=1;i<=nPointNumber;i++){
		gets(sInput);
		psInput = strtok(sInput," ");
		anTime[i] = atoi(psInput);
		psInput = strtok(NULL," ");
		anX[i] = atoi(psInput);
		psInput = strtok(NULL," ");
		anY[i] = atoi(psInput);
	}

	while(nFailed==0 && nTimeCounter<=nPointNumber){
		nLeftTime=anTime[nTimeCounter]-anTime[nTimeCounter-1];
		nXDistance=abs(anX[nTimeCounter]-anX[nTimeCounter-1]);
		nYDistance=abs(anY[nTimeCounter]-anY[nTimeCounter-1]);
		nSumDistance=nXDistance+nYDistance;

		if ( nLeftTime < nSumDistance ){
			nFailed=1;
		} else {
			nTempNumber = nLeftTime - nSumDistance;
			if ( nTempNumber % 2 == 1 ){
				nFailed=1;
			} 
		}

		nTimeCounter++;
	}


	if (nFailed>0){
		printf("No\n");
	} else {
		printf("Yes\n");
	}

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccatbKLg.o: In function `main':
Main.c:(.text.startup+0x4a): warning: the `gets' function is dangerous and should not be used.