#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		long long r, t;
		scanf("%lld %lld", &r, &t);
		long long left = 0, right = t / r / 2 + 2;
		while ( left < right - 1)
		{
			long long mid = ( left + right) >> 1;
			long long rest = t - mid * 2 * r;
			int aval = 0;
//			printf("%lld %lld\n", mid, rest);
			if ( rest >= 0)
			{
				rest += mid;
				rest >>= 1;
				if ( mid <= rest / mid + 1)
				{
					aval = rest >= mid * mid;
				}
			}
			if ( aval)
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
		printf("Case #%d: %lld\n", cases + 1, left);
	}

	return 0;
}
