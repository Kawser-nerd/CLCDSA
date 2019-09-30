#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, M, A, B, C, K, x, y, z, i, j, k, ans;
	scanf("%lld%lld", &N, &M);
	int **dis = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		dis[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			dis[i][j] = i == j ? 0 : inf;
		}
	}
	for(i = 0; i < M; i++){
		scanf("%lld%lld%lld", &A, &B, &C);
		A--;
		B--;
		dis[A][B] = C;
		dis[B][A] = C;
	}
	scanf("%lld", &K);
	int *X = (int *)malloc(sizeof(int) * K);
	int *Y = (int *)malloc(sizeof(int) * K);
	int *Z = (int *)malloc(sizeof(int) * K);
	for(i = 0; i < K; i++){
		scanf("%lld%lld%lld", &X[i], &Y[i], &Z[i]);
		X[i]--;
		Y[i]--;
	}
	for(k = 0; k < N; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
//				printf("(k, i, j) = (%lld, %lld, %lld)\n", k, i, j);
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(k = 0; k < K; k++){
		ans = 0;
		x = X[k];
		y = Y[k];
		z = Z[k];
		dis[x][y] = min(dis[x][y], z);
		dis[y][x] = min(dis[y][x], z);
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				dis[i][j] = min(dis[i][j], min(dis[i][x] + dis[x][y] + dis[y][j], dis[i][y] + dis[y][x] + dis[x][j]));
				ans += dis[i][j];
			}
		}
/*		printf("k = %lld\n", k);
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				printf("%lld  ", dis[i][j]);
			}
			printf("\n");
		}
*/		printf("%lld\n", ans / 2);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &A, &B, &C);
   ^
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &K);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &X[i], &Y[i], &Z[i]);
   ^