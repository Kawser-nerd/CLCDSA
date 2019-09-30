// Problem B. Rank and File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; i ++)
	{
		int j, k, N, piece[60] = {0}, h[2511] = {0}, ans[60] = {0};
		scanf("%d", &N);
		for (j = 0; j < N * 2 - 1; j ++)
		{
			for (k = 0; k < N; k ++)
			{
				scanf("%d", &piece[N]);
				h[piece[N]] ++;
			}
		}
		for (j = 0, k = 0; j < 2511; j ++)
		{
			if (h[j] % 2)
				ans[k ++] = j;
		}
		printf("Case #%d:", i + 1);
		for (j = 0; j < N; j ++)
			printf(" %d", ans[j]);
		printf("\n");
	}
	return 0;
}