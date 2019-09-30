#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 20
#define MAXSHIPS 200000

	int aShipStart[MAXSHIPS];
	int aShipEnd[MAXSHIPS];

	int aShipFrom1[MAXSHIPS];
	int aShipToN[MAXSHIPS];

	int compar(const int *val1, const int *val2);

int main() {
	char sInput[MAX_STRING]="";
	char* psInput;
	int nMaxIsland=0;
	int nShipNumber=0;
	int nSmallShipNumber=0;
	int nMiddleIsland=0;
	int i=0;
	int j=0;
	int nFind=0;
	int nTempStart=0;
	int nTempEnd=0;
	int nFrom1Num=0;
	int nToNNum=0;
	
	// read line 1
	gets(sInput);
	psInput = strtok(sInput," ");
	nMaxIsland = atoi(psInput);
	psInput = strtok(NULL," ");
	nShipNumber = atoi(psInput);

	// read line 2
	for (i=0;i<nShipNumber;i++){
		gets(sInput);
		psInput = strtok(sInput," ");
		nTempStart = atoi(psInput);
		psInput = strtok(NULL," ");
		nTempEnd = atoi(psInput);
		if ( nTempStart == 1  ){
			aShipFrom1[nFrom1Num] = nTempEnd;
			nFrom1Num++;
		} else if (nTempEnd == nMaxIsland ){
			aShipToN[nToNNum] = nTempStart;
			nToNNum++;
		}
	}
	// sort
    qsort(aShipFrom1, nFrom1Num, sizeof(int),
        (int (*)(const void *, const void *))compar
    );
    qsort(aShipToN, nToNNum, sizeof(int),
        (int (*)(const void *, const void *))compar
    );
	// search
	i=0;
	while (i<nFrom1Num&&j<nToNNum){
		if (aShipFrom1[i]<aShipToN[j]){
			i++;
		} else if (aShipFrom1[i]>aShipToN[j]){
			j++;
		} else if (aShipFrom1[i]==aShipToN[j]) {
			nFind=1;
			break;
		} else {
			break;
		}
	}
	/*
	for (i=0;i<nSmallShipNumber;i++){
		for (j=0;j<nSmallShipNumber;j++){
			if(aShipStart[j]==aShipEnd[i] ){
					nFind=1;
					break;
			}
		}
		if(nFind==1){
			break;
		}
	}*/

	if (nFind==1){
		printf("POSSIBLE\n");
	} else {
		printf("IMPOSSIBLE\n");
	}

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
./Main.c:34:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccQUDCAs.o: In function `main':
Main.c:(.text.startup+0x3b): warning: the `gets' function is dangerous and should not be used.