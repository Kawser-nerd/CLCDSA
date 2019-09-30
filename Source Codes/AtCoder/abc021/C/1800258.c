#include <stdio.h>
#include <stdlib.h>
#define p (int)(1e9 + 7)
#define inf (int)(1e9 + 8)

int main(){
	int N, a, b, M, x, y, i, j, k;
	scanf("%d", &N);
	int **E = (int **)malloc(sizeof(int *) * N);
	int **shortest_case = (int **)malloc(sizeof(int *) * N);
	int **dis = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		E[i] = (int *)malloc(sizeof(int) * N);
		shortest_case[i] = (int *)malloc(sizeof(int) * N);
		dis[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			E[i][j] = inf;
			shortest_case[i][j] = 0;
			dis[i][j] = inf;
		}
	}
	scanf("%d%d", &a, &b);
	a--;
	b--;
	scanf("%d", &M);
	for(i = 0; i < M; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		E[x][y] = 1;
		E[y][x] = 1;
	}
	shortest_case[0][a] = 1;
	dis[0][a] = 0;
	for(k = 0; dis[k][b] >= inf; k++){
		for(i = 0; i < N; i++){
			if(dis[k][i] == k){
				for(j = 0; j < N; j++){
					if(E[i][j] < inf){
						if(dis[k + 1][j] >= inf){
							dis[k + 1][j] = k + 1;
							shortest_case[k + 1][j] = shortest_case[k][i];
						}
						else{
							shortest_case[k + 1][j] += shortest_case[k][i];
							shortest_case[k + 1][j] %= p;
						}
					}
				}
			}
		}
	}
	printf("%d\n", shortest_case[k][b]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &a, &b);
  ^
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &M);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^