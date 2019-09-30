#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, Q, x1, y1, x2, y2, i, j;
	scanf("%d%d%d", &N, &M, &Q);
	int **S = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		S[i] = (int *)malloc(sizeof(int) * (M + 1));
		for(j = 0; j <= M; j++){
			if(i > 0 && j > 0){
				scanf("%1d", &S[i][j]);
			}
			else{
				S[i][j] = 0;
			}
		}
	}
	int **joge = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		joge[i] = (int *)malloc(sizeof(int) * (M + 1));
		for(j = 0; j <= M; j++){
			if(i < N){
				joge[i][j] = (S[i][j] & S[i + 1][j]);
			}
		}
	}
	int **sayu = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		sayu[i] = (int *)malloc(sizeof(int) * (M + 1));
		for(j = 0; j <= M; j++){
			if(j < M){
				sayu[i][j] = (S[i][j] & S[i][j + 1]);
			}
		}
	}
	for(i = 1; i <= N; i++){
		for(j = 0; j <= M; j++){
			S[i][j] += S[i - 1][j];
			if(i < N){
				joge[i][j] += joge[i - 1][j];
			}
			if(j < M){
				sayu[i][j] += sayu[i - 1][j];
			}
		}
	}
	for(i = 0; i <= N; i++){
		for(j = 1; j <= M; j++){
			S[i][j] += S[i][j - 1];
			if(i < N){
				joge[i][j] += joge[i][j - 1];
			}
			if(j < M){
				sayu[i][j] += sayu[i][j - 1];
			}
		}
	}
	int *ans = (int *)malloc(sizeof(int) * Q);
	for(i = 0; i < Q; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		ans[i] = 0;
		ans[i] += S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];
		ans[i] -= joge[x2 - 1][y2] - joge[x1][y2] - joge[x2 - 1][y1] + joge[x1][y1];
		ans[i] -= sayu[x2][y2 - 1] - sayu[x1][y2 - 1] - sayu[x2][y1] + sayu[x1][y1];
	}
	for(i = 0; i < Q; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &Q);
  ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%1d", &S[i][j]);
     ^
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
   ^