#include <stdio.h>
#include <stdlib.h>
#define int long long

int MOD(int a, int p){
	a %= p;
	return a >= 0 ? a : a + p;
}

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &A[i], &B[i]);
	}
	for(i = N - 1; i >= 0; i--){
		A[i] += ans;
		ans += MOD(-A[i], B[i]);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &A[i], &B[i]);
   ^