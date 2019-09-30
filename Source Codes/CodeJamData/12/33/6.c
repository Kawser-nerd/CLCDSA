#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//0 for type 1 for num
long long orga[1024][2];
long long orgb[1024][2];
long long linea[1024][2];
long long lineb[1024][2];

long long res = 0;

void dfs(int n, int m, int N, int M, long long sofar){
	if (n>=N || m>=M){
		if (sofar > res){
			res = sofar;
		}
		return;
	}

	dfs(n+1, m, N, M, sofar);
	long long acc = 0;
	for (int i = m; i<M; i++){
		if (orgb[i][0] == orga[n][0]){
			if (acc+orgb[i][1] < orga[n][1]){
				acc += orgb[i][1];
			}else{
				long long minus = orga[n][1] -acc;
				acc = orga[n][1];
				orgb[i][1] -= minus;
				dfs(n+1, i, N, M, sofar + acc);
				orgb[i][1] += minus;
			}
		}
		dfs(n+1, i+1, N, M, sofar + acc);
	}
}

int main(int argc, char *argv[]){
	int T = 0, N = 0, M = 0;
	scanf("%d", &T);

	for (int cas = 1; cas <= T; cas++){
		scanf("%d %d", &N, &M);
		for (int i = 0; i<N; i++){
			scanf("%lld %lld", &orga[i][1], &orga[i][0]);
		}
		for (int i = 0; i<M; i++){
			scanf("%lld %lld", &orgb[i][1], &orgb[i][0]);
		}

		res = 0;
		dfs(0, 0, N, M, 0);
		printf("Case #%d: ", cas);
		printf("%lld\n", res);
	}
}
