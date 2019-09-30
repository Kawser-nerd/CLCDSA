#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 1000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int N;
int x[1001];
int y[1001];
int c[1001];

double eval(double X, double Y) {
	int i;
	double ret = 0;
	
	for(i=1;i<=N;i++) {
		ret = max(ret, c[i]*max(fabs(x[i]-X), fabs(y[i]-Y)));
	}
	
	return ret;
}

int main() {
	int i;
	double gx, gy;
	double dif;
	double now;
	
	scanf("%d", &N);
	gx = gy = 0.0;
	for(i=1;i<=N;i++) {
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
		gx += x[i];
		gy += y[i];
	}
	gx /= N;
	gy /= N;
	
	now = eval(gx, gy);
	dif = 100;
	while(dif > 0.000000001) {
		if(now > eval(gx + dif, gy)) {
			now = eval(gx + dif, gy);
			gx += dif;
		} else if(now > eval(gx - dif, gy)) {
			now = eval(gx - dif, gy);
			gx -= dif;
		} else if(now > eval(gx, gy + dif)) {
			now = eval(gx, gy + dif);
			gy += dif;
		} else if(now > eval(gx, gy - dif)) {
			now = eval(gx, gy - dif);
			gy -= dif;
		} else if(now > eval(gx + dif, gy + dif)) {
			now = eval(gx + dif, gy + dif);
			gx += dif;
			gy += dif;
		} else if(now > eval(gx + dif, gy - dif)) {
			now = eval(gx + dif, gy - dif);
			gx += dif;
			gy -= dif;
		} else if(now > eval(gx - dif, gy + dif)) {
			now = eval(gx - dif, gy + dif);
			gx -= dif;
			gy += dif;
		} else if(now > eval(gx - dif, gy - dif)) {
			now = eval(gx - dif, gy - dif);
			gx -= dif;
			gy -= dif;
		} else {
			dif /= 2.0;
		}
		//printf("Debug: (%lf, %lf)\n", gx, gy);
	}
	
	printf("%lf\n", now);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &x[i], &y[i], &c[i]);
   ^