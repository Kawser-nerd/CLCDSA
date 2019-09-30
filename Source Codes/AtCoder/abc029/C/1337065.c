#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 10

int main() {

	char sInput[MAX_STRING+1]="";
	int  anCardinal[9]={1,1,1,1,1,1,1,1,1};
	int  anBaseNumber[8]={0,0,0,0,0,0,0,0};
	char* psInput=NULL;

	int nDigit=0;
	int nMaxNumber=1;
	int nNumber=0;
	int nTargetNumber=0;
	int nTemp=1;

	int nIndex=0;
	int i=0;
	int j=0;

	// read line 1
	fgets(sInput,MAX_STRING,stdin);
	if (strchr(sInput, '\n') != NULL) {
	    sInput[strlen(sInput) - 1] = '\0';
	}
	nDigit=atoi(sInput);
	for (i=0;i<9;i++){
		anCardinal[i]=nTemp;
		nTemp=nTemp*3;
	}
	for (i=0;i<nDigit;i++){
		nMaxNumber = nMaxNumber*3;
	}
	for (nTargetNumber=0;nTargetNumber<nMaxNumber;nTargetNumber++){
		anBaseNumber[0]=nTargetNumber%3;
		for (i=1;i<nDigit;i++){
			anBaseNumber[i]=(nTargetNumber%anCardinal[i+1])/anCardinal[i];
		}
		for (i=nDigit-1;i>=0;i--){
			printf("%c",'a'+anBaseNumber[i]);
		}
		printf("\n");
	}	
	return 0;

} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sInput,MAX_STRING,stdin);
  ^