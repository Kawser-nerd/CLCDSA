#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, i;
	scanf("%d%d", &N, &M);
	int *a = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	int *b = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		b[i] = 0;
	}
	for(i = M - 1; i >= 0; i--){
		if(b[a[i]] == 0){
			printf("%d\n", a[i] + 1);
			b[a[i]] = 1;
		}
	}
	for(i = 0; i < N; i++){
		if(b[i] == 0){
			printf("%d\n", i + 1);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^