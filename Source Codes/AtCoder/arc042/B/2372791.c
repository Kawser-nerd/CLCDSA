#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double min(double a, double b){
	return a <= b ? a : b;
}

double ABS(double a){
	return a >= 0 ? a : -a;
}

double distance(double x0, double y0, double a1, double b1, double a2, double b2){
	double A, B, C;
	A = b2 - b1;
	B = a1 - a2;
	C = a2 * b1 - a1 * b2;
	return ABS(A * x0 + B * y0 + C) / hypot(A, B);
}

int main(){
	double x0, y0;
	int N, i;
	scanf("%lf%lf", &x0, &y0);
	scanf("%d", &N);
	double *x = (double *)malloc(sizeof(double) * N);
	double *y = (double *)malloc(sizeof(double) * N);
	for(i = 0; i < N; i++){
		scanf("%lf%lf", &x[i], &y[i]);
	}
	double ans = distance(x0, y0, x[N - 1], y[N - 1], x[0], y[0]);
	for(i = 1; i < N; i++){
		ans = min(ans, distance(x0, y0, x[i - 1], y[i - 1], x[i], y[i]));
	}
	printf("%.12lf\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf", &x0, &y0);
  ^
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf", &x[i], &y[i]);
   ^