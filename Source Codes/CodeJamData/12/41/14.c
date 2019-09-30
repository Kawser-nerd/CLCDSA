#include <stdio.h>
#include <string.h>

#define MAX 10000

int pos[MAX];
int len[MAX];
int ulen[MAX];
int dpos;

int main()
{
	int cn, cc;

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int n;
		int i;

		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%d%d", pos+i, len+i);
		scanf("%d", &dpos);

		printf("Case #%d: ", cc);

		memset(ulen, 0, sizeof(ulen));
		ulen[0] = pos[0];

		if (pos[0] + ulen[0] >= dpos)
			goto YES;

		for (i=0; i<n; i++)
		{
			int tp;
			int tul;
			for (tp = i+1; tp<n; tp++)
			{
				if (pos[tp] > pos[i] + ulen[i])
					break;

				tul = (pos[tp] - pos[i] < len[tp]) ? pos[tp] - pos[i] : len[tp];
				if (tul > ulen[tp])
				{
					ulen[tp] = tul;
					if (pos[tp] + tul >= dpos)
						goto YES;
				}
			}
		}

		puts("NO");
		continue;

YES:
		puts("YES");
		continue;
	}

	return 0;
}