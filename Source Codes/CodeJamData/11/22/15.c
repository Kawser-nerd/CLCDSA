#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXC 20
#define MAX( a, b) ( ( a) > ( b) ? ( a) : ( b))
#define MIN( a, b) ( ( a) < ( b) ? ( a) : ( b))

int pos[MAXC];
int cnt[MAXC];
int C, D;

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d %d", &C, &D);
		int i;
		for ( i = 0; i < C; i++)
		{
			scanf("%d %d", pos + i, cnt + i);
		}


		double left = 0.0, right = 1e8;

		while ( fabs( right - left) >= 1e-8)
		{
			double mid = ( left + right) * 0.5;

			double aval = -1e8;
			int flag = 1;
			for ( i = 0; i < C && flag; i++)
			{
				double curl = pos[i] - mid;
				if ( aval < curl)
				{
					if ( mid + mid < ( cnt[i] - 1) * D)
					{
						flag = 0;
					}
					else
					{
						aval = curl + cnt[i] * D;
					}
				}
				else
				{
					if ( aval + ( cnt[i] - 1) * D - pos[i] > mid)
					{
						flag = 0;
					}
					else
					{
						aval = aval + cnt[i] * D;
					}
				}

			}


			if ( flag)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}

		printf("Case #%d: %.10lf\n", cases + 1, right);
	}

	return 0;
}


