#include <stdio.h>
#include <stdlib.h>

int ABS(int a){
	return a >= 0 ? a : -a;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, Z, W, i, j;
	scanf("%d%d%d", &N, &Z, &W);
	int *a = (int *)malloc(sizeof(int) * (N + 1));
	a[0] = W;
	for(i = 1; i <= N; i++){
		scanf("%d", &a[i]);
	}
	int *dp_max = (int *)malloc(sizeof(int) * (N + 1));
	int *dp_min = (int *)malloc(sizeof(int) * (N + 1));
	for(i = N - 1; i >= 0; i--){
		dp_max[i] = ABS(a[i] - a[N]);
		for(j = i + 1; j < N; j++){
			dp_max[i] = max(dp_max[i], dp_min[j]);
		}
		dp_min[i] = ABS(a[i] - a[N]);
		for(j = i + 1; j < N; j++){
			dp_min[i] = min(dp_min[i], dp_max[j]);
		}
	}
	printf("%d\n", dp_max[0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &Z, &W);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^