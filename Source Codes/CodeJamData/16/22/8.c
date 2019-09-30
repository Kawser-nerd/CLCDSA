#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
char C[100];
char J[100];
char printX[100];
long long int i, x, y, c, L, ansD, ansC, ansJ;

//larger = C>J
void DFS(int curD, int larger, long long int tmpC, long long int tmpJ){
	int i;
	
	if (curD==L){
		long long int tmpD = tmpC-tmpJ;
		if (tmpD<0) tmpD = -tmpD;
		
		if (tmpD<ansD){
			ansD = tmpD;
			ansC = tmpC;
			ansJ = tmpJ;
		}
		else if (tmpD==ansD){
			if (tmpC<ansC){
				ansC = tmpC;
				ansJ = tmpJ;
			}
			else if (tmpC==ansC){
				if (tmpJ<ansJ) ansJ = tmpJ;
			}
		}
		return ;
	}
	
	if (C[curD]=='?' && J[curD]=='?'){
		if (larger==0){
			DFS(curD+1, 0, tmpC*10, tmpJ*10);
			DFS(curD+1, 1, tmpC*10+1, tmpJ*10);
			DFS(curD+1, -1, tmpC*10, tmpJ*10+1);
			return ;
		}
		if (larger==1){
			DFS(curD+1, 1, tmpC*10, tmpJ*10+9);
		}
		if (larger==-1){
			DFS(curD+1, -1, tmpC*10+9, tmpJ*10);
		}
		return ;
	}
	if (C[curD]=='?'){
		int c = J[curD] - '0';
		
		if (larger==0){
			DFS(curD+1, 0, tmpC*10+c, tmpJ*10+c);
			if (c<9) DFS(curD+1, 1, tmpC*10+c+1, tmpJ*10+c);
			if (c>0) DFS(curD+1, -1, tmpC*10+c-1, tmpJ*10+c);
		}
		if (larger==1) DFS(curD+1, 1, tmpC*10, tmpJ*10+c);
		if (larger==-1) DFS(curD+1, -1, tmpC*10+9, tmpJ*10+c);
		return ;
	}
	if (J[curD]=='?'){
		int c = C[curD] - '0';
		
		if (larger==0){
			DFS(curD+1, 0, tmpC*10+c, tmpJ*10+c);
			if (c<9) DFS(curD+1, -1, tmpC*10+c, tmpJ*10+c+1);
			if (c>0) DFS(curD+1, 1, tmpC*10+c, tmpJ*10+c-1);
		}
		if (larger==1) DFS(curD+1, 1, tmpC*10+c, tmpJ*10+9);
		if (larger==-1) DFS(curD+1, -1, tmpC*10+c, tmpJ*10);
		return ;
	}
	
	tmpC = tmpC*10+C[curD]-'0';
	tmpJ = tmpJ*10+J[curD]-'0';
	if (tmpC>tmpJ) larger = 1;
	if (tmpC==tmpJ) larger = 0;
	if (tmpC<tmpJ) larger = -1;
	
	DFS(curD+1, larger, tmpC, tmpJ);
	
	
	return ;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d:", T);
		scanf("%s%s", C, J);
		L = strlen(C);
		
		ansD = 5;
		for (i=0; i<18; i++) ansD *= 10;
		ansC = ansD;
		ansJ = ansD;
		
		DFS(0, 0, 0, 0);
		
		printX[L] = '\0';
		
		for (i=L-1; i>=0; i--){
			printX[i] = (ansC%10)+'0';
			ansC /= 10;
		}
		printf(" %s", printX);
		
		for (i=L-1; i>=0; i--){
			printX[i] = (ansJ%10)+'0';
			ansJ /= 10;
		}
		printf(" %s\n", printX);
		
	}
	
	
	return 0;
}


