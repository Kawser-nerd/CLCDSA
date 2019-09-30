#include <stdio.h>
#include <stdlib.h>

int main(){
	int R, C, K, i, j, ans = 0;
	scanf("%d%d%d", &R, &C, &K);
	char **S = (char **)malloc(sizeof(char *) * R);
	int **A = (int **)malloc(sizeof(int *) * R);
	int **B1 = (int **)malloc(sizeof(int *) * R);
	int **B2 = (int **)malloc(sizeof(int *) * R);
	for(i = 0; i < R; i++){
		S[i] = (char *)malloc(sizeof(char) * (C + 1));
		A[i] = (int *)malloc(sizeof(int) * C);
		B1[i] = (int *)malloc(sizeof(int) * C);
		B2[i] = (int *)malloc(sizeof(int) * C);
		scanf("%s", S[i]);
	}
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			if(S[i][j] == 'x'){
				A[i][j] = 0;
			}
			else{
				if(i == 0 || j == 0){
					A[i][j] = 1;
				}
				else{
					A[i][j] = A[i - 1][j - 1] + 1;
				}
			}
		}
	}
	for(i = 0; i < R; i++){
		for(j = C - 1; j >= 0; j--){
			if(A[i][j] < K){
				B1[i][j] = 0;
			}
			else{
				if(i == 0 || j == C - 1){
					B1[i][j] = 1;
				}
				else{
					B1[i][j] = B1[i - 1][j + 1] + 1;
				}
			}
			if(A[i][j] < K - 1){
				B2[i][j] = 0;
			}
			else{
				if(i == 0 || j == C - 1){
					B2[i][j] = 1;
				}
				else{
					B2[i][j] = B2[i - 1][j + 1] + 1;
				}
			}
		}
	}
	for(i = 1; i < R; i++){
		for(j = 0; j < C; j++){
			if(B1[i][j] >= K && B2[i - 1][j] >= K - 1){
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &R, &C, &K);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^