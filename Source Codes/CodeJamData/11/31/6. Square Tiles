#include <stdio.h>

char g[55][55];
int main()
{
	int ncase;
	int i, j;
	int icase;
	int r, c;
	int flag;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d", &r, &c);

		for(i = 0;i < r;i++)
			scanf("%s", g[i]);

		for(i = 0;i < r;i++)
			for(j = 1;j < c;j++)
			{
				if (g[i][j] == '#' && g[i][j - 1] == '#' && (i + 1) < r && g[i + 1][j] == '#' && g[i + 1][j - 1] == '#')
				{
					g[i][j - 1] = g[i + 1][j] = '/';
					g[i][j] = g[i + 1][j - 1] = '\\';
				}
			}

		flag = 1;
		for(i = 0;i < r;i++)
			for(j = 0;j < c;j++)
				if (g[i][j] == '#')
					flag = 0;

		printf("Case #%d:\n", icase);
		if (flag)
		{
			for(i = 0;i < r;i++)
				printf("%s\n", g[i]);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
