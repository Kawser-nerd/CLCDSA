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

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, Q, i, j, k, h, w, ans;
	scanf("%d", &N);
	int **D = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		D[i] = (int *)malloc(sizeof(int) * (N + 1));
		for(j = 0; j <= N; j++){
			D[i][j] = 0;
		}
	}
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			scanf("%d", &D[i][j]);
		}
	}
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
		}
	}
	scanf("%d", &Q);
	int *P = (int *)malloc(sizeof(int) * Q);
	for(k = 0; k < Q; k++){
		scanf("%d", &P[k]);
	}
	for(k = 0; k < Q; k++){
		ans = 0;
		for(h = 1; h <= min(P[k], N); h++){
			w = min(P[k] / h, N);
			for(i = h; i <= N; i++){
				for(j = w; j <= N; j++){
					ans = max(ans, D[i][j] - D[i - h][j] - D[i][j - w] + D[i - h][j - w]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:34:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &D[i][j]);
    ^
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Q);
  ^
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &P[k]);
   ^