#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int min4(int a, int b, int c, int d){
	return min(min(a, b), min(c, d));
}

int main(){
	int N, M, a, i, j;
	scanf("%d%d", &N, &M);
	int **b = (int **)malloc(sizeof(int *) * (N + 2));
	for(i = 0; i <= N + 1; i++){
		b[i] = (int *)malloc(sizeof(int) * (M + 2));
		if(i == 0 || i == N + 1){
			for(j = 0; j <= M + 1; j++){
				b[i][j] = 0;
			}
		}
		else{
			b[i][0] = 0;
			for(j = 1; j <= M; j++){
				scanf("%1d", &b[i][j]);
			}
			b[i][M + 1] = 0;
		}
	}
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			a = min4(b[i - 1][j], b[i][j - 1], b[i + 1][j], b[i][j + 1]);
			printf("%d", a);
			b[i - 1][j] -= a;
			b[i][j - 1] -= a;
			b[i + 1][j] -= a;
			b[i][j + 1] -= a;
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%1d", &b[i][j]);
     ^