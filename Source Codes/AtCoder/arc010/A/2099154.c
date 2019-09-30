#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, A, B, i;
	scanf("%d%d%d%d", &N, &M, &A, &B);
	int *c = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d", &c[i]);
	}
	for(i = 0; i < M; i++){
		if(N <= A){
			N += B;
		}
		if(N < c[i]){
			printf("%d\n", i + 1);
			return 0;
		}
		else{
			N -= c[i];
		}
	}
	printf("complete\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &N, &M, &A, &B);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &c[i]);
   ^