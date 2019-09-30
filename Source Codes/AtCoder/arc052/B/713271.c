#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
 
#define INF 10000000000
#define PI 3.14159265358979

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int N, Q;
	int X[100];
	double R[100];
	double H[100];
	int A, B;
	double h;
	double v;
	double ans[100000];
	int i, j;
	double x, y;
	double l;
	double q;
	
	scanf("%d %d", &N, &Q);
	for(i=0;i<N;i++) {
		scanf("%d %lf %lf", &X[i], &R[i], &H[i]);
	}
	
	for(i=0;i<Q;i++) {
		scanf("%d %d", &A, &B);
		ans[i] = 0;
		for(j=0;j<N;j++) {
			if(A <= X[j] && X[j] < B) {
				h = min(H[j], B-X[j]);
				h = H[j] - h;
				v = R[j] * R[j] / 3 * PI * H[j];
				ans[i] += (v - v*pow(h/H[j], 3));
			}
		}
		
		for(j=0;j<N;j++) {
			if(X[j] < A && A < X[j]+H[j]) {
				h = X[j] + H[j] - A;
				l = h - min(B-A, h);
				q = H[j] - h;
				v = R[j] * R[j] / 3 * PI * H[j];
				x = v * pow(h/(q+h), 3);
				y = x * pow(l/h, 3);
				ans[i] += x - y;
			}
		}
	}
	
	for(i=0;i<Q;i++) {
		printf("%lf\n", ans[i]);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &Q);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %lf %lf", &X[i], &R[i], &H[i]);
   ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &A, &B);
   ^