#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 300000

	char sInput[MAX_STRING+1]="";


int main() {
//	char* psInput;
	char sInput2[30]="";

	int i=0;
	int j=0;
	int nMin=999999;
	int nLen=0;
	int nMismatch=0;
	char cCorrect=' ';

	// read line 1
	gets(sInput2);
	nLen = atoi(sInput2);

	// read line 2
	gets(sInput);

	//first callenge
	i=0;
	for(j=1;j<nLen;j++){
		if ('W'!=sInput[j]){
			nMismatch++;
		}
	}
	if(nMin>nMismatch){
		nMin=nMismatch;
	}
	//2nd case or lator
	for (i=1;i<nLen;i++){
		// ???????????????????????????????????
		if(sInput[i]!='W'){
			nMismatch--;
		}
		// ?????????????
		if(sInput[i-1]!='E'){
			nMismatch++;
		}
		if(nMin>nMismatch){
			nMin=nMismatch;
		}

	}

	printf("%d\n",nMin);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput2);
  ^
/tmp/ccRIM0Da.o: In function `main':
Main.c:(.text.startup+0x43): warning: the `gets' function is dangerous and should not be used.