#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 1e-6
int main()
{
	int N;
	scanf("%d", &N);
	for (int r = 1; r <= N; r++)
	{
int res = 0;
long long L, P, C;

scanf("%lld %lld %lld", &L, &P, &C);
double F = log((double)P/L)/log(C);
//printf("F %lf\n", F);
double X = log(F)/log(2);

if (X - (double)((int)X) < EPS)
{
	res = (int)X;
}
else
{
	res = (int)(X) + 1;
}

if (res < 0) res = 0;
//printf("X %lf\n", X);
		printf("Case #%d: ", r);
		printf("%d\n", res);
	}

	return 0;
}

