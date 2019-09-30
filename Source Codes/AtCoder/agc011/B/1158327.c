#include <stdio.h>
#include <stdlib.h>

long long int *sort_sub(long long int *T, int N){
	long long int *ans = (long long int *)malloc(sizeof(long long int) * N);
	if(N == 1){
		ans[0] = T[0];
	}
	else{
		int N1 = N / 2;
		int N2 = (N + 1) / 2;
		long long int *sub1 = sort_sub(&T[0] , N1);
		long long int *sub2 = sort_sub(&T[N1], N2);
		int i, j, k;
		for(i = 0, j = 0, k = 0; i < N; i++){
			if((sub1[j] < sub2[k] && j != N1) || (k == N2)){
				ans[i] = sub1[j];
				j++;
			}
			else{
				ans[i] = sub2[k];
				k++;
			}
		}
		free(sub1);
		free(sub2);
	}
	return ans;
}

long long int *sort(long long int *T, int N){
	long long int *ans = sort_sub(T, N);
	free(T);
	return ans;
}

int main(){
	int N, i;
	scanf("%d", &N);
	long long int *A = (long long int *)malloc(sizeof(long long int) * N);
	long long int *S = (long long int *)malloc(sizeof(long long int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	A = sort(A, N);
	S[0] = A[0];
	for(i = 1; i < N; i++){
		S[i] = S[i - 1] + A[i];
	}
	for(i = N -1; i >= 1; i--){
		if(A[i] > 2 * S[i - 1]){
			break;
		}
	}
	printf("%d\n", N - i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^