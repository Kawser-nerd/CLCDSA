#include <stdio.h>
#include <string.h>

char drink[2000][2000];
char mix[2000];
int deg[2000];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; c++)
	{
		int m,n;
		memset(drink, 0, sizeof(drink));
		memset(mix, 0, sizeof(mix));

		scanf("%d %d", &n, &m);
		for (int i=0; i<m; i++)
		{
			scanf("%d", &deg[i]);
			for (int tt = 0; tt < deg[i]; tt++)
			{
				int x,y;
				scanf("%d %d", &x, &y);
				drink[i][x-1] = y+1;
			}
		}
		printf("Case #%d:", c);
		while(1)
		{
			int i;
			for (i=0; i<m; i++)
			{
				if (deg[i] == 0) goto impossible;
				if (deg[i] == 1)
				{
					int j;
					for (j=0; j<n; j++) if (drink[i][j] != 0) break;
					int t = drink[i][j];

					mix[j] = t-1;
					deg[i] = -1;
					for (int k=0; k<m; k++)
						if (drink[k][j])
							if (drink[k][j] == t) deg[k] = -1;
							else { drink[k][j] = 0; deg[k]--; }
					break;
				}
			}
			if (i >= m) break;
		}
		for (int i=0; i<n; i++) printf(" %d", mix[i]);
		printf("\n");
		continue;
impossible:
		printf(" IMPOSSIBLE\n");
	}
	return 0;
}
