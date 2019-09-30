#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

static int solve(int X, int R, int C)
{
	if (X == 1) return 0;
	if (X >= 7) return 1;
	if (R * C % X) return 1;
	if (X == 2) return 0;
	if (R == 1 || C == 1) return 1;
	if (X == 3) return 0;
	if (R < X && C < X) return 1;
	if (R == 2 || C == 2) return 1;
	if (X == 4) return 0;
	if (X == 5) return R + C == 8;
	if (R == 3 || C == 3) return 1;
	return 0;
}

int main(void) {
	int T;
	assert(scanf("%d", &T) == 1);
	for (int t = 1; t <= T; t++) {
		int X, R, C, r;
		assert(scanf("%d", &X) == 1);
		assert(scanf("%d", &R) == 1);
		assert(scanf("%d", &C) == 1);
		r = solve(X, R, C);
		printf("Case #%d: %s\n", t, r ? "RICHARD" : "GABRIEL");
	}
	return 0;
}
