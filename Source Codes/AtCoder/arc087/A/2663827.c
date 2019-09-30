#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 50

	char sInput[MAX_STRING+1]="";
	int anX[100000];
	int anY[100000];

	int compar(const int *val1, const int *val2);

int main() {
//	char* psInput;

	int i=0;
	int j=0;
	int nNumber=0;
	int nTargetNumber=0;
	int nLastTarget=0;
	int nFriends=0;
	int nNeedChanges=0;

	// read line 1
    scanf("%d", &nNumber);
	// read line 2
	for(i=0; i<nNumber; i++) {
        scanf("%d", &anX[i]);
	}
	// sort
    qsort(anX, nNumber, sizeof(int),
        (int (*)(const void *, const void *))compar
    );
	nTargetNumber=anX[0];
	nLastTarget=anX[nNumber-1];
	for (i=0;i<nNumber;i++){
		if (anX[i]==nTargetNumber){
			nFriends++;
		} else {
			// ???????????????????
			if (nFriends<nTargetNumber){
				nNeedChanges=nNeedChanges+nFriends;
			} else if (nFriends>nTargetNumber){
				nNeedChanges=nNeedChanges+(nFriends-nTargetNumber);
			}
			// ????????
			nTargetNumber=anX[i];
			nFriends=1;
		}
	}
	// ??????????
	if (nFriends>0){
		if (nFriends<nTargetNumber){
			nNeedChanges=nNeedChanges+nFriends;
		} else if (nFriends>nTargetNumber){
			nNeedChanges=nNeedChanges+(nFriends-nTargetNumber);
		}
	}

	printf("%d\n",nNeedChanges);
	

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
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &nNumber);
     ^
./Main.c:31:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &anX[i]);
         ^