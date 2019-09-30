#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1000005

int main ()
{
	static char b[MAXN];
	memset(b,1,sizeof(b));
	int i, j;
	b[0] = 0;
	b[1] = 0;
	for (i = 2; (i*i) <= 1000000; i++)
	{
		if (b[i])
		{
			for (j = 2*i; j <= 1000000; j += i) b[j] = 0;
		}
	}
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		long long int N;
		scanf("%I64i",&N);
		if (N == 1LL)
		{
			printf("Case #%d: 0\n",iT+1);
			continue;
		}
		long long int max = 1LL;
		long long int min = 0LL;
		long long int num;
		for (i = 1; ((long long int)(i) * (long long int)(i)) <= N; i++)
		{
			if (b[i])
			{
				min++;
				num = (long long int)(i);
				int cnt = 1;
				while ((num * (long long int)(i)) <= N)
				{
					num *= (long long int)(i);
					cnt++;
				}
				max += (long long int)(cnt);
			}
		}
		printf("Case #%d: %I64i\n",iT+1,max-min);
	}
	return 0;
}
