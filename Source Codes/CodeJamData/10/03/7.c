#include <stdio.h>

int main(void)
{
	long long T, R, k, N;
	long long g[1000];
	long long t[1000];
	long long n[1000];
	long long i, j, p;
	long long s, r;
	long long y;

	scanf("%lld", &T);
	for (i = 0; i < T; i++) {
		scanf("%lld%lld%lld", &R, &k, &N);
		s = 0;
		for (j = 0; j < N; j++) {
			scanf("%lld", &g[j]);
			s += g[j];
		}
		for (j = 0; j < N; j++) {
			if (k >= s) {
				t[j] = s;
				n[j] = j;
				continue;
			}
			r = k;
			t[j] = 0;
			for (p = j; r >= g[p]; p = (p + 1) % N) {
				t[j] += g[p];
				r -= g[p];
			}
			n[j] = p;
		}
		y = 0;
		p = 0;
		for (j = 0; j < R; j++) {
			y += t[p];
			p = n[p];
		}
		printf("Case #%lld: %lld\n", i + 1, y);
	}

	return 0;
}
