#include <cstdio>

int T, m, x, c;
double p, q, pr[16][65537], t;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d%lf%d", &m, &p, &x);
		q = 1 - p;
		pr[0][0] = 0;
		pr[0][1] = 1;
		for (int i = 1; i <= m; ++i)
			for (int j = 0; j <= 1 << i; ++j) {
				pr[i][j] = pr[i - 1][j >> 1];
				for (int k = 0; k <= j && k + j <= (1 << i); ++k)
					if (pr[i][j] < (t = p*pr[i - 1][j + k >> 1] + q*pr[i - 1][j - k >> 1]))
						pr[i][j] = t;
			}
		c = 0;
		for (int i = 0; i <= m; ++i) {
			c <<= 1;
			if (x >= 1000000) {
				++c;
				x -= 1000000;
			}
			x <<= 1;
		}
		printf("%.6lf\n", pr[m][c]);
	}
	return 0;
}
