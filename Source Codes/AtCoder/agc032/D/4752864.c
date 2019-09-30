#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e14)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, A, B, i, j;
	scanf("%lld%lld%lld", &N, &A, &B);
	int *p = (int *)malloc(sizeof(int) * (N + 1));
	int *p_inv = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 1; i <= N; i++){
		scanf("%lld", &p[i]);
		p_inv[p[i]] = i;
	}
	int **dp1 = (int **)malloc(sizeof(int *) * (N + 1));
	int **dp2 = (int **)malloc(sizeof(int *) * (N + 1));
	int **m1 = (int **)malloc(sizeof(int *) * (N + 1));
	int **m2 = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		dp1[i] = (int *)malloc(sizeof(int) * (N + 1));
		dp2[i] = (int *)malloc(sizeof(int) * (N + 1));
		m1[i] = (int *)malloc(sizeof(int) * (N + 1));
		m2[i] = (int *)malloc(sizeof(int) * (N + 1));
	}
	for(j = 0; j <= N; j++){
		dp1[0][j] = 0;
		dp2[0][j] = 0;
		m1[0][j] = 0;
		m2[0][j] = 0;
	}
	for(i = 1; i <= N; i++){
		dp1[i][0] = inf;
		for(j = 1; j <= N; j++){
			dp1[i][j] = min(m1[i - 1][j - 1], m2[i - 1][j - 1]);
			if(j < p_inv[i]){
				dp1[i][j] += B;
			}
			if(j > p_inv[i]){
				dp1[i][j] += A;
			}
		}
		for(j = 0; j <= N; j++){
			dp2[i][j] = min(m1[i - 1][j], m2[i - 1][j]);
			if(j < p_inv[i]){
				dp2[i][j] += B;
			}
			else{
				dp2[i][j] += A;
			}
		}
		m1[i][0] = dp1[i][0];
		for(j = 1; j <= N; j++){
			m1[i][j] = min(m1[i][j - 1], dp1[i][j]);
		}
		m2[i][0] = dp2[i][0];
		for(j = 1; j <= N; j++){
			m2[i][j] = min(m2[i][j - 1], dp2[i][j]);
		}
	}
	printf("%lld\n", min(m1[N][N], m2[N][N]));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &A, &B);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &p[i]);
   ^