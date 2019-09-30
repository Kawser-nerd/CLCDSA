#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int cc,ca;
	cin >> ca;
	int N,M;
	int i,j,k;

	int ff[200][200][2];

	for(cc=1; cc<=ca; cc++)
	{
		memset(ff, 0, sizeof(ff));
		cin >> N >> M;
		for(i=0; i<M; i++)
		{
			int T;
			cin >> T;
			for(j=0; j<T; j++)
			{
				int a,b;
				cin >> a >> b;
				ff[i][a-1][b] = 1;
			}
		}
		int r;
		int best, bestc;
		bestc = 1000000;
		for(r=0; r<(1<<10); r++)
		{
			int f[200];
			memset(f, 0, sizeof(f));
			int bc = 0;
			for(i=0; i<N; i++)
			{
				int temp = 0;
				if (r&(1<<i))
				{
					bc++;
					temp = 1;
				}
				for(j=0; j<M; j++)
					if (ff[j][i][temp])
						f[j] = 1;
			}
			for(j=0; j<M; j++)
				if (f[j] == 0)
					break;
			if (j < M) continue;
			if (bc < bestc)
			{
				bestc = bc;
				best = r;	
			}
		}
		if (bestc == 1000000)
		{
			printf("Case #%d: IMPOSSIBLE\n", cc);
			continue;
		}
		printf("Case #%d:", cc);
		for(i=0; i<N; i++)
		{
			if (best&(1<<i))
				printf(" 1");
			else
				printf(" 0");
		}
		printf("\n");
	}
}
