#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	int *inv = (int *)malloc(sizeof(int) * (N + 1));
	int *inv_sum = (int *)malloc(sizeof(int) * (N + 1));
	inv[1] = 1;
	for(i = 2; i <= N; i++){
		inv[i] = MOD(-(p / i) * inv[p % i]);
	}
	inv_sum[0] = 0;
	for(i = 1; i <= N; i++){
		inv_sum[i] = MOD(inv_sum[i - 1] + inv[i]);
	}
	for(i = 0; i < N; i++){
		ans = MOD(ans + (inv_sum[i + 1] + inv_sum[N - i] - 1) * A[i]);
	}
	for(i = 1; i <= N; i++){
		ans = MOD(ans * i);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^