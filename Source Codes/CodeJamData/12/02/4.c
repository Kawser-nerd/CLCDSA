#include <stdio.h>
#include <stdlib.h>

int faisable(int total, int p)
{
	int min, min2;
	if(p >= 2)
	{
		min = p-1;
		min2 = p-2;
	}
	else
	{
		min = 0;
		min2 = 0;
	}

	if(total >= p+2*min) return 1; // possible (sans surprise)
	else if(total >= p+2*min2) return 2; // possible (avec surprise)
	else return 0;
}

int main()
{
	int T, i, j, N, S, p, score, test, max;
	
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		max = 0;
		scanf("%d %d %d", &N, &S, &p);
		for(j = 0; j < N; j++)
		{
			scanf("%d", &score);
			test = faisable(score, p);
			if(test == 1)
			{
				max++;
			}
			else if(test == 2 && S > 0)
			{
				S--;
				max++;
			}
		}
		printf("Case #%d: %d\n", i+1, max);
	}

	return 0;
}
