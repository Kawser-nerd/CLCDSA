#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, K, i, j, xor;
	scanf("%d%d", &N, &K);
	int **T = (int **)malloc(sizeof(int *) * N);
	int *count = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		T[i] = (int *)malloc(sizeof(int) * K);
		count[i] = 0;
		for(j = 0; j < K; j++){
			scanf("%d", &T[i][j]);
		}
	}
	while(1){
		xor = 0;
		for(i = 0; i < N; i++){
			xor ^= T[i][count[i]];
		}
		if(xor == 0){
			printf("Found\n");
			return 0;
		}
		for(i = 0; ; i++){
			if(count[i] < K - 1){
				count[i]++;
				break;
			}
			else if(i == N - 1){
				printf("Nothing\n");
				return 0;
			}
			else{
				count[i] = 0;
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &T[i][j]);
    ^