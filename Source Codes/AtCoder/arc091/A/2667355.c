#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 100

	char sInput[MAX_STRING+1]="";

int main() {
	char* psInput;

	long nA=0;
	long nB=0;
	long nTemp=0;
	long nAnswer=0;

	// read line 1
	gets(sInput);
	psInput = strtok(sInput," ");
	nA = atol(psInput);
	psInput = strtok(NULL," ");
	nB = atol(psInput);

	if(nA>nB){
		nTemp=nA;
		nA=nB;
		nB=nTemp;
	}

	switch(nA){
	case 1:
		if(nB==1){
			nAnswer=1;
		} else {
			nAnswer=nB-2;
		}
		break;
	case 2:
		// do nothing
		break;
	default:
		nAnswer=(nA-2)*(nB-2);
		break;
	}

	printf("%ld\n",nAnswer);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccgmioHe.o: In function `main':
Main.c:(.text.startup+0x9): warning: the `gets' function is dangerous and should not be used.