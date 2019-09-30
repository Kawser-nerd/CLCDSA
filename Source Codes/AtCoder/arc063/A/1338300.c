#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LINE 100001

char sLongInputLine[MAX_LINE+1]="";

int main() {

	char* psInput=NULL;
	char* psTemp=NULL;
	char cPrevChar;

	int nLen = 0;
	int nCharChangeCount=0;
	int nCharChangeCountRev=0;
	int i=0;
	int j=0;


	// read line 1
	psTemp = fgets(sLongInputLine,MAX_LINE,stdin);
	if (strchr(sLongInputLine, '\n') != NULL) {
	    sLongInputLine[strlen(sLongInputLine) - 1] = '\0';
	} else {
		while(getchar() != '\n');
	}
	cPrevChar = sLongInputLine[0];
	nLen = strlen(sLongInputLine);

	for (i=1;i<nLen;i++){
		if (cPrevChar != sLongInputLine[i]){
			cPrevChar = sLongInputLine[i];
			nCharChangeCount++;
		}
	}
	cPrevChar = sLongInputLine[nLen-1];
	for (i=nLen-1;i>=0;i--){
		if (cPrevChar != sLongInputLine[i]){
			cPrevChar = sLongInputLine[i];
			nCharChangeCountRev++;
		}
	}
	if(nCharChangeCountRev<nCharChangeCount){
		nCharChangeCount = nCharChangeCountRev;
	}

	printf("%d\n",nCharChangeCount);
	
	return 0;

}