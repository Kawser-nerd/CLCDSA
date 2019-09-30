#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int R, C, N, Empty;
int Map[100][100];
int i, x, y, Ans, FAns, Temp;


void DFS(int Level, int Sy, int Sx){
	if (Level==Empty){
		Ans = 0;
		for (y=0; y<R; y++) for (x=1; x<C; x++) if (Map[y][x-1]) if (Map[y][x]) Ans++;
		for (x=0; x<C; x++) for (y=1; y<R; y++) if (Map[y-1][x]) if (Map[y][x]) Ans++;
		if (Ans<FAns) FAns = Ans;
		return ;
	}
	if (Sx==C){
		DFS(Level, Sy+1, 0);
		return ;
	}
	if (Sy==R) return ;
	
	Map[Sy][Sx] = 0;
	DFS(Level+1, Sy, Sx+1);
	Map[Sy][Sx] = 1;
	DFS(Level, Sy, Sx+1);
	return ;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d%d%d", &R, &C, &N);
		Empty = R*C-N;
		
		for (y=0; y<R; y++) for (x=0; x<C; x++) Map[y][x] = 1;
		
		FAns = 10000;
		
		for (y=0; y<R; y++) for (x=0; x<C; x++) DFS(0, y, x);
		
		printf("%d\n", FAns);
	}
	
	return 0;
}

