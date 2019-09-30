#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 4
#define QNUM_LIMIT 100

int main() {

	char  sInput[MAX_STRING]="";
	char* psInput=NULL;
	char* psTemp=NULL;

	int nQNum=0;
	int anScore[QNUM_LIMIT];
	int nSum=0;
	int nMinNum = 10000;
	int nAnswer=0;

	int i=0;
	int j=0;


	// read line 1
	psTemp = fgets(sInput,MAX_STRING,stdin);
	if (strchr(sInput, '\n') != NULL) {
	    sInput[strlen(sInput) - 1] = '\0';
	} else {
		while(getchar() != '\n');
	}
	nQNum=atoi(sInput);

	for (i=0;i<nQNum;i++){
		psTemp = fgets(sInput,MAX_STRING,stdin);
		if (strchr(sInput, '\n') != NULL) {
			sInput[strlen(sInput) - 1] = '\0';
		} else {
			while(getchar() != '\n');
		}
		anScore[i]=atoi(sInput);
		nSum = nSum + anScore[i];

		if (anScore[i]%10 != 0 && anScore[i]<nMinNum){
			nMinNum=anScore[i];
		}
	}

	if (nSum%10 != 0 ){
		nAnswer = nSum;
	} else {
		nAnswer = nSum - nMinNum;
		if ( nAnswer <= 0 || nAnswer%10 == 0){
			nAnswer=0;
		}
	}


	printf("%d\n",nAnswer);
	
	return 0;

}