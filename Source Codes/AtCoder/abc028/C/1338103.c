#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 100
#define MAX_KIND 5
#define MAX_SUM_KIND 10

int main() {

	char sInput[MAX_STRING+1]="";
	int  anInput[MAX_KIND]={0,0,0,0,0};
	int  an3Sum[MAX_SUM_KIND]={0,0,0,0,0,0,0,0,0,0};
	char* psInput=NULL;

	int n1stSum=0;
	int n2ndSum=0;
	int n3rdSum=0;

	int i=0;

	// read line 1
	fgets(sInput,MAX_STRING,stdin);
	if (strchr(sInput, '\n') != NULL) {
	    sInput[strlen(sInput) - 1] = '\0';
	}
	psInput = strtok(sInput," ");
	for (i=0;i<MAX_KIND;i++){
		anInput[i]=atoi(psInput);
		psInput = strtok(NULL," ");
	}
	an3Sum[0]=anInput[0]+anInput[1]+anInput[2];
	an3Sum[1]=anInput[0]+anInput[1]+anInput[3];
	an3Sum[2]=anInput[0]+anInput[1]+anInput[4];
	an3Sum[3]=anInput[0]+anInput[2]+anInput[3];
	an3Sum[4]=anInput[0]+anInput[2]+anInput[4];
	an3Sum[5]=anInput[0]+anInput[3]+anInput[4];
	an3Sum[6]=anInput[1]+anInput[2]+anInput[3];
	an3Sum[7]=anInput[1]+anInput[2]+anInput[4];
	an3Sum[8]=anInput[1]+anInput[3]+anInput[4];
	an3Sum[9]=anInput[2]+anInput[3]+anInput[4];

	for (i=0;i<MAX_SUM_KIND;i++){
		if (n1stSum<an3Sum[i]){
			n1stSum=an3Sum[i];
		}
	}
	for (i=0;i<MAX_SUM_KIND;i++){
		if (an3Sum[i]<n1stSum && n2ndSum<an3Sum[i]){
			n2ndSum=an3Sum[i];
		}
	}
	for (i=0;i<MAX_SUM_KIND;i++){
		if (an3Sum[i]<n2ndSum && n3rdSum<an3Sum[i]){
			n3rdSum=an3Sum[i];
		}
	}
	printf("%d\n",n3rdSum);
	
	return 0;

} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sInput,MAX_STRING,stdin);
  ^