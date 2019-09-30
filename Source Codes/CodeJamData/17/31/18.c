#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef struct {
	int r, h;
} pk_t;

int N, K;
pk_t P[1000];

long long int area(long long int r, long long int h) {
	return r * r + 2 * r * h;
}

long long int harea(long long int r, long long int h) {
	return 2 * r * h;
}

int pkcmp(const void *a, const void *b) {
	const pk_t *aa = a;
	const pk_t *bb = b;
	if (aa->r == bb->r)
		return bb->h - aa->h;
	return bb->r - aa->r;
}

long long int DP[1000][1000][2];

long long int best(int i, int taken, int base) {
	if (taken == K)
		return 0;
	if (i == N)
		return -1;
	if (DP[i][taken][base] >= 0)
		return DP[i][taken][base];
	long long int skip = best(i+1, taken, base);
	long long int take = best(i+1, taken+1, 0);
	if (take < 0)
		return skip;
	long long int a = base ? area(P[i].r, P[i].h) : harea(P[i].r, P[i].h);
	take += a;

	DP[i][taken][base] = take > skip ? take : skip;
	return DP[i][taken][base];
}


int main() {
	int t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &N, &K);
		for (int i = 0; i < N; ++i) {
			scanf("%d %d\n", &P[i].r, &P[i].h);
		}
		qsort(P, N, sizeof(pk_t), pkcmp);
		memset(DP, -1, sizeof(DP));
		long long int r = best(0, 0, 1);
		double rr = (double) r * M_PI;
		printf("Case #%d: %.9lf\n", x++, rr);
	}
	return 0;
}
