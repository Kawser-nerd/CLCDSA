#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int solve(int R, int C, int N, char *p, int r, int c, int u, int m)
{
	if (++c > C) {
		c = 1;
		r++;
	}
	if (r > R) return u;
	if (N <= (R - r) * C + C - c) {
		p[r * (C + 2) + c] = 0;
		int m_ = solve(R, C, N, p, r, c, u, m);
		if (m_ < m) m = m_;
	}
	p[r * (C + 2) + c] = 1;
	N--;
	u += p[(r - 1) * (C + 2) + c];
	u += p[r * (C + 2) + c - 1];
	int m_ = solve(R, C, N, p, r, c, u, m);
	if (m_ < m) m = m_;
	return m;
}

int main(void) {
	int T_;
	assert(scanf("%d", &T_) == 1);
	for (int t_ = 1; t_ <= T_; t_++) {
		int R, C, N;
		assert(scanf("%d %d %d", &R, &C, &N) == 3);
		size_t s = (size_t)(R + 2) * (size_t)(C + 2);
		char *p = malloc(s);
		memset(p, 0, s);
		printf("Case #%d: %d\n", t_,
		       solve(R, C, N, p, 1, 0, 0, C * (R - 1) + R * (C - 1)));
		free(p);
	}
	return 0;
}
