#include <stdio.h>
#include <stdlib.h>

void digit_down(int *A, int N, int K){
	int i;
	for(i = N - 1; A[i] == 0; i--){}
	if(A[i] == 1){
		A[i] = 0;
	}
	else{
		A[i]--;
		for(i++; i < N; i++){
			A[i] = K;
		}
	}
}

int main(){
	int N, K, i;
	scanf("%d%d", &K, &N);
	if(K == 1){
		for(i = 0; i < (N + 1) / 2; i++){
			printf("1 ");
		}
	}
	else if(K % 2 == 0){
		printf("%d ", K / 2);
		for(i = 1; i < N; i++){
			printf("%d ", K);
		}
	}
	else{
		int *ans = (int *)malloc(sizeof(int) * N);
		for(i = 0; i < N; i++){
			ans[i] = (K + 1) / 2;
		}
		int l = N / 2;
		for(i = 0; i < l; i++){
			digit_down(ans, N, K);
		}
		for(i = 0; i < N; i++){
			if(ans[i] != 0){
				printf("%d ", ans[i]);
			}
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &K, &N);
  ^