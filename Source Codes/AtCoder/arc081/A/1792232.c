#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 2200000 
#define MAXCARDS 100000

long long alNumber[MAXCARDS];
long long alTimes[MAXCARDS];
char sInput[MAX_STRING];
int compare(long long*a,long long*b);
	int main() {

	char* psInput;
	long long l=0;
	int i=0;
	int j=0;
	long long lTemp2=0;
	long long lKinds=0;
	long long  lCardsNumber =0;
	long long  lMax = 0;
	long long  lTop = 0;
	long long  lSecond = 0;
	long long  lSquare = 0;
	long long  lTarget=0;
	long long  lFound=0;
	long long  lAnswer=0;
	long long  lTimes=0;
	long long  lNumber=0;
	long long  lBefore=0;
	long long  lCount=0;
	int nFlag=0;

	// read line 1
	gets(sInput);
	lCardsNumber = atol(sInput);
	//format
/*	for (i=0;i<lCardsNumber;i++){
//		alNumber[i]=0;
		alTimes[i]=0;
	}*/
	// read line 2
	gets(sInput);
	psInput = strtok(sInput," ");
	for (i=0;i<lCardsNumber;i++){
		alNumber[i]=atol(psInput);
		psInput = strtok(NULL," ");
	}
    qsort(alNumber, lCardsNumber, sizeof(long long),
        (int (*)(const void *, const void *))compare
    );

	for (i=lCardsNumber-1;i>=0;i--){
		lNumber=alNumber[i];
		nFlag=0;
		if (lBefore==lNumber){
			lCount++;
			nFlag=1;
		} 
		if (nFlag==0||i==0) {
			if(lCount>=4&&lSquare==0){
				lSquare=lBefore;
			}
			if(lCount>=2){
				if(lTop==0){
					lTop=lBefore;
				} else if (lSecond==0) {
					lSecond=lBefore;
				}
			}
			lBefore = lNumber;
			lCount=1;
		}
		if (lSquare>0||(lTop>0&&lSecond>0)){
			break;
		}
	}
	lAnswer=lTop*lSecond;
	if (lAnswer<lSquare*lSquare){
			lAnswer=lSquare*lSquare;
	}
	printf("%ld\n",lAnswer);

    return 0;
}

int compare(long long*a,long long*b){
    unsigned long long v=*b-*a;
    return v?(v>>63<<1)-1:0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
./Main.c:83:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%ld\n",lAnswer);
         ^
/tmp/ccqqdBRN.o: In function `main':
Main.c:(.text.startup+0xe): warning: the `gets' function is dangerous and should not be used.