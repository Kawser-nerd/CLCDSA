#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, N = 100, i, j;
	scanf("%d%d", &A, &B);
	char **C = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		C[i] = (char *)malloc(sizeof(char) * (N + 1));
		for(j = 0; j < N; j++){
			if(i < N / 2){
				C[i][j] = '.';
			}
			else{
				C[i][j] = '#';
			}
		}
		C[i][N] = '\0';
	}
	A--;
	B--;
	for(i = 0; i < N / 2; i++){
		for(j = 0; j < N; j++){
			if(i % 2 == 0 && j % 2 == 0 && B > 0){
				C[i][j] = '#';
				B--;
			}
		}
	}
	for(i = N - 1; i >= N / 2; i--){
		for(j = 0; j < N; j++){
			if(i % 2 == 0 && j % 2 == 0 && A > 0){
				C[i][j] = '.';
				A--;
			}
		}
	}
	printf("%d %d\n", N, N);
	for(i = 0; i < N; i++){
		printf("%s\n", C[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^