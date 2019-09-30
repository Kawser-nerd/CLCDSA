#include <stdio.h>
#include <stdlib.h>
#define int long long

int ABS(int a){
	return a >= 0 ? a : 0;
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, K, i, ans = 0;
	scanf("%lld%lld", &N, &K);
	int *a = (int *)malloc(sizeof(int) * (N + 1));
	int *sum = (int *)malloc(sizeof(int) * (N + 1));
	int *absum = (int *)malloc(sizeof(int) * (N + 1));
	sum[0] = 0;
	absum[0] = 0;
	for(i = 1; i <= N; i++){
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		absum[i] = absum[i - 1] + ABS(a[i]);
	}
	for(i = 0; i + K <= N; i++){
		ans = max(ans, absum[N] - absum[i + K] + absum[i] + ABS(sum[i + K] - sum[i]));
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^