#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int min(int a, int b){
	return a <= b ? a : b;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, M, a, b, t, i, j, k, now, ans;
	scanf("%d%d", &N, &M);
	int **E = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		E[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			E[i][j] = i == j ? 0 : inf;
		}
	}
	for(i = 0; i < M; i++){
		scanf("%d%d%d", &a, &b, &t);
		a--;
		b--;
		E[a][b] = t;
		E[b][a] = t;
	}
	for(k = 0; k < N; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
			}
		}
	}
	for(i = 0, ans = inf; i < N; i++){
		for(j = 0, now = 0; j < N; j++){
			now = max(now, E[i][j]);
		}
		ans = min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &t);
   ^