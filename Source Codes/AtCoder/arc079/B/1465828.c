#include <stdio.h>
#include <stdlib.h>

#define int long long

int main(){
	int K, i, N = 50;
	scanf("%lld", &K);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = N - 1 + K / N;
	}
	for(i = 0; i < K % N; i++){
		a[i] += N - K % N + 1;
	}
	for(i = K % N; i < N; i++){
		a[i] -= K % N;
	}
	printf("%lld\n", N);
	for(i = 0; i < N; i++){
		printf("%lld ", a[i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &K);
  ^