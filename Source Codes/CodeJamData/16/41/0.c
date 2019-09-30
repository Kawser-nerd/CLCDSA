#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TCs, TC;
int N, R, P, S;
char ans[15][3][4400];/*round, PRS, ans*/
int ansCount[15][3][3];/*round, winPRS, countPRS*/
int i, x;

int CheckValid(){
	int tmpN = 1<<N;
	int limitL = tmpN/3;
	int limitH = tmpN/3+1;
	
	if (R<limitL) return 0;
	if (P<limitL) return 0;
	if (S<limitL) return 0;
	if (R>limitH) return 0;
	if (P>limitH) return 0;
	if (S>limitH) return 0;
	return 1;
}

int Check(char A[], char B[]){
	int L = strlen(A);
	int i;
	for (i=0; i<L; i++){
		if (A[i]>B[i]) return 1;
		if (A[i]<B[i]) return -1;
	}
	return 0;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	ansCount[0][0][0] = 1;/*P*/
	ansCount[0][1][1] = 1;/*R*/
	ansCount[0][2][2] = 1;/*S*/
	strcpy(ans[0][0], "P");
	strcpy(ans[0][1], "R");
	strcpy(ans[0][2], "S");
	
	int round;
	for (round=1; round<=12; round++){
		/*PR P*/
		for (i=0; i<3; i++) ansCount[round][0][i] = ansCount[round-1][0][i]+ansCount[round-1][1][i];
		if (Check(ans[round-1][0], ans[round-1][1])==-1){
			strcpy(ans[round][0], ans[round-1][0]);
			strcat(ans[round][0], ans[round-1][1]);
		}
		else{
			strcpy(ans[round][0], ans[round-1][1]);
			strcat(ans[round][0], ans[round-1][0]);
		}
		
		/*PS S*/
		for (i=0; i<3; i++) ansCount[round][2][i] = ansCount[round-1][0][i]+ansCount[round-1][2][i];
		if (Check(ans[round-1][0], ans[round-1][2])==-1){
			strcpy(ans[round][2], ans[round-1][0]);
			strcat(ans[round][2], ans[round-1][2]);
		}
		else{
			strcpy(ans[round][2], ans[round-1][2]);
			strcat(ans[round][2], ans[round-1][0]);
		}
		
		/*RS R*/
		for (i=0; i<3; i++) ansCount[round][1][i] = ansCount[round-1][1][i]+ansCount[round-1][2][i];
		if (Check(ans[round-1][1], ans[round-1][2])==-1){
			strcpy(ans[round][1], ans[round-1][1]);
			strcat(ans[round][1], ans[round-1][2]);
		}
		else{
			strcpy(ans[round][1], ans[round-1][2]);
			strcat(ans[round][1], ans[round-1][1]);
		}
	}
	
	scanf("%d", &TCs);
	for (TC=1; TC<=TCs; TC++){
		printf("Case #%d: ", TC);
		scanf("%d%d%d%d", &N, &R, &P, &S);
		
		if (!CheckValid()){
			puts("IMPOSSIBLE");
			continue;
		}
		
		for (i=0; i<3; i++){
			if (P==ansCount[N][i][0]) if (R==ansCount[N][i][1]) if (S==ansCount[N][i][2]) break;
		}
		
		printf("%s\n", ans[N][i]);
		
	}
	
	return 0;
}


