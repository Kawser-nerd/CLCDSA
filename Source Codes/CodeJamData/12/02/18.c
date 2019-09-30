#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ncase = -1;
int n, s, p;

int max(int total, int* score, int sup)
{	
	int i,j,k,c = 0;

	if(total == 0)
		return 0;
	
	if(sup == 0)
	{
		for(i = 0; i < total; i++)
			if(score[i] > 3 * (p-1))
				c++;
	}
	else
	{
		int* s2 = malloc((total-1)*sizeof(int));
		for(i = 0; i < total; i++)
		{
			k = 0;
			for(j = 0; j < total; j++)
				if(j != i)
					s2[k++] = score[j];
			int max1 = 0;
			int max2 = 0;
			if(total > sup)
			{
				max1 = max(total-1, s2, sup);
				if(max1 > c)
					c = max1;
			}
			if(score[i] > 2)
			{
				max2 = max(total-1, s2, sup-1);
				if(score[i] >= p * 3 - 4)
					max2++;
				if(max2 > c)
					c = max2;
			}
		}
		free(s2);
	}

	return c;
}

void solve(int icase)
{
	printf("Case #%d: ", icase + 1);
	
 	int i, j, k;
	scanf("%d%d%d", &n, &s, &p);
	
	int* score = malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &score[i]);

	printf("%d", max(n, score, s));
	free(score);
	putchar('\n');
}

int main()
{
	scanf("%d", &ncase);
	while(getchar()!='\n');

	int icase = 0;
	for(icase = 0; icase < ncase; icase++)
		solve(icase);
}