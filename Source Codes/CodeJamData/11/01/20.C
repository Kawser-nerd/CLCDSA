#include <iostream>
using namespace std;

int stepO[105], stepB[105];

struct ss
{
	char c;
	int pos;
}seq[105];

int main()
{
	int icase, ncase;
	int i, n;
	int button;
	int pa, pb;
	int res;
	char c;
	int sa, sb, ta, tb, ph;
	char now;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &n);
		getchar();
		sa = sb = 0;

		for(i = 0;i < n;i++)
		{
			c = getchar();
			scanf("%d", &button);
			seq[i].c = c;
			seq[i].pos = button;
			if (c == 'O')
				stepO[sa++] = button;
			else
				stepB[sb++] = button;
			getchar();
		}

		pa = 1;pb = 1;
		ta = 0;tb = 0;
		ph = 0;
		res = 0;
		while(ph < n)
		{
			res++;
			now = seq[ph].c;

			if (ta < sa)
			{
				if (pa < stepO[ta])
					pa++;
				else if (pa > stepO[ta])
					pa--;
				else if (pa == stepO[ta] && now == 'O')
				{
					ta++;
					ph++;
				}
			}

			if (tb < sb)
			{
				if (pb < stepB[tb])
					pb++;
				else if (pb > stepB[tb])
					pb--;
				else if (pb == stepB[tb] && now == 'B')
				{
					tb++;
					ph++;
				}
			}
		}
		printf("Case #%d: %d\n", icase, res);
	}

}
