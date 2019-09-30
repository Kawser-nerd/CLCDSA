#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, C;
	int *B;
	int **A;
	int i, j, k;
	int count = 0;
	long int value = 0;

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &C);
	B = (int*)malloc(sizeof(int) * M);
	for(i = 0;i < M;i++) {
		scanf("%d", &B[i]);
	}
	A = (int**)malloc(sizeof(int*) * N);
	for(i = 0;i < N;i++) {
		A[i] = (int*)malloc(sizeof(int) * M);
	}
	for(i = 0;i < N;i++) {
		for(j = 0;j < M;j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for(i = 0;i < N;i++) {
		value = 0;
		for(j=0;j < M;j++) {
			value += A[i][j] * B[j];
		}
		value += C;
		if(value > 0) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &M);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &C);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B[i]);
   ^
./Main.c:25:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &A[i][j]);
    ^