#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 2000
double r[MAXN], x[MAXN], y[MAXN], w, h, tx, ty, tz;
int n, cc, t, kk, finish;

double randD() {
	return (double)(rand() & 32767) / 32768.0;
}

double sqr(double x) {
	return x*x;
}

int main() {
	int i, j, k;
	srand(time(NULL));
	scanf("%d", &cc);
	for (t = 1; t <= cc; t++) {
		scanf("%d %lf %lf", &n, &w, &h);
		for (i = 1; i <= n; i++)
			scanf("%lf", r + i);
		finish = 0;
		while (!finish) {
		kk = 0;
		for (i = 1; i <= n; i++) {
			x[i] = randD() * w;
			y[i] = randD() * h;
		}
		while (kk < n * n  && !finish) {
			finish = 1;
			kk++;
			for (i = 1; i <= n; i++)
			 	for (j = i + 1; j <= n; j++) {
					tx = x[i] - x[j];
					ty = y[i] - y[j];
					tz = sqrt(sqr(tx) + sqr(ty));
					tx /= tz;
					ty /= tz;
					if (tz < r[i] + r[j]) {
						finish = 0;
						tz = (r[i] + r[j] - tz) / 1.5;
						x[i] += tx * tz;
						y[i] += ty * tz;
						x[j] -= tx * tz;
						y[j] -= ty * tz;
						if (x[i] < 0 || x[i] > w || y[i] < 0 || y[i] > h) {
							x[i] -= tx * tz;
							y[i] -= ty * tz;
							x[j] -= tx * tz;
							y[j] -= ty * tz;
							tz *= 2;
						}
						if (x[j] < 0 || x[j] > w || y[j] < 0 || y[j] > h) {
							x[i] += tx * tz;
							y[i] += ty * tz;
							x[j] += tx * tz;
							y[j] += ty * tz;

						}
						if (x[i] < 0 || x[i] > w || y[i] < 0 || y[i] > h) {
							kk = n * n + 1;
						}

					}
				}
		}
		}
		printf("Case #%d:", t);
		for (i = 1; i <= n; i++) printf(" %lf %lf", x[i], y[i]);
		printf("\n");
	}
}
