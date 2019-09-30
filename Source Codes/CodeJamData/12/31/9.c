#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int map[1010][1010], n, vist[1010];

int dfs(int x)
{
	int i, tmp;
	vist[x] = 1;
	for(i=1; i<=n; i++)
	{
		if(map[x][i])
		{
			if( vist[i] )
				return 1;
			else
				tmp = dfs(i);
			if(tmp == 1)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int t, cas, i, j, chn, tmp;
	scanf("%d", &t);
	for(cas=1; cas<=t; cas++)
	{
		memset(map, 0, sizeof(map));
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%d", &chn);
			for(j=0; j<chn; j++)
			{
				scanf("%d", &tmp);
				map[i][tmp] = 1;
			}
		}
		printf("Case #%d: ", cas);
		for(i=1; i<=n; i++)
		{
			memset(vist, 0, sizeof(vist));
			if(dfs(i))
			{
				printf("Yes\n");
				break;
			}
		}
		if(i>n)
			printf("No\n");
	}
	return 0;
}
