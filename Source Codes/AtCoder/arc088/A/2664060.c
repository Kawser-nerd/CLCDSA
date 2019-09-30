#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 100

	char sInput[MAX_STRING+1]="";


int main() {
	char* psInput;

	int i=0;
	int j=0;
	long long nMin=0;
	long long  nMax=0;
	long long  nNow=0;
	long long  nCount=0;

	// read line 1
	gets(sInput);
	psInput = strtok(sInput," ");
	nMin = atoll(psInput);
	psInput = strtok(NULL," ");
	nMax = atoll(psInput);

	nNow=nMin;

	while(nNow<=nMax){
		nCount++;
		nNow=nNow*2;
	}

	printf("%lld\n",nCount);
	

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccREr8N4.o: In function `main':
Main.c:(.text.startup+0x9): warning: the `gets' function is dangerous and should not be used.