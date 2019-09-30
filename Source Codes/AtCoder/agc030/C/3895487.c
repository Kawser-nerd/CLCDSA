#include <stdio.h>
#include <stdlib.h>

int main(){
	int K, N, i, j;
	scanf("%d", &K);
	if(K == 1){
		printf("1\n");
		printf("1\n");
		return 0;
	}
	N = (K + 1) / 2;
	if(N % 2 == 1){
		N++;
	}
	int **C = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		C[i] = (int *)malloc(sizeof(int) * N);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			C[i][j] = (j - i + N) % N;
			if(i % 2 == 0 && C[i][j] + N < K){
				C[i][j] += N;
			}
		}
	}
	printf("%d\n", N);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d ", C[i][j] + 1);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &K);
  ^