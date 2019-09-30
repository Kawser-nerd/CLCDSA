#include <stdio.h>

#define MAXN 500000

#define MIN(a, b) (((a)<(b))?(a):(b))

double a[MAXN], f[MAXN], min, tmp;
int n, cc, A, B, t;
int main()
{
	int i, j, k;
	scanf("%d", &cc);
	f[0] = 1;
	for (t = 1; t <= cc; t++) {
		scanf("%d %d", &A, &B);
		for (i = 1; i <= A; i++) {
			scanf("%lf", a + i);
			f[i] = f[i - 1] * a[i];
		}
		min = 2 + B;
		for (i = 1; i <= A; i++) {
			tmp = f[i] * (A - i + B - i + 1) + (1 - f[i]) * (A - i + B - i + 1 + B + 1);
			min = MIN(min, tmp);
			//printf("%d %lf %lf\n", i, f[i], tmp);
		}
		printf("Case #%d: %0.6lf\n", t, min);
	}
}
