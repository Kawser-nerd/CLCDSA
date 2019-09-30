#include <stdio.h>
#include <math.h>
#include <assert.h>

#define MAXN		5000

int PX[MAXN], PY[MAXN], N;

double choppedslice(double r, double h)
{
	double r2, p, alpha;

	r2 = r * r;
	p = sqrt(r2 - h * h);
	alpha = atan2(p, h);

	return r2 * alpha - p * h;
}

double dist(int x1, int y1, int x2, int y2)
{
	int tx = x1 - x2, ty = y1 - y2;
	return sqrt(tx * tx + ty * ty);
}

double computearea2(double r1, double r2, double d)
{
	double t1, t2, t;

	t = d / 2 + (r1 * r1 - r2 * r2) / (2 * d);
	t1 = choppedslice(r1, t);
	t2 = choppedslice(r2, d - t);

	return t1 + t2;
}

double solve2(int QX, int QY)
{
	double r1, r2, d, answer;

	r1 = dist(QX, QY, PX[0], PY[0]);
	r2 = dist(QX, QY, PX[1], PY[1]);
	d = dist(PX[0], PY[0], PX[1], PY[1]);

	if (r1 < r2)
		answer = computearea2(r1, r2, d);
	else
		answer = computearea2(r2, r1, d);

	return answer;
}

void solve(void)
{
	int M, QX, QY;
	int i;

	scanf("%d %d", &N, &M);
	assert(N == 2);

	for (i = 0; i < N; i++) {
		scanf("%d %d", PX + i, PY + i);
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d", &QX, &QY);
		printf(" %.7lf", solve2(QX, QY));
	}
	printf("\n");
}

int main(void)
{
	int testno, T;

	scanf("%d", &T);
	for (testno = 1; testno <= T; testno++) {
		printf("Case #%d:", testno);
		solve();
	}

	return 0;
}
