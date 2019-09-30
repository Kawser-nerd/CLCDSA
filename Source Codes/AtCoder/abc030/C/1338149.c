#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 30
#define MAX_LINE 1000000
#define MAX_FLIGHT 100000

char sLongInputLine[MAX_LINE+1]="";
int anFlightTime_AtoB[MAX_FLIGHT];
int anFlightTime_BtoA[MAX_FLIGHT];

int main() {

	char sInput[MAX_STRING+1]="";
	char* psInput=NULL;
	char* psTemp=NULL;

	int nFlightNumberAtoB=0;
	int nFlightNumberBtoA=0;
	int nReqTimeAtoB=0;
	int nReqTimeBtoA=0;

	int nAtoBTimeIndex=0;
	int nBtoATimeIndex=0;
	int nNow=0;
	int nReturnCount=0;

	int i=0;
	int j=0;

	// read line 1
	psTemp = fgets(sInput,MAX_STRING,stdin);
	if (strchr(sInput, '\n') != NULL) {
	    sInput[strlen(sInput) - 1] = '\0';
	}
	psInput = strtok(sInput," ");
	nFlightNumberAtoB = atoi(psInput);
	psInput = strtok(NULL," ");
	nFlightNumberBtoA = atoi(psInput);

	// read line 2
	psTemp = fgets(sInput,MAX_STRING,stdin);
	if (strchr(sInput, '\n') != NULL) {
	    sInput[strlen(sInput) - 1] = '\0';
	}
	psInput = strtok(sInput," ");
	nReqTimeAtoB = atoi(psInput);
	psInput = strtok(NULL," ");
	nReqTimeBtoA = atoi(psInput);

	// read line 3
	psTemp = fgets(sLongInputLine,MAX_LINE,stdin);
	if (strchr(sLongInputLine, '\n') != NULL) {
	    sLongInputLine[strlen(sLongInputLine) - 1] = '\0';
	}
	psInput = strtok(sLongInputLine," ");
	for (i=0;i<nFlightNumberAtoB;i++){
		anFlightTime_AtoB[i]=atoi(psInput);
		psInput = strtok(NULL," ");
	}
	// read line 4
	psTemp = fgets(sLongInputLine,MAX_LINE,stdin);
	if (strchr(sLongInputLine, '\n') != NULL) {
	    sLongInputLine[strlen(sLongInputLine) - 1] = '\0';
	}
	psInput = strtok(sLongInputLine," ");
	for (i=0;i<nFlightNumberBtoA;i++){
		anFlightTime_BtoA[i]=atoi(psInput);
		psInput = strtok(NULL," ");
	}

	while(nAtoBTimeIndex < nFlightNumberAtoB && nBtoATimeIndex < nFlightNumberBtoA){
		while(nAtoBTimeIndex < nFlightNumberAtoB && anFlightTime_AtoB[nAtoBTimeIndex]<nNow){
			nAtoBTimeIndex++;
		}
		if (nAtoBTimeIndex >= nFlightNumberAtoB){
			break;
		}
		//ride to flight A to B, then get off
		nNow=anFlightTime_AtoB[nAtoBTimeIndex]+nReqTimeAtoB;

		while(nBtoATimeIndex < nFlightNumberBtoA && anFlightTime_BtoA[nBtoATimeIndex]<nNow){
			nBtoATimeIndex++;
		}
		if (nBtoATimeIndex >= nFlightNumberBtoA){
			break;
		}
		//ride to flight B to A, then get off
		nNow=anFlightTime_BtoA[nBtoATimeIndex]+nReqTimeBtoA;

		nReturnCount++;

	}

	printf("%d\n",nReturnCount);
	
	return 0;

}