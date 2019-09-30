#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 2000 + 10;

double t[maxn], x[maxn];
int n, T;
double d;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for (int nCase = 1; nCase <= TT; ++nCase) {
		scanf("%lf%d%d", &d, &n, &T);
		for (int i = 0; i < n; ++i) scanf("%lf%lf", &t[i], &x[i]);

		while (n - 2 >= 0 && x[n - 2] > d) --n;
		if (x[n - 1] > d) {
			double v = (x[n - 1] - x[n - 2]) / (t[n - 1] - t[n - 2]);
			x[n - 1] = d; t[n - 1] = t[n - 2] + (d - x[n - 2]) / v;
		}

		printf("Case #%d:\n", nCase);
		for (int i = 0; i < T; ++i) {
			double a;
			scanf("%lf", &a);
			double dist = 0, v = 0, res = 0;
			for (int j = 0; j + 1 < n; ++j) {
				double vv = (x[j + 1] - x[j]) / (t[j + 1] - t[j]);
				double mov = dist + v * (t[j + 1] - t[j]) + 0.5 * a * (t[j + 1] - t[j]) * (t[j + 1] - t[j]);
				if (mov < x[j + 1]) {
					dist = mov;
					v += a * (t[j + 1] - t[j]);
				}
				else {
					double A = 0.5 * a, B = v, C = -(x[j + 1] - dist);
					dist = x[j + 1];
					v += a * (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
				}
				res = t[j + 1];
			}
			if (dist < d) {
				double A = 0.5 * a, B = v, C = -(d - dist);
				res += (-B + sqrt(B * B - 4 * A * C )) / (2 * A);
			}

			printf("%lf\n", res);
		}
	}

	return 0;
}
