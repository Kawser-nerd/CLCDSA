#include <stdio.h>
#include <math.h>

double tri(double R, double H) {
	return M_PI * R * R * H / 3;
}

int main() {
	int i, j;
	int N, Q;
	double sum, X[110], R[110], H[110], l, r, ta,  A, B;
	scanf("%d %d", &N, &Q);
	for(i=0;i<N;i++) scanf("%lf %lf %lf", &X[i], &R[i], &H[i]);

	for(i=0;i<Q;i++) {
		sum = 0;
		scanf("%lf %lf", &A, &B);
		for(j=0;j<N;j++) {
			l = X[j];
			r = l + H[j];
			ta = R[j] / H[j];
			if(l <= A && A <= r && r <= B) {
				sum += tri(R[j] - (A - X[j]) * R[j] / H[j] , r - A);
			}
			else if(l <= A && B <= r) {
				sum += tri(R[j] - (A - X[j]) * ta, r - A);
				sum -= tri(R[j] - (B - X[j]) * ta, r - B);
			}
			else if(A <= l && r <= B) {
				sum += tri(R[j], H[j]);
			}
			else if(A <= l && l <= B && B <= r) {
				sum += tri(R[j], H[j]);
				sum -= tri(R[j] - (B - X[j]) * ta , r - B);
			}
		}
		printf("%lf\n", sum);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &Q);
  ^
./Main.c:13:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++) scanf("%lf %lf %lf", &X[i], &R[i], &H[i]);
                   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf", &A, &B);
   ^