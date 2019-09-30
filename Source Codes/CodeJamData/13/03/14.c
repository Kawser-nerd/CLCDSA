#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TestCases, TCCount;
int x, Digits, t, i, L;
int Try[120];
int Ans[50000][120];
int TotalDigit[50000];
char Input[120];
int InputN[120];
int S, E;


int DFS(int Center, int Level){
	if (Center>=10) return 0;
	int i;
	if ((Level*2)>(Digits/2)){
		for (t=0; t<Digits; t++) for (i=0; i<=t; i++) Ans[x][t] += (Try[i]*Try[t-i]);
		TotalDigit[x] = Digits;
		x++;
		return 0;
	}
	for (i=0; i<=2; i++){
		Try[Level] = i;
		Try[Digits/2-Level] = i;
		if ((Level*2)==(Digits/2)) DFS(Center+i*i, Level+1);
		else DFS(Center+2*i*i, Level+1);
	}
	return 0;
}

int Check(int C){
	if (TotalDigit[C]<L) return 1;
	if (TotalDigit[C]>L) return 0;
	for (i=L-1; i>=0; i--){
		if (Ans[C][i]<InputN[i]) return 1;
		if (Ans[C][i]>InputN[i]) return 0;
	}
	return 0;
}


int main(){
	freopen("C-large-2.in", "r", stdin);
	freopen("C-large-2.out", "w", stdout);
	memset(Ans, 0, sizeof(Ans));
	memset(TotalDigit, 0, sizeof(TotalDigit));
	for (x=1; x<4; x++) TotalDigit[x] = 1;
	Ans[0][0] = 0;
	Ans[1][0] = 1;
	Ans[2][0] = 4;
	Ans[3][0] = 9;
	x = 4;
	for (Digits=3; Digits<=100; Digits+=2){
		Try[0] = 1;
		Try[Digits/2] = 1;
		DFS(2, 1);
		Try[0] = 2;
		Try[Digits/2] = 2;
		DFS(8, 1);
	}
	TotalDigit[41552] = 1000;
	
	
	scanf("%d", &TestCases);
	for (TCCount=1; TCCount<=TestCases; TCCount++){
		printf("Case #%d: ", TCCount);
		
		scanf("%s", Input);
		L = strlen(Input);
		for (i=0; i<L; i++) InputN[i] = Input[L-i-1]-48;
		for (S=0; Check(S); S++);
		
		scanf("%s", Input);
		L = strlen(Input);
		for (i=0; i<L; i++) InputN[i] = Input[L-i-1]-48;
		
		InputN[0]++;
		i = 0;
		while(InputN[i]>=10){
			InputN[i] -= 10;
			InputN[i+1]++;
			i++;
		}
		if (i==L) L++;
		
		for (E=S; Check(E); E++);
		
		printf("%d\n", E-S);
	}
	
	
	
	return 0;
}

