#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *p = (int *)malloc(sizeof(int) * N);
	p[0] = -1;
	for(i = 1; i < N; i++){
		scanf("%d", &p[i]);
	}
	int *max_set = (int *)malloc(sizeof(int) * N);
	int *descendants_num = (int *)malloc(sizeof(int) * N);
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		max_set[i] = 0;
		descendants_num[i] = 0;
		ans[i] = 0;
	}
	for(i = N - 1; i >= 0; i--){
		ans[i] = max(max_set[i], N - descendants_num[i] - 1);
		if(p[i] != -1){
			max_set[p[i]] = max(max_set[p[i]], descendants_num[i] + 1);
			descendants_num[p[i]] += descendants_num[i] + 1;
		}
	}
	for(i = 0; i < N; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &p[i]);
   ^