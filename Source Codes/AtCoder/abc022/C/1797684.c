#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e17)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, M, u, v, l, i, j, k, ans = inf;
	scanf("%lld%lld", &N, &M);
	int **E = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		E[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			E[i][j] = inf;
		}
	}
	for(i = 0; i < M; i++){
		scanf("%lld%lld%lld", &u, &v, &l);
		u--;
		v--;
		E[u][v] = l;
		E[v][u] = l;
	}
	for(k = 1; k < N; k++){
		for(i = 1; i < N; i++){
			for(j = 1; j < N; j++){
				E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
			}
		}
	}
	for(i = 1; i < N; i++){
		for(j = i + 1; j < N; j++){
			ans = min(ans, E[0][i] + E[i][j] + E[j][0]);
		}
	}
	if(ans >= inf){
		printf("-1\n");
	}
	else{
		printf("%lld\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &u, &v, &l);
   ^