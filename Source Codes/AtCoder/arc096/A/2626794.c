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
	int nPriceA=0;
	int nPriceB=0;
	int nPriceAB=0;
	int nNeedsA=0;
	int nNeedsB=0;
	int nNeedsAB=0;
	int nNeedsAPair=0;
	int nNeedsBPair=0;
	int nTotal=0;
	int nSubTotal=0;
	int nTotal1=0;
	int nSubTotal1=0;
	int nSubA=0;
	int nTotal2=0;
	int nSubTotal2=0;
	int nSubB=0;

	// read line 1
	gets(sInput);
	psInput = strtok(sInput," ");
	nPriceA = atoi(psInput);
	psInput = strtok(NULL," ");
	nPriceB = atoi(psInput);
	psInput = strtok(NULL," ");
	nPriceAB = atoi(psInput);
	psInput = strtok(NULL," ");
	nNeedsA = atoi(psInput);
	psInput = strtok(NULL," ");
	nNeedsB = atoi(psInput);

	if ( nNeedsA > nNeedsB ){
		nNeedsA = nNeedsA - nNeedsB;
		nNeedsAB = nNeedsB;
		nNeedsB = 0;
	} else if ( nNeedsA < nNeedsB ){
		nNeedsB = nNeedsB - nNeedsA;
		nNeedsAB = nNeedsA;
		nNeedsA = 0;
	} else {
		nNeedsAB = nNeedsA;
		nNeedsA = 0;
		nNeedsB = 0;
	}

	// buy AB or A and B
	if ( nPriceA+nPriceB < nPriceAB*2 ) {
		nSubTotal=(nPriceA+nPriceB)*nNeedsAB;
	} else {
		nSubTotal=nPriceAB*2*nNeedsAB;
	}
	nSubA=nNeedsAB;
	nSubB=nNeedsAB;

	// buy A
	if ( nNeedsA >0 ){
		if ( nPriceA < nPriceAB*2 ){
			nSubTotal=nSubTotal+nPriceA*nNeedsA;
			nSubA=nSubA+nNeedsA;
		} else {
			nSubTotal=nSubTotal+nPriceAB*2*nNeedsA;
			nSubA=nSubA+nNeedsA;
			nSubB=nSubB+nNeedsA;
		}
	}
	// buy B
	if ( nNeedsB >0 ){
		if ( nPriceB < nPriceAB*2 ){
			nSubTotal=nSubTotal+nPriceB*nNeedsB;
			nSubB=nSubB+nNeedsB;
		} else {
			nSubTotal=nSubTotal+nPriceAB*2*nNeedsB;
			nSubA=nSubA+nNeedsB;
			nSubB=nSubB+nNeedsB;
		}
	}


	printf("%d\n",nSubTotal);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccCspChw.o: In function `main':
Main.c:(.text.startup+0x45): warning: the `gets' function is dangerous and should not be used.