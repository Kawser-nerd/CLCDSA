#include <stdio.h>
#include <stdlib.h>
#define p (int)(1e9 + 7)

int main(){
	int N, K, i, j, k, ans = 0;
	scanf("%d%d", &N, &K);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	int ***A = (int ***)malloc(sizeof(int **) * (N + 1));
	for(i = 0; i <= N; i++){
		A[i] = (int **)malloc(sizeof(int *) * (K + 2));
		for(j = 0; j <= K + 1; j++){
			A[i][j] = (int *)malloc(sizeof(int) * (K + 2));
			for(k = 0; k <= K + 1; k++){
				A[i][j][k] = 0;
			}
		}
	}
	A[0][0][0] = 1;
	for(i = 0; i < N; i++){
//		printf("i = %d\n", i);
		for(j = 0; j <= K; j++){
//			printf("j = %d\n", j);
			for(k = 0; k <= K; k++){
//				printf("k = %d\n", k);
//				printf("S[%d] = %c\n", i, S[i]);
				if(S[i] == '0'){
					if(j > 0){
						if(k == 0){
							A[i + 1][j][k] = (A[i][j - 1][k + 1] + A[i][j - 1][k]) % p;
						}
						else{
							A[i + 1][j][k] = A[i][j - 1][k + 1];
						}
					}
				}
				else if(S[i] == '1'){
					if(k > 0){
						if(j == 0){
							A[i + 1][j][k] = (A[i][j + 1][k - 1] + A[i][j][k - 1]) % p;
						}
						else{
							A[i + 1][j][k] = A[i][j + 1][k - 1];
						}
					}
				}
				else{
					if(j > 0 && k > 0){
						A[i + 1][j][k] = (A[i][j - 1][k + 1] + A[i][j + 1][k - 1]) % p;
					}
					else if(j > 0 && k == 0){
						A[i + 1][j][k] = (A[i][j - 1][k + 1] + A[i][j - 1][k]) % p;
					}
					else if(j == 0 && k > 0){
						A[i + 1][j][k] = (A[i][j + 1][k - 1] + A[i][j][k - 1]) % p;
					}
				}
			}
		}
	}
/*	for(i = 0; i <= N; i++){
		printf("i = %d\n", i);
		for(j = 0; j <= K; j++){
			for(k = 0; k <= K; k++){
				printf("%d  ", A[i][j][k]);
			}
			printf("\n");
		}
	}
*/	for(j = 0; j <= K; j++){
		for(k = 0; k <= K; k++){
			ans = (ans + A[N][j][k]) % p;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^