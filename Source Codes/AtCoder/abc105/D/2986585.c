#include <stdio.h>
#include <stdlib.h>
#define int long long

signed compare(const void *a, const void *b){
	int sub = *(int *)a - *(int *)b;
	if(sub < 0){
		return -1;
	}
	else if(sub > 0){
		return 1;
	}
	else{
		return 0;
	}
}

signed main(){
	int N, M, i, j, ans = 0;
	scanf("%lld%lld", &N, &M);
	int *A = (int *)malloc(sizeof(int) * (N + 1));
	int *B = (int *)malloc(sizeof(int) * (N + 1));
	A[0] = 0;
	for(i = 1; i <= N; i++){
		scanf("%lld", &A[i]);
	}
	for(i = 1; i <= N; i++){
		A[i] = (A[i] + A[i - 1]) % M;
	}
	qsort(A, N + 1, sizeof(int), compare);
	B[0] = 1;
	for(i = 1, j = 0; i <= N; i++){
		if(A[i] == A[i - 1]){
			B[j]++;
		}
		else{
			j++;
			B[j] = 1;
		}
	}
	for(i = 0; i <= j; i++){
//		printf("B[%lld] = %lld\n", i, B[i]);
		ans += (B[i] * (B[i] - 1)) / 2;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^