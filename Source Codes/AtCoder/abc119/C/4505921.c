#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int ABS(int a){
	return a >= 0 ? a : -a;
}

int main(){
	int N, A, B, C, i, j, k;
	scanf("%d%d%d%d", &N, &A, &B, &C);
	int *l = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &l[i]);
	}
	int a[4], ans = 1000000000, now;
	for(i = 0; i < (1 << (2 * N)); i++){
//		printf("i = %d\n", i);
		for(k = 0; k < 4; k++){
			a[k] = 0;
		}
		now = 0;
		for(j = 0; j < N; j++){
			k = ((i >> (2 * j)) & 3);
			if(i == 4626){
//			printf("(j, k) = (%d, %d)\n", j, k);
}			if(k > 0 && a[k] > 0){
				now += 10;
			}
			a[k] += l[j];
		}
		if(a[1] == 0 || a[2] == 0 || a[3] == 0){
			continue;
		}
		now += ABS(A - a[1]);
		now += ABS(B - a[2]);
		now += ABS(C - a[3]);
//		printf("now = %d\n", now);
		ans = min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &N, &A, &B, &C);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &l[i]);
   ^