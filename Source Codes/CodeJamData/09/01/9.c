#include <stdio.h>
#include <stdlib.h>

char dict[5000][16];
char good[15][26];

int main()
{
	int L, D, N, t, i;

	scanf("%d %d %d ", &L, &D, &N);
	for (i=0; i<D; i++)
		scanf("%s", dict[i]);

	for (t=1; t<=N; t++)
	{
		int cnt;
		char patt[15*28+1];
		int i, j;
		char *p;
	
		scanf("%s", patt);

		memset(good, 0, sizeof(good));
		j = 0;
		for (p = patt; *p; p++)
		{
			if (*p != '(')
				good[j][*p - 'a'] = 1;
			else
			{
				for (p++; *p != ')'; p++)
					good[j][*p - 'a'] = 1;
			}
			j++;
		}

		cnt = 0;
		for (i=0; i<D; i++)
		{
			for (j=0; j<L; j++)
				if (!good[j][dict[i][j] - 'a'])
					break;
			if (j >= L)
				cnt++;
		}
		printf("Case #%d: %d\n", t, cnt);
	}
	return 0;
}
