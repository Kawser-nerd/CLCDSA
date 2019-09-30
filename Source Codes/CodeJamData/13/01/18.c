#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TestCases, TCCount;
char Map[10][10];
int i, x, y, T, Ans;

int Solve(){
	for (y=0; y<4; y++){
		T = 0;
		Ans = 0;
		for (x=0; x<4; x++){
			if (Map[y][x]=='X') Ans--;
			if (Map[y][x]=='O') Ans++;
			if (Map[y][x]=='T') T = 1;
		}
		if (T){
			if (Ans<0) Ans--;
			if (Ans>0) Ans++;
		}
		if (Ans==-4){
			printf("X won\n");
			return 0;
		}
		if (Ans==4){
			printf("O won\n");
			return 0;
		}
	}
	
	for (x=0; x<4; x++){
		T = 0;
		Ans = 0;
		for (y=0; y<4; y++){
			if (Map[y][x]=='X') Ans--;
			if (Map[y][x]=='O') Ans++;
			if (Map[y][x]=='T') T = 1;
		}
		if (T){
			if (Ans<0) Ans--;
			if (Ans>0) Ans++;
		}
		if (Ans==-4){
			printf("X won\n");
			return 0;
		}
		if (Ans==4){
			printf("O won\n");
			return 0;
		}
	}
	
	T = 0;
	Ans = 0;
	for (x=0, y=0; x<4; x++, y++){
		if (Map[y][x]=='X') Ans--;
		if (Map[y][x]=='O') Ans++;
		if (Map[y][x]=='T') T = 1;
		
	}
	if (T){
		if (Ans<0) Ans--;
		if (Ans>0) Ans++;
	}
	if (Ans==-4){
		printf("X won\n");
		return 0;
	}
	if (Ans==4){
		printf("O won\n");
		return 0;
	}
	
	T = 0;
	Ans = 0;
	for (x=3, y=0; x>=0; x--, y++){
		if (Map[y][x]=='X') Ans--;
		if (Map[y][x]=='O') Ans++;
		if (Map[y][x]=='T') T = 1;
		
	}
	if (T){
		if (Ans<0) Ans--;
		if (Ans>0) Ans++;
	}
	if (Ans==-4){
		printf("X won\n");
		return 0;
	}
	if (Ans==4){
		printf("O won\n");
		return 0;
	}
	
	for (y=0; y<4; y++) for (x=0; x<4; x++) if (Map[y][x]=='.'){
		printf("Game has not completed\n");
		return 0;
	}
	printf("Draw\n");
		return 0;
}


int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	scanf("%d", &TestCases);
	for (TCCount=1; TCCount<=TestCases; TCCount++){
		printf("Case #%d: ", TCCount);
		
		for (y=0; y<4; y++) scanf("%s", Map[y]);
		
		Solve();
		
		
	}
	
	
	return 0;
}

