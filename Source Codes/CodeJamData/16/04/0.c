#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		printf("Case #%d:", iT+1);
		long long K, C, S;
		scanf("%lli %lli %lli",&K,&C,&S);
		long long R = (K + C - 1) / C;
		if (S < R) printf(" IMPOSSIBLE\n");
		else
		{
			for (long long i = 0; i < R; i++)
			{
				long long num = 0LL;
				for (long long j = 0; j < C; j++)
				{
					num = num * K + ((i * C + j) % K);
				}
				printf(" %lli", num+1);
			}
			printf("\n");
		}
	}
	return 0;
}
