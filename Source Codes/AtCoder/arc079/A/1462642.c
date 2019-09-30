#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, i, a, b;
	scanf("%d%d", &N, &M);
	int *c = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		c[i] = 0;
	}
	for(i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if(a == 0){
			c[b]++;
		}
		if(b == 0){
			c[a]++;
		}
		if(a == N - 1){
			c[b]++;
		}
		if(b == N - 1){
			c[a]++;
		}
	}
	for(i = 1; i < N - 1; i++){
		if(c[i] == 2){
			printf("POSSIBLE\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^