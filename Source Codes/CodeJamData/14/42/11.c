#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T;

	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		int N;
		
		scanf("%d", &N);
		
		char d[12];
		
		int a[N];
		
		for (int j = 0; j < N; j++)
		{
			scanf(" %s", d);
			
			a[j] = strtol(d, NULL, 10);
			
//			printf("%d ", a[j]);
		}
		
//		putchar('\n');
		
		int moves = 0;
			
		// for each small thing, find the quickest place to move it to the side
			
		int tide = 0;
			
		for (int l = 0; l < N; l++)
		{
			int curr = -1;
			int gt = 0;
			int gtlcurr = 0;

			for (int i = 0; i < N; i++)
			{
				if (a[i] > tide)
				{				
					if (curr == -1 || a[i] < a[curr])
					{
						gtlcurr = gt;
						curr = i;
					}
						
					gt++;
				}
			}
				
			tide = a[curr];
				
			int gtgcurr = gt - gtlcurr - 1;
			
//			printf("%d %d %d\n", a[curr], gtlcurr, gtgcurr);
				
			if (gtlcurr < gtgcurr)
			{
				moves += gtlcurr;
			}
			else
			{
				moves += gtgcurr;
			}
		}
		
		printf("Case #%d: %d\n", Q, moves);
	}
}