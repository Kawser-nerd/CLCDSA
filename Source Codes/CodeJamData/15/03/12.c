#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define read1(fmt, p)						\
	do {							\
		if (scanf(fmt, p) != 1)				\
			err(1, "%s:%d", __FILE__, __LINE__);	\
	} while (0)

typedef uint8_t quat;
static const quat P1 = 0;
static const quat Pi = 1;
static const quat Pj = 2;
static const quat Pk = 3;
static const quat N1 = 4;
static const quat Ni = 5;
static const quat Nj = 6;
static const quat Nk = 7;
#define qs(x) ((x) & 4)
#define qv(x) ((x) & 3)
static const quat mt[4][4] = {
	{P1, Pi, Pj, Pk},
	{Pi, N1, Pk, Nj},
	{Pj, Nk, N1, Pi},
	{Pk, Pj, Ni, N1},
};
#define mult(x, y) ((qs(x) ^ qs(y)) ^ mt[qv(x)][qv(y)])

static int solve(uint64_t L, uint64_t X, quat *c)
{
	uint64_t a, b, LX = L * X;
	quat q;
	for (q = P1, a = 0; q != Pi && a < LX - 1; a++)
		q = mult(q, c[a % L]);
	if (q != Pi) return 0;
	for (q = P1, b = LX - 1; q != Pk && b > 0; b--)
		q = mult(c[b % L], q);
	if (q != Pk) return 0;
	for (q = P1; a <= b; a++)
		q = mult(q, c[a % L]);
	return q == Pj;
}

int main(void) {
	int T;
	read1("%d", &T);
	for (int t = 1; t <= T; t++) {
		uint64_t L, X;
		int r;
		char *c;
		read1("%lu", &L);
		read1("%lu", &X);
		c = malloc(L + 1);
		read1("%s", c);
		for (uint64_t i = 0; i < L; i++)
			c[i] = qv(c[i]);
		r = solve(L, X, (quat *)c);
		free(c);
		printf("Case #%d: %s\n", t, r ? "YES" : "NO");
	}
	return 0;
}
