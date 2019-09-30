#include <stdio.h>
#include <stdlib.h>

int ABS(int a){
	return a >= 0 ? a : -a;
}

int main(){
	int N, i, T, D;
	scanf("%d", &N);
	int *t = (int *)malloc(sizeof(int) * (N + 1));
	int *x = (int *)malloc(sizeof(int) * (N + 1));
	int *y = (int *)malloc(sizeof(int) * (N + 1));
	t[0] = 0;
	x[0] = 0;
	y[0] = 0;
	for(i = 1; i <= N; i++){
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
	}
	for(i = 1; i <= N; i++){
		T = t[i] - t[i - 1];
		D = ABS(x[i] - x[i - 1]) + ABS(y[i] - y[i - 1]);
		if(T < D || (T - D) % 2 != 0){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &t[i], &x[i], &y[i]);
   ^