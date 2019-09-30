#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	int *aa = (int *)a, *bb = (int *)b;

	if (*(aa+1) != *(bb+1))
		return *(aa+1) - *(bb+1);
	else
		return *aa - *bb;
}

int main()
{
	int cn, cc;

	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int i;
		int n;
		int lim[1000][2];
		int reach[1000];
		int sc;
		int step;

		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%d%d", lim[i], lim[i]+1);

		qsort(lim, n, sizeof(lim[0]), cmp);
		memset(reach, 0, sizeof(reach));

		sc = 0;
		step = 0;
		while (1)
		{
			int maxid = -1;
			for (i=0; i<n; i++)
			{
				if (reach[i] < 2 && lim[i][1] <= sc)
				{
					sc += 2 - reach[i];
					reach[i] = 2;
					step++;
				}
			}

			for (i=0; i<n; i++)
			{
				if (!reach[i] && lim[i][0] <= sc)
					maxid = i;
			}

			if (maxid < 0)
				break;

			reach[maxid] = 1;
			step++;
			sc++;
		}

		printf("Case #%d: ", cc);
		if (sc != 2*n)
			puts("Too Bad");
		else
			printf("%d\n", step);
	}

	return 0;
}