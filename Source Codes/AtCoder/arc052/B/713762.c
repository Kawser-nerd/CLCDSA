#include <stdio.h>
#include <math.h>

double X[100];
double R[100];
double H[100];

int N, Q;

double solve(double A,double B);

double PI = 4.0*atan(1.0);

int main() {

	scanf("%d %d",&N,&Q);

	int i;

	for (i = 0; i < N; i++) {
		scanf("%lf %lf %lf",&X[i],&R[i],&H[i]);
	}

	double A, B;

	for (i = 0; i < Q; i++) {
		scanf("%lf %lf",&A,&B);
		printf("%lf\n",solve(A,B));
	}


	return 0;
}
double solve(double A, double B) {

	int i;

	double sum = 0;

	double A1, B1;

	for (i = 0; i < N; i++) {

		if (X[i] <= A&&A <= X[i] + H[i]) {
			A1 = A;
		}
		else if (X[i] + H[i] < A) {
			continue;
		}
		else {
			A1 = X[i];
		}

		if (X[i] <= B&&B <= X[i] + H[i]) {
			B1 = B;
		}
		else if (X[i] > B) {
			continue;
		}
		else {
			B1 = X[i]+H[i];
		}


		double r = R[i] * (X[i]+H[i]-A1)/ H[i];
		double h = X[i] + H[i] - A1;

		double S1 = (PI*r*r*h) / 3.0;

		r= R[i] * (X[i] + H[i] - B1) / H[i];
		h= X[i] + H[i] - B1;

		double S2= (PI*r*r*h) / 3.0;

		sum += S1 - S2;

	}
	return sum;

} ./Main.c:12:13: warning: initializer element is not a constant expression
 double PI = 4.0*atan(1.0);
             ^
./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&Q);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf",&X[i],&R[i],&H[i]);
   ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&A,&B);
   ^