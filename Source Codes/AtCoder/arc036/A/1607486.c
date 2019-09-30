#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, K, i;
	scanf("%d%d", &N, &K);
	int *t = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &t[i]);
	}
	for(i = 2; i < N; i++){
		if(t[i - 2] + t[i - 1] + t[i] < K){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &t[i]);
   ^