#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int T, N, D, t, n, j;
	int * d, * l, * b;
	
	d = (int *) malloc(MAX_SIZE * sizeof(d[0]));
	l = (int *) malloc(MAX_SIZE * sizeof(l[0]));
	b = (int *) malloc(MAX_SIZE * sizeof(b[0]));
	
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		
		for(n = 0; n < N; n++)
		{
			b[n] = 0;
		}
			
		for(n = 0; n < N; n++)
		{
			scanf("%d %d", &d[n], &l[n]); // vine dist, len
		}
		scanf("%d", &D); // dist to love
		
		b[0] = MIN(d[0], l[0]);
		for(j = MIN(0 + b[0], N - 1); j > 0; j--)
		{
			if(d[j] - d[0] <= b[0] && d[j] - d[0] > b[j])
			{
				if(d[j] - d[0] <= l[j])
					b[j] = d[j] - d[0];
				else if(l[j] > b[j])
					b[j] = l[j];
			}
			
		}
		for(n = 1; n < N; n++)
		{
			for(j = MIN(n + b[n], N - 1); j > n; j--)
			{
				if(d[j] - d[n] <= b[n] && d[j] - d[n] > b[j])
				{
					if(d[j] - d[n] <= l[j])
						b[j] = d[j] - d[n];
					else if(l[j] > b[j])
						b[j] = l[j];
				}
			}
		}
		for(n = N - 1; n >= 0; n--)
		{
			if(D - d[n] <= b[n])
				break;
		}
		/*for(j = 0; j < N; j++)
		{
			if(l[j] != 0)
				printf("%d ", b[j]);
		}
		printf("\n");*/
		printf("Case #%d: ", t);
		if(n < 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	free(d);
	free(l);
	free(b);
	return 0;
}
