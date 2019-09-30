#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *p = (int *)malloc(sizeof(int) * N);
	for(i = 1; i < N; i++){
		scanf("%d", &p[i]);
	}
	int *max_set = (int *)calloc(N, sizeof(int));
	int *descendants_num = (int *)calloc(N, sizeof(int));
	for(i = N - 1; i > 0; i--){
		max_set[p[i]] = max(max_set[p[i]], descendants_num[i] + 1);
		descendants_num[p[i]] += descendants_num[i] + 1;
	}
	printf("%d\n", max_set[0]);
	for(i = 1; i < N; i++){
		printf("%d\n", max(max_set[i], N - descendants_num[i] - 1));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &p[i]);
   ^