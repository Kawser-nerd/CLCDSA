#include <stdio.h>
#include <stdlib.h>

#define int long long

signed main(){
	int Ax, Ay, Bx, By, N, i, k = 0, Xinc, Yinc, C;
	scanf("%lld%lld%lld%lld", &Ax, &Ay, &Bx, &By);
	Xinc = Bx - Ax;
	Yinc = By - Ay;
	C = Bx * Ay - Ax * By;
	scanf("%lld", &N);
	int *X = (int *)malloc(sizeof(int) * N);
	int *Y = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &X[i], &Y[i]);
	}
	for(i = 0; i < N; i++){
		if((Yinc * X[i] - Xinc * Y[i] + C) * (Yinc * X[(i + 1) % N] - Xinc * Y[(i + 1) % N] + C) < 0
			&&
			((Y[(i + 1) % N] - Y[i]) * Ax - (X[(i + 1) % N] - X[i]) * Ay + X[(i + 1) % N] * Y[i] - X[i] * Y[(i + 1) % N])
			*
			((Y[(i + 1) % N] - Y[i]) * Bx - (X[(i + 1) % N] - X[i]) * By + X[(i + 1) % N] * Y[i] - X[i] * Y[(i + 1) % N])
			< 0){
			k++;
		}
	}
	printf("%lld\n", 1 + k / 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld", &Ax, &Ay, &Bx, &By);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &X[i], &Y[i]);
   ^