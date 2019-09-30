#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

#define MAX 2100

double ts[MAX];
double xs[MAX];
double D;
int N;

double f(double a)
{
	double t0 = 0;
	for (int i = 1; i < N; i++)
	{
		double bcpt = -1;
		double bcpx = -1;
		if (xs[i] > D)
		{
			double vv = (xs[i] - xs[i-1]) / (ts[i] - ts[i-1]);
			bcpx = xs[i];
			xs[i] = D;
			bcpt = ts[i];
			ts[i] = ts[i-1] + (xs[i] - xs[i-1]) / vv;
		}
		double tt = ts[i] - sqrt(xs[i] * 2 / a);
		t0 = max(t0, tt);

		if (bcpt != -1)
		{
			ts[i] = bcpt;
			xs[i] = bcpx;
			break;
		}
	}
	double t = sqrt(D * 2 / a) + t0;
	return t;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int A;
		scanf("%lf%d%d", &D, &N, &A);
		for (int i = 0; i < N; i++)
			scanf("%lf%lf", &ts[i], &xs[i]);
		printf("Case #%d:\n", t+1);
		for (int i = 0; i < A; i++)
		{
			double a;
			scanf("%lf", &a);
			double res = f(a);
			printf("%.7lf\n", res);
		}
	}

	return 0;
}