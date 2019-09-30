// some things were done by hand too
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b) { return (a<b)?a:b; }
int max(int a, int b) { return (a>b)?a:b; }

char buf[32][32];
int r, c;

void solve()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++) scanf("%s", buf[i]);
	for (int z = 'A';z <= 'Z';z++)
	{
		int lor, hir, loc, hic;
		lor = loc = 1000;
		hir = hic = -1000;
		for (int i = 0;i < r;i++) for (int j = 0;j < c;j++) if (buf[i][j] == z)
		{
			lor = min(lor, i);
			loc = min(loc, j);
			hir = max(hir, i);
			hic = max(hic, j);
		}
		for (int i = lor;i <= hir;i++) for (int j = loc;j <= hic;j++) buf[i][j] = z;
	}
	while (1)
	{
		char done = 1;
		for (int z = 'A';z <= 'Z';z++)
		{
			int lor, hir, loc, hic;
			lor = loc = 1000;
			hir = hic = -1000;
			for (int i = 0;i < r;i++) for (int j = 0;j < c;j++) if (buf[i][j] == z)
			{
				lor = min(lor, i);
				loc = min(loc, j);
				hir = max(hir, i);
				hic = max(hic, j);
			}
			if (lor == 1000) continue;
			while (lor != 0)
			{
				char ok = 1;
				for (int j = loc;j <= hic;j++) if (buf[lor-1][j] != '?')
				{
					ok = 0;
					break;
				}
				if (ok)
				{
					for (int j = loc;j <= hic;j++) buf[lor-1][j] = z;
					lor--;
					done = 0;
				} else break;
			}
			while (lor != r-1)
			{
				char ok = 1;
				for (int j = loc;j <= hic;j++) if (buf[lor+1][j] != '?')
				{
					ok = 0;
					break;
				}
				if (ok)
				{
					for (int j = loc;j <= hic;j++) buf[lor+1][j] = z;
					lor++;
					done = 0;
				} else break;
			}
			while (loc != 0)
			{
				char ok = 1;
				for (int j = lor;j <= hir;j++) if (buf[j][loc-1] != '?')
				{
					ok = 0;
					break;
				}
				if (ok)
				{
					for (int j = lor;j <= hir;j++) buf[j][loc-1] = z;
					loc--;
					done = 0;
				} else break;
			}
			while (loc != c-1)
			{
				char ok = 1;
				for (int j = lor;j <= hir;j++) if (buf[j][loc+1] != '?')
				{
					ok = 0;
					break;
				}
				if (ok)
				{
					for (int j = lor;j <= hir;j++) buf[j][loc+1] = z;
					loc++;
					done = 0;
				} else break;
			}
		}
		if (done)
			break;
	}
	for (int i = 0;i < r;i++) printf("%s\n", buf[i]);
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);

		printf("Case #%d: \n", _);
		solve();

		fprintf(stderr, " done\n"); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
