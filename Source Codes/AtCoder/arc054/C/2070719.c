#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, k, *tmp;
	scanf("%d", &N);
	int **A = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		A[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			scanf("%1d", &A[i][j]);
		}
	}
	for(i = 0; i < N; i++){
		if(A[i][i] == 0){
			for(j = i + 1; j < N; j++){
				if(A[j][i] == 1){
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
					break;
				}
			}
			if(j == N){
				printf("Even\n");
				return 0;
			}
		}
		for(j = i + 1; j < N; j++){
			if(A[j][i] == 1){
				for(k = i; k < N; k++){
					A[j][k] ^= A[i][k];
				}
			}
		}
	}
	printf("Odd\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%1d", &A[i][j]);
    ^