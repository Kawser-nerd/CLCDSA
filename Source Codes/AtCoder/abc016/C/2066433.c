#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, a, b, i, j, k, ans;
	scanf("%d%d", &N, &M);
	int **E = (int **)malloc(sizeof(int *) * N);
	int *is_counted = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		E[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			E[i][j] = 0;
		}
	}
	for(i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		a--;
		b--;
		E[a][b] = 1;
		E[b][a] = 1;
	}
	for(i = 0; i < N; i++){
		ans = 0;
		for(j = 0; j < N; j++){
			is_counted[j] = 0;
		}
		for(j = 0; j < N; j++){
			if(E[i][j] == 1){
				for(k = 0; k < N; k++){
					if(E[j][k] == 1 && i != k && E[i][k] == 0 && is_counted[k] == 0){
						ans++;
						is_counted[k] = 1;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^