#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 35
#define MAXK 

int main ()
{
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		printf("Case #%d: ",iT+1);
		int N, K;
		scanf("%d %d",&N,&K);
		K++;
		int MOD = 1 << N;
		if ((K % MOD) == 0) printf("ON\n");
		else printf("OFF\n");
	}
	return 0;
}
