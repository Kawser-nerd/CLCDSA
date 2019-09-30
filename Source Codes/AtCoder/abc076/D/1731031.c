#include <stdio.h>

int n;
int total = 0;
int t[300] = {0};
int vs[300] = {0};

double f(double l, double r, double v, double x) {
	if(x < l) return v + l - x;
	if(l <= x && x <= r) return v;
	return v + x - r;
}

double vel(double x) {
	double minv = f(0, 0, 0, x);
	double new = f(total, total, 0, x);
	minv = minv < new ? minv : new;
	int i;
	double l = 0, r = 0;
	for(i=0;i<n;i++) {
		r += t[i];
		new = f(l, r, vs[i], x);
		minv = minv < new ? minv : new;
		l = r;
	}
	return minv;
}

int main() {
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i++) {
		scanf("%d", &t[i]);
		total += t[i];
	}
	for(i=0;i<n;i++) {
		scanf("%d", &vs[i]);
	}
	double area = 0;
	for(i=0;i<total;i++) {
		area += 0.25 * (vel(i) + 2 * vel(i+0.5) + vel(i+1));
	}
	printf("%f\n", area);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &t[i]);
   ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &vs[i]);
   ^