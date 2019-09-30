#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<stack>

using namespace std;

const int maxn = 1005;


struct point
{
	double x, y;
};

int W, L, U, G;
double x, y;

point lower[maxn], upper[maxn];

double down(point X, point Y)
{
	return (X.y + Y.y) * (Y.x - X.x) / 2;
}

double down(point X, point Y, double bound)
{
	double ratio = (bound - X.x) / (Y.x - X.x);
	point Z;
	Z.x = bound;
	Z.y = X.y * (1 - ratio) + Y.y * ratio;

	return down(X, Z);
}

double area(double bound)
{
	double res = 0;
	
	for(int i=1; i<U; i++)
	{
		if(upper[i].x < bound)
		{
			res += down(upper[i-1], upper[i]);
		}
		else
		{
			res += down(upper[i-1], upper[i], bound);
			break;
		}
	}

	for(int i=1; i<L; i++)
	{
		if(lower[i].x < bound)
		{
			res -= down(lower[i-1], lower[i]);
		}
		else
		{
			res -= down(lower[i-1], lower[i], bound);
			break;
		}
	}

	return res;
}

double getSlice(double sum)
{
	double lower = 0, upper = W;

	for(int times = 0; times <= 500; times++)
	{
		double mid = (lower + upper) / 2;
		if(area(mid) > sum) upper = mid;
		else lower = mid;
	}

	return upper;
}

int main()
{
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int test=1; test<=ntest; test++)
	{
		scanf("%d%d%d%d", &W, &L, &U, &G);
		
		for(int i=0; i<L; i++)
		{
			scanf("%lf%lf", &x, &y);
			lower[i].x = x;
			lower[i].y = y;
		}

		for(int i=0; i<U; i++)
		{
			scanf("%lf%lf", &x, &y);
			upper[i].x = x;
			upper[i].y = y;
		}

		double sum = area(W);

		printf("Case #%d:\n", test);
		for(int i=1; i<G; i++)
		{
			printf("%.10lf\n", getSlice(sum * i / G));
		}
	}
	return 0;
}
