#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, i, d = 21, j;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	int **next_dig = (int **)malloc(sizeof(int *) * (N + 2));
	for(i = 0; i <= N + 1; i++){
		next_dig[i] = (int *)malloc(sizeof(int) * d);
		for(j = 0; j < d; j++){
//			printf("test\n");
			next_dig[i][j] = -1;
		}
	}
	for(j = 0; j < d; j++){
		next_dig[N][j] = N;
		next_dig[N + 1][j] = N;
		for(i = N - 1; i >= 0; i--){
//			printf("(i, j) = (%lld, %lld)\n", i, j);
			if(((1 << j) & A[i]) != 0){
				next_dig[i][j] = i;
			}
			else{
				next_dig[i][j] = next_dig[i + 1][j];
			}
		}
	}
/*	for(i = 0; i <= N; i++){
		for(j = 0; j < d; j++){
			printf("next_dig[%lld][%lld] = %lld\n", i, j, next_dig[i][j]);
		}
	}
*/	int ans = 0, now;
	for(i = 0; i < N; i++){
		now = inf;
		for(j = 0; j < d; j++){
//			printf("(i, j) = (%lld, %lld)\n", i, j);
			now = min(now, next_dig[next_dig[i][j] + 1][j]);
		}
		ans += now - i;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^