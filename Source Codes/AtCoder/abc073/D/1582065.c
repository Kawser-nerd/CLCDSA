#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int solve(int N, int R, int **d, int *r, int pre){
	int i, tmp, ans = inf;
	for(i = 0; i < R; i++){
		if(r[i] != -1){
			tmp = r[i];
			r[i] = -1;
//			printf("pre = %d, before:ans = %d\n", pre, ans);
//			printf("d[%d][%d] = %d\n", pre, r[i], d[pre][tmp]);
			ans = min(ans, solve(N, R, d, r, tmp) + d[pre][tmp]);
//			printf("pre = %d, after:ans = %d\n", pre, ans);
			r[i] = tmp;
		}
	}
	ans %= inf;
//	printf("pre = %d, ans = %d\n", pre, ans);
	return ans;
}

int main(){
	int N, M, R, A, B, C, i, j, k;
	scanf("%d%d%d", &N, &M, &R);
	int *r = (int *)malloc(sizeof(int) * R);
	for(i = 0; i < R; i++){
		scanf("%d", &r[i]);
	}
	int **d = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		d[i] = (int *)malloc(sizeof(int) * (N + 1));
		for(j = 0; j <= N; j++){
			if(i == j || i == 0 || j == 0){
				d[i][j] = 0;
			}
			else{
				d[i][j] = inf;
			}
		}
	}
	for(i = 0; i < M; i++){
		scanf("%d%d%d", &A, &B, &C);
		d[A][B] = C;
		d[B][A] = C;
	}
	for(k = 1; k <= N; k++){
		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
/*	for(i = 0; i <= N; i++){
		for(j = 0; j <= N; j++){
			printf("%d  ", d[i][j]);
		}
		printf("\n");
	}
*/	printf("%d\n", solve(N, R, d, r, 0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &R);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &r[i]);
   ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &A, &B, &C);
   ^