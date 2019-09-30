#include <stdio.h>
#include <string.h>

int n;
int stat[512][10];
int l[9], r[9];

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d", &n);
		for (int i = 0;i  < n - 1; i ++)
		{
			scanf ("%d%d", l + i, r + i);
			l[i] --;
			r[i] --;
		}
		memset(stat,0,sizeof(stat));
		int cur = 0;
		int pos = 0;
		int steps = 0;

		while (!stat[cur][pos])
		{
			stat[cur][pos] = 1;
			cur ^= (1 << pos);
			if ((1 << pos) & cur)
			{
				// Go left
				pos = l[pos];
			}
			else
			{
				pos = r[pos];
			}
			steps ++;
			if (pos == n - 1)
				break;
		}

		if (pos == n - 1)
			printf ("Case #%d: %d\n", ++ct, steps);
		else
			printf ("Case #%d: Infinity\n", ++ct);
	}

	return 0;
}