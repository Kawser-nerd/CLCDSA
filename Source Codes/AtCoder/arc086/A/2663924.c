#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 50

	char sInput[MAX_STRING+1]="";
	int anX[200001];
	int anY[100000];

	int compar(const int *val1, const int *val2);

int main() {
//	char* psInput;

	int i=0;
	int j=0;
	int nNumber=0;
	int nTargetKind=0;
	int nTemp=0;
	int nTargetNumber=0;
	int nLastTarget=0;
	int nFriends=0;
	int nMustBeRemoved=0;

	// read line 1
    scanf("%d", &nNumber);
    scanf("%d", &nTargetKind);
	// read line 2
	for(i=0; i<nNumber; i++) {
        scanf("%d", &nTemp);
		anX[nTemp]=anX[nTemp]+1;
	}
	// sort
    qsort(anX, 200001, sizeof(int),
        (int (*)(const void *, const void *))compar
    );

	// calc
	for(i=0; i<=200000; i++) {
		if(anX[i]>0){
			if(nTargetKind>0){
				nTargetKind--;
			} else {
				nMustBeRemoved=nMustBeRemoved+anX[i];
			}
		}
	}
	printf("%d\n",nMustBeRemoved);
	

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
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &nNumber);
     ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &nTargetKind);
     ^
./Main.c:34:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &nTemp);
         ^