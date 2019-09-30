#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int main(){
	int N, i, mina = inf, maxa = -inf, min_num, max_num;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
		if(a[i] < mina){
			mina = a[i];
			min_num = i;
		}
		if(a[i] > maxa){
			maxa = a[i];
			max_num = i;
		}
	}
	if(mina >= 0){
		printf("%d\n", N - 1);
		for(i = 1; i < N; i++){
			printf("%d %d\n", i, i + 1);
		}
	}
	else if(maxa <= 0){
		printf("%d\n", N - 1);
		for(i = N; i > 1; i--){
			printf("%d %d\n", i, i - 1);
		}
	}
	else if(maxa + mina >= 0){
		printf("%d\n", 2 * N - 1);
		for(i = 1; i <= N; i++){
			printf("%d %d\n", max_num + 1, i);
		}
		for(i = 1; i < N; i++){
			printf("%d %d\n", i, i + 1);
		}
	}
	else{
		printf("%d\n", 2 * N - 1);
		for(i = 1; i <= N; i++){
			printf("%d %d\n", min_num + 1, i);
		}
		for(i = N; i > 1; i--){
			printf("%d %d\n", i, i - 1);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^