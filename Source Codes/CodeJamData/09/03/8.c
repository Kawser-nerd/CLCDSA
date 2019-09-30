#include <stdio.h>
#include <string.h>

char phrase[] = "welcome to code jam";
char buf[501];
int a[501][20];

int main()
{
	int N, t;

	scanf("%d ", &N);
	for (t=1; t<=N; t++)
	{
		int l, i, j;

		gets(buf);
		l = strlen(buf);

		for (i=0; i<19; i++)
			a[l][i] = 0;
		for (i=0; i<=l; i++)
			a[i][19] = 1;

		for (i=l-1; i>=0; i--)
			for (j=18; j>=0; j--)
			{
				a[i][j] = a[i+1][j];
				if (phrase[j] == buf[i])
					a[i][j] = (a[i][j] + a[i+1][j+1]) % 10000;
			}
		printf("Case #%d: %04d\n", t, a[0][0]);
	}
	return 0;
}
