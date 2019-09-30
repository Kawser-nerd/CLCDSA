#include <stdio.h>
#include <stdlib.h>
#define inf 1e9

double min(double a, double b){
	return a <= b ? a : b;
}

int main(){
	int N, i, j;
	double nowv = 0, ans = 0, x, x1, x2, b;
	scanf("%d", &N);
	double *t = (double *)malloc(sizeof(double) * (N + 1));
	double *t_sum = (double *)malloc(sizeof(double) * (N + 1));
	double *v = (double *)malloc(sizeof(double) * (N + 1));
	t_sum[0] = 0;
	for(i = 0; i < N; i++){
		scanf("%lf", &t[i]);
		t_sum[i + 1] = t_sum[i] + t[i];
	}
	for(i = 0; i < N; i++){
		scanf("%lf", &v[i]);
	}
	t[N] = 0;
	v[N] = 0;
	for(i = 0; i < N; i++){
//		printf("i = %d\n", i);
		b = inf;
		for(j = i + 1; j <= N; j++){
//			printf("j = %d\n", j);
//			printf("(v[j], t_sum[j]) = (%lf, %lf)\n", v[j], t_sum[j]);
//			printf("v[j] + t_sum[j] = %lf\n", v[j] + t_sum[j]);
			b = min(b, v[j] + t_sum[j]);
		}
//		printf("b = %lf\n", b);
		if(v[i] + t_sum[i + 1] < b){
			if(nowv + t[i] <= v[i]){
//				printf("test1\n");
				ans += t[i] * (2 * nowv + t[i]) / 2;
				nowv = nowv + t[i];
			}
			else{
				x = v[i] - nowv + t_sum[i];
//				printf("test2: x = %lf\n", x);
				ans += (v[i] + nowv) * (x - t_sum[i]) / 2 + v[i] * (t_sum[i + 1] - x);
				nowv = v[i];
			}
		}
		else{
			if((nowv - t_sum[i] + b) / 2 <= v[i]){
				x = (t_sum[i] + b - nowv) / 2;
//				printf("test3: x = %lf\n", x);
				if(x <= t_sum[i + 1]){
					ans += (x - t_sum[i]) * (nowv + b - x) / 2 + (t_sum[i + 1] - x) * (b - x + b - t_sum[i + 1]) / 2;
					nowv = b - t_sum[i + 1];
				}
				else{
					ans += t[i] * (2 * nowv + t[i]) / 2;
					nowv = nowv + t[i];
				}
			}
			else{
				x1 = v[i] + t_sum[i] - nowv;
				x2 = b - v[i];
//				printf("test4: (x1, x2) = (%lf, %lf)\n", x1, x2);
				ans += (x1 - t_sum[i]) * (nowv + v[i]) / 2 + v[i] * (x2 - x1) + (t_sum[i + 1] - x2) * (v[i] + b - t_sum[i + 1]) / 2;
				nowv = b - t_sum[i + 1];
			}
		}
	}
	printf("%lf\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &t[i]);
   ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &v[i]);
   ^