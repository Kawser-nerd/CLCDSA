#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int N, M, i, j, k;
	scanf("%d%d", &N, &M);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), compare);
	int *B = (int *)malloc(sizeof(int) * M);
	for(j = 0; j < M; j++){
		scanf("%d", &B[j]);
	}
	qsort(B, M, sizeof(int), compare);
/*	for(i = 0; i < N; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	for(j = 0; j < M; j++){
		printf("%d ", B[j]);
	}
	printf("\n");
*/	for(i = 0, j = 0, k = 0; i < N && j < M; ){
		if(A[i] < B[j]){
			i++;
		}
		else if(A[i] > B[j]){
			j++;
		}
		else{
			i++;
			j++;
			k++;
		}
	}
	printf("%.20lf\n", (double)k / (double)(N + M - k));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B[j]);
   ^