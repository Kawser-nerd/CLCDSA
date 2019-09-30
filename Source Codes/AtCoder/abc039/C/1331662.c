#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 20

int main() {

	char sInput[MAX_STRING+1]="";
	char sKeys[37] = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
	char sAnswer[3] = "";

	int nAnswer=0;
	int nKeepMatching=0;
	int nLookingIndex=0;
	int i=0;
	int j=0;

	// read line 1
	gets(sInput);
	for (i=0;i<7;i++){
		nKeepMatching=1;
		for (j=0;j<MAX_STRING;j++){
			if (sInput[j] != sKeys[nLookingIndex+j] ){
				nKeepMatching=0;
				break;
			}
		}
		if (nKeepMatching == 1){
			nAnswer=i;
			break;
		} else {
			if (sKeys[nLookingIndex+1]=='B'){
				nLookingIndex++;
			}
		}
		nLookingIndex++;
	}

	switch( nAnswer ){
	case 0:
		strcpy(sAnswer,"Do");
		break;
	case 1:
		strcpy(sAnswer,"Re");
		break;
	case 2:
		strcpy(sAnswer,"Mi");
		break;
	case 3:
		strcpy(sAnswer,"Fa");
		break;
	case 4:
		strcpy(sAnswer,"So");
		break;
	case 5:
		strcpy(sAnswer,"La");
		break;
	case 6:
		strcpy(sAnswer,"Si");
		break;
	}
	printf("%s\n",sAnswer);
	return 0;

} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(sInput);
  ^
/tmp/ccWYyARW.o: In function `main':
Main.c:(.text.startup+0x8f): warning: the `gets' function is dangerous and should not be used.