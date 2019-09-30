#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int s;
	int i;
	int p[];
} problem;

static problem *split(problem *x, int k)
{
	problem *y = malloc(sizeof(problem) + (size_t)x->i * sizeof(int));
	y->s = x->s + x->p[x->i] * (k - 1);
	y->i = x->i - 1;
	memcpy(y->p, x->p, (size_t)x->i * sizeof(int));
	for (int j = 0; j < k; j++)
		y->p[(x->i + j) / k] += x->p[x->i];
	return y;
}

static int solve(problem *x, int r) {
	double k_;
	if (x->p[x->i] == 0) {
		x->i--;
		return solve(x, r);
	}
	if (x->s + x->i < r) r = x->s + x->i;
	k_ = sqrt(x->i);
	for (int k = (int)k_; k > 1; k--) {
		problem *y = split(x, k);
		int q;
		/* if (y->s >= r) { */
		/* 	free(y); */
		/* 	continue; */
		/* } */
		q = solve(y, r);
		if (q < r) r = q;
	}
	free(x);
	return r;
}

int main(void) {
	int T;
	assert(scanf("%d", &T) == 1);
	for (int t = 1; t <= T; t++) {
		int D;
		int p[1001];
		int r = 0;
		problem *x;
		memset(p, 0, sizeof(p));
		assert(scanf("%d", &D) == 1);
		for (int i = 0; i < D; i++) {
			int j;
			assert(scanf("%d", &j) == 1);
			p[j]++;
			if (j > r) r = j;
		}
		x = malloc(sizeof(problem) + ((size_t)r + 1) * sizeof(int));
		x->s = 0;
		x->i = r;
		memcpy(x->p, p, ((size_t)r + 1) * sizeof(int));
		r = solve(x, r);
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}
