#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ncase = -1;

int a, b, nd, res;

int next(int x)
{
	int i,j,t = 1;
	for(j = 0;j < nd - 1;j++)
		t *= 10;
	i = x / t;
	j = x % t;
	return j*10+i;
}

void solve(int icase)
{
	printf("Case #%d: ", icase + 1);

	scanf("%d%d", &a, &b);
	int i = a;
	nd = 0;
	while( i > 0 )
	{
		nd++;
		i /= 10;
	}
	char ch[2000001];
	for( i = 0; i < 2000001; i++ )
		ch[i] = 0;
	
	res = 0;
	int j, k, c;
	if(nd > 1)
	{
		int* p = malloc(sizeof(int) * nd);
		for( i = a; i <= b; i++ )
		{
			if(ch[i])
				continue;
			
			ch[i] = 1;
			
			if(i == next(i))
				continue;
				
			p[0] = i;
			for( j = 1; j < nd; j++ )
				p[j] = next(p[j-1]);
			
			c = 1;
			for( j = 1; j < nd; j++ )
			{
				if(p[j] >= a && p[j] <= b)
				{
					if(!ch[p[j]])
					{
						ch[p[j]] = 1;
						c++;
					}
				}
			}
			if(c>1)
			{
				res += (c * (c-1)) / 2;
			}
		}
		free(p);
	}
	printf("%d\n", res);
}

int main()
{
	scanf("%d", &ncase);
	while(getchar()!='\n');
	
	int icase;
	for(icase = 0; icase < ncase; icase++)
		solve(icase);
}