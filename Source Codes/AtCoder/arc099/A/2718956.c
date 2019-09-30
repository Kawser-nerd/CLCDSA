#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, K, i;
	scanf("%d%d", &N, &K);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	printf("%d\n", ((N - 1) + (K - 1) - 1) / (K - 1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^