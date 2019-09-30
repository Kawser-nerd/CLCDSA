#include <stdio.h>
#include <stdlib.h>
#define int long long

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
		B[i] = A[i] + N - 1 - i;
	}
	if(A[0] > 0){
		printf("-1\n");
		return 0;
	}
	int Bmin = (int)(1e18);
	for(i = 0; i < N; i++){
		Bmin = min(Bmin, B[i]);
		if(Bmin != B[i]){
			printf("-1\n");
			return 0;
		}
	}
	for(i = N - 1; i > 0; i--){
		ans += A[i];
		while(A[i - 1] == A[i] - 1 && i > 0){
			i--;
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^