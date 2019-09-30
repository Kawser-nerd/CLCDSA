#include <stdio.h>

int gseen[1001];

int longest(int N, int *fw, int at)
{
	//printf("dfs(%d) = ...\n", at + 1);
	if(gseen[at])
		return -1;
	gseen[at] = 1;
	int max = -1;
	int i;
	for(i = 0; i < N; i++)
		if(fw[i] == at)
		{
			int r = longest(N, fw, i);
			if(r > max)
				max = r;
		}
	gseen[at] = 0;
	//printf("... = %d\n",max == -1 ? -1 : max + 1);
	return max == -1 ? 1 : max + 1;
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
		int bff[N];
		int i, p, q;
		for(i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			bff[i] = x - 1;
		}
		int max = -1;
		int start;
		for(start = 0; start < N; start++)
		{
			int seen[N];
			for(i = 0; i < N; i++)
				seen[i] = 0;
			int cur = start;
			int count = 0;
			while(!seen[cur])
			{
				count++;
				seen[cur] = 1;
				cur = bff[cur];
				if(cur == start)
				{
					//printf("loop at %d\n", count);
					if(count > max)
						max = count;
					break;
				}
			}
		}
		int sum = 0;
		for(p = 0; p < N; p++)
			for(q = 0; q < p; q++)
				if(bff[p] == q && bff[q] == p)
				{
					//printf("pair (%d, %d)\n", p + 1, q + 1);
					gseen[p] = 1;
					int r1 = longest(N, bff, q);
					gseen[p] = 0;
					gseen[q] = 1;
					int r2 = longest(N, bff, p);
					gseen[q] = 0;
					//printf("branches %d %d\n", r1, r2);
					sum += r1 + r2;
				}
		//printf("piece sum %d\n", sum);
		if(sum > max)
			max = sum;
		printf("Case #%d: %d\n", test, max);
	}
}
