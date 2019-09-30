#include <stdio.h>
#include <limits.h>
#include <math.h>
#define MAXN 200
#define P 100000000

int points[MAXN];
int N;
int sum;

int avail( int p, long long per)
{
	long long low = points[p];
	low *= P;
	low += per * sum;

	int i;
	long long one = P;
	for ( i = 0; i < N; i++)
	{
		long long cur = points[i];
		cur *= P;
		if ( low - cur > 0)
		{
			long long d = ceil( ( low - cur) / ( double) sum);
			one -= d;
		}
		if ( one < 0)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d", &N);
		int i;
		sum = 0;
		for ( i = 0; i < N; i++)
		{
			scanf( "%d", points + i);
			sum += points[i];
		}

		printf("Case #%d:", cases + 1);
		for ( i = 0; i < N; i++)
		{
			long long left = -1, right = P;
			while ( right - left > 1)
			{
				long long mid = ( left + right) >> 1;

				if ( !avail( i, mid))
				{
					left = mid;
				}
				else
				{
					right = mid;
				}
			}
			printf(" %lf", right * 100 / ( double) P);
		}
		printf("\n");
	}

	return 0;
}
