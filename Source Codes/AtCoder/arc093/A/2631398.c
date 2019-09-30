#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 600000

	int anX[100002];
	char sInput[MAX_STRING+1]="";

int main() {
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
	int nMagicNumber=0;
	int nSubTotal=0;
	int nTotal=0;
	int nOrgRoute=0;
	int nShortCutRoute=0;

	// read line 1
	gets(sInput);
	nPointNumber = atoi(sInput);

	anX[0]=0;

	// read line 2 ~
	gets(sInput);
	psInput = strtok(sInput," ");
	for (i=1;i<=nPointNumber;i++){
		anX[i] = atoi(psInput);
		psInput = strtok(NULL," ");
	}
	anX[nPointNumber+1]=0;

	for(i=1;i<=nPointNumber+1;i++){
		nSubTotal=nSubTotal+abs(anX[i]-anX[i-1]);
	}

	for(nMagicNumber=1;nMagicNumber<=nPointNumber;nMagicNumber++){
		nOrgRoute = abs(anX[nMagicNumber]-anX[nMagicNumber-1])+abs(anX[nMagicNumber+1]-anX[nMagicNumber]);
		nShortCutRoute = abs(anX[nMagicNumber+1]-anX[nMagicNumber-1]);

		printf("%d\n",nSubTotal-nOrgRoute+nShortCutRoute);
	}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccHr6lGZ.o: In function `main':
Main.c:(.text.startup+0x12): warning: the `gets' function is dangerous and should not be used.