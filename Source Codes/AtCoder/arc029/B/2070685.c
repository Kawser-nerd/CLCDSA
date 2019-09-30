#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N, i;
	double A, B, tmp, x, y;
	scanf("%lf%lf", &A, &B);
	if(A > B){
		tmp = A;
		A = B;
		B = tmp;
	}
	scanf("%d", &N);
	double *C = (double *)malloc(sizeof(double) * N);
	double *D = (double *)malloc(sizeof(double) * N);
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lf%lf", &C[i], &D[i]);
		if(C[i] > D[i]){
			tmp = C[i];
			C[i] = D[i];
			D[i] = tmp;
		}
		ans[i] = 0;
	}
	for(i = 0; i < N; i++){
		if(A <= C[i] && B <= D[i]){
			ans[i] = 1;
		}
		else if(A * A + B * B > C[i] * C[i]){
			x = (A * A * C[i] + A * B * sqrt(A * A + B * B - C[i] * C[i])) / (A * A + B * B);
			y = (B * B * C[i] - A * B * sqrt(A * A + B * B - C[i] * C[i])) / (A * A + B * B);
			if(0 < x && x < C[i] && 0 < y && y < C[i]){
				if(x * B / A + y * A / B <= D[i]){
					ans[i] = 1;
				}
			}
			x = (A * A * C[i] - A * B * sqrt(A * A + B * B - C[i] * C[i])) / (A * A + B * B);
			y = (B * B * C[i] + A * B * sqrt(A * A + B * B - C[i] * C[i])) / (A * A + B * B);
			if(0 < x && x < C[i] && 0 < y && y < C[i]){
				if(x * B / A + y * A / B <= D[i]){
					ans[i] = 1;
				}
			}
		}
	}
	for(i = 0; i < N; i++){
		if(ans[i] == 1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf", &A, &B);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf", &C[i], &D[i]);
   ^