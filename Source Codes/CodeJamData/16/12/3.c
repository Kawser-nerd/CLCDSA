#include <stdio.h>

int comp(int *a, int *b)
{
	return *a - *b;
}

int main()
{
	int T;
	scanf("%d", &T);
	int test;
	for(test = 1; test <= T; test++)
	{
		int N;
		scanf("%d", &N);
		int heightmap[3000];
		int i, j;
		for(i = 0; i < 3000; i++)
			heightmap[i] = 0;
		for(i = 0; i < 2 * N - 1; i++)
		{
			for(j = 0; j < N; j++)
			{
				int x;
				scanf("%d", &x);
				heightmap[x]++;
			}
		}
		int out[N];
		int outpos = 0;
		for(i = 0; i < 3000; i++)
			if(heightmap[i] & 1)
				out[outpos++] = i;
		qsort(out, N, sizeof(int), comp);
		printf("Case #%d: ", test);
		for(i = 0; i < N; i++)
			printf("%d ", out[i]);
		printf("\n");
	}
}
