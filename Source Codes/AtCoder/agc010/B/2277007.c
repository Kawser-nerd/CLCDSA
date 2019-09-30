#include <stdio.h>
#include <stdlib.h>
#define int long long

signed main(){
	int N, i, sum = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
		sum += A[i];
	}
	if(sum % ((N * (N + 1)) / 2) != 0){
		printf("NO\n");
		return 0;
	}
	int K = sum / ((N * (N + 1)) / 2);
	int now = 0;
	for(i = 0; i < N; i++){
		int d = A[(i + 1) % N] - A[i];
		if(K < d || (K - d) % N != 0){
//			printf("i = %lld\n", i);
			printf("NO\n");
			return 0;
		}
		now += (K - d) / N;
	}
	if(now == K){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^