#include<stdio.h>

int main()
{
	freopen("gcj2.in", "r", stdin);
	freopen("gcj2.out", "w", stdout);
	int ca, count;
	char coma, comb, comc, oppa, oppb;
	scanf("%d", &ca);
	for (count = 1; count <= ca; count++)
	{
		char com[26][26] =
		{ 0 };
		int opp[26][26] =
		{ 0 };
		int n, m, k;
		int i;
		char ch;
		char ans[110];
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf(" %c%c%c", &coma, &comb, &comc);
			com[coma - 'A'][comb - 'A'] = comc;
			com[comb - 'A'][coma - 'A'] = comc;
		}
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			scanf(" %c%c", &oppa, &oppb);
			opp[oppa - 'A'][oppb - 'A'] = 1;
			opp[oppb - 'A'][oppa - 'A'] = 1;
		}
		scanf("%d ", &n);
		int p = 0;
		while (n--)
		{
			scanf("%c", &ch);
			if (p > 0)
			{
				int flag=0;
				if (com[ans[p - 1] - 'A'][ch - 'A'])
				{
					flag=1;
					ans[p - 1] = com[ans[p - 1] - 'A'][ch - 'A'];
				}
				else
				{
					for (i = 0; i < p; i++)
						if (opp[ans[i] - 'A'][ch - 'A'])
						{
							p = 0;
							flag=1;
							break;
						}
				}
				if (!flag)
					ans[p++] = ch;
			}
			else
				ans[p++] = ch;
		}
		printf("Case #%d: [", count);
		if (p>0) printf("%c",ans[0]);
		for (i = 1; i < p; i++)
			printf(", %c", ans[i]);
		printf("]\n");
	}
	return 0;
}
