#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 100

	char sInput[MAX_STRING+1]="";
	int anX[200000];
	int anY[200000];
	int compar(const int *val1, const int *val2);

int main() {
//	char* psInput;

	int i=0;
	int j=0;
	int nMin=0;
	int nMax=0;
	int nNow=0;
	int nCount=0;
	int nNumber=0;
	int nMiddleIndex=0;
	int nTempMiddle=0;
	int nFirstMiddle=0;
	int nSecondMiddle=0;

	// read line 1
    scanf("%d", &nNumber);
	// read line 2
	for(i=0; i<nNumber; i++) {
        scanf("%d", &anX[i]);
		anY[i]=anX[i];
	}
	// sort
    qsort(anY, nNumber, sizeof(int),
        (int (*)(const void *, const void *))compar
    );
	nMiddleIndex=(nNumber/2)-1;
	nFirstMiddle=anY[nMiddleIndex];
	nSecondMiddle=anY[nMiddleIndex+1];

	if (nNumber==2){
		printf("%d\n%d\n",anX[1],anX[0]);
	} else {
		for (i=0; i<nNumber; i++){
			if(anX[i]<nFirstMiddle){
				printf("%d\n",nFirstMiddle);
			} else {
				printf("%d\n",nSecondMiddle);
			}
		}
	}

    return 0;
}
int compar(const int *val1, const int *val2) {
    if ( *val1 > *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
} ./Main.c: In function ‘main’:
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &nNumber);
     ^
./Main.c:34:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &anX[i]);
         ^