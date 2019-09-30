#include <stdio.h>
#include <stdlib.h>

#define max_size (int)(1e5)

int main(){
	int N, i, w, d, l;
	scanf("%d", &N);
	int **num = (int **)malloc(sizeof(int *) * (max_size + 1));
	int *sum = (int *)malloc(sizeof(int) * (max_size + 1));
	for(i = 0; i <= max_size; i++){
		num[i] = (int *)malloc(sizeof(int) * 3);
		num[i][0] = 0;
		num[i][1] = 0;
		num[i][2] = 0;
	}
	int *R = (int *)malloc(sizeof(int) * N);
	int *H = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &R[i], &H[i]);
		H[i]--;
		num[R[i]][H[i]]++;
	}
	sum[0] = 0;
	for(i = 1; i <= max_size; i++){
		sum[i] = sum[i - 1] + num[i][0] + num[i][1] + num[i][2];
	}
	for(i = 0; i < N; i++){
		w = sum[R[i] - 1] + num[R[i]][(H[i] + 1) % 3];
		d = num[R[i]][H[i]] - 1;
		l = N - w - d - 1;
		printf("%d %d %d", w, l, d);
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &R[i], &H[i]);
   ^