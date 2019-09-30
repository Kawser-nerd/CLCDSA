#include <stdio.h>

int main(){
	long long int N, K;
	scanf("%lld%lld", &N, &K);
	printf("%1.20f\n", (double)(1 + 3 * (N - 1) + 6 * (K - 1) * (N - K)) / (N * N * N));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^