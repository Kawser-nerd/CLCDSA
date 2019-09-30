#include <math.h>
#include <stdio.h>

#define N 1000000

int main(void)
{
	int T, A1, A2, B1, B2;
	int x, p;
	long long y;
	int c1[N + 1];
	int c2[N + 1];
	double tau;

	tau = (1 + sqrt(5)) / 2;
	for (x = 1; x <= N; x++) {
		c1[x] = (int) ceil(x / tau);
	}
	p = 1;
	for (x = 1; x <= N; x++) {
		while (p < N && c1[p + 1] == x) {
			p++;
		}
		c2[x] = p;
	}

	scanf("%d", &T);
	for (x = 1; x <= T; x++) {
		scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
		if (B2 - B1 < A2 - A1) {
			A1 ^= B1 ^= A1 ^= B1;
			A2 ^= B2 ^= A2 ^= B2;
		}
		y = 0;
		for (p = A1; p <= A2; p++) {
			if (B2 < c1[p] || B1 > c2[p]) {
				y += B2 - B1 + 1;
			} else if (B1 <= c1[p] && B2 >= c2[p]) {
				y += B2 - B1 + 1 - (c2[p] - c1[p] + 1);
			} else if (B1 < c1[p]) {
				y += c1[p] - B1;
			} else if (B2 > c2[p]) {
				y += B2 - c2[p];
			} else {
				y += 0;
			}
		}
		printf("Case #%d: %lld\n", x, y);
	}
	return 0;
}
