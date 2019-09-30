#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
	const double *ad = a, *bd = b;

	return *ad < *bd ? -1 : *ad > *bd;
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		int N;
		
		scanf("%d", &N);
		
		double k[N], n[N];
		
		for (int i = 0; i < N; i++)
		{
			scanf("%lf", &n[i]);
		}
		
		for (int i = 0; i < N; i++)
		{
			scanf("%lf", &k[i]);
		}
		
		qsort(k, N, sizeof(double), &cmp);
		qsort(n, N, sizeof(double), &cmp);
		
		printf("Case #%d: ", Q);
		
		// deceitful war
		
		// Ken's strategy is
		// - if Told is unbeatable, use your lowest
		// - otherwise use the lowest that will win
		
		// so Naomi's is
		// - go throw your stones from low to high
		// - if the current stone is bigger than Ken's smallest,
		//   say it's bigger than his biggest FTW
		// - otherwise say it's just smaller than his biggest FTL
		
		int i, j;
		
		for (i = j = 0; i < N; i++)
		{
			if (n[i] > k[j])
			{
				j++;
			}
		}
		
		printf("%d ", j);
		
		// war
		
		int w = 0;
		
		for (i = j = 0; i < N, j < N; i++)
		{
			while (n[i] > k[j])
			{
				j++;
				
				if (j == N)
				{
					goto done;
				}
			}
			
//			printf("%lf < %lf\n", n[i], k[j]);
			
			j++;
			w++;
		}
		
		done:
		
		printf("%d\n", N - w);
	}
}