#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 600000 
#define MAXCARDS 100000
#define MAXNUM 100000
int alNumber[MAXCARDS];
int alTimes[MAXNUM];
char sInput[MAX_STRING];
int compare(const int *val1, const int *val2);

int main() {

	char* psInput;
	int l=0;
	int i=0;
	int j=0;
	int lTemp2=0;
	int lKinds=0;
	int  lCardsNumber =0;
	int  lMax = 0;
	int  lTop = 0;
	int  lSecond = 0;
	int  lSquare = 0;
	int  lTarget=0;
	int  lFound=0;
	int  lAnswer=0;
	int  lTimes=0;
	int  lNumber=0;
	int  lBefore=0;
	int  lCount=0;
	int nFlag=0;

	// read line 1
	gets(sInput);
	lCardsNumber = atol(sInput);
	//format
	for (i=0;i<MAXNUM;i++){
		alNumber[i]=-1;
		alTimes[i]=0;
	}
	// read line 2
	gets(sInput);
	psInput = strtok(sInput," ");
	for (i=0;i<lCardsNumber;i++){
		lTemp2=atol(psInput);
		alNumber[i]=lTemp2;
		if(lMax<lTemp2){
			lMax=lTemp2;
		}
		psInput = strtok(NULL," ");
	}
    qsort(alNumber, lCardsNumber, sizeof(int),
        (int (*)(const void *, const void *))compare
    );

	for (i=0;i<=lMax;i++){
		lCount=0;
		while(j<lCardsNumber && alNumber[j]==i){
			lCount++;
			j++;
		}
		alTimes[i]=lCount;
	}
	if(lMax>=2){
		for (i=2;i<=lMax;i++){
			lTemp2=alTimes[i-2]+alTimes[i-1]+alTimes[i];
			if (lAnswer<lTemp2){
				lAnswer=lTemp2;
			}
		}
	} else {
		lAnswer=alTimes[0];
		if(lMax==1){
			lAnswer=lAnswer+alTimes[1];
		}
	}

	printf("%d\n",lAnswer);

    return 0;
}

int compare(const int *val1, const int *val2) {
    if ( *val1 < *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/cczu8UT0.o: In function `main':
Main.c:(.text.startup+0x10): warning: the `gets' function is dangerous and should not be used.