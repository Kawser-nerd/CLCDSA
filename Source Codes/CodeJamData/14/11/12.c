#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T;
	int N;
	int L;

	char Device[150][41];
	char Outlet[150][41];
	char switchedOutlet[150][41];
	int switchedIdx[41];
	int switchedCnt = 0;
	int usedIdx[150];

	int testCase, i,j,k;

	scanf("%d", &T);

	for(testCase = 0; testCase < T; testCase++)
	{
		int minimumCnt = 9999;
		scanf("%d %d", &N, &L);

		for(i = 0; i < N; i++)
			scanf("%s", Outlet[i]);
		for(i = 0; i < N; i++)
			scanf("%s", Device[i]);

		for(i = 0; i <N; i++)
		{
			memset(switchedIdx, 0, sizeof(switchedIdx));
			memset(usedIdx, 0, sizeof(usedIdx));
			switchedCnt = 0;
			// check Device and Outlet

			for(j = 0; j < L; j++)
			{
				if(Device[0][j] != Outlet[i][j])
				{
					switchedIdx[j] = 1;
					switchedCnt++;
				}
				else
					switchedIdx[j] = 0;
			}
			if( minimumCnt <= switchedCnt )
				continue;

			usedIdx[i] = 1;

			for(j = 0; j < N; j ++)
			{
				for(k = 0; k < L; k++)
				{
					if( switchedIdx[k])
					{
						switchedOutlet[j][k] = (Outlet[j][k]=='0'?'1':'0');
					}
					else
						switchedOutlet[j][k] = Outlet[j][k];
				}
				switchedOutlet[j][k] = '\0';
			}

			for(j = 1; j < N; j++)
			{
				for(k = 0; k < N; k++)
				{
					if( usedIdx[k] == 1)
						continue;
					if(strcmp(Device[j], switchedOutlet[k]) == 0)
						usedIdx[k] = 1;
				}
			}

			for(j = 0; j < N; j++)
				if( usedIdx[j] != 1)
					break;
			// find solution
			if( j == N )
				minimumCnt = switchedCnt;
		}

		printf("Case #%d: ", testCase + 1);
		if( minimumCnt <= L )
			printf("%d\n", minimumCnt);
		else
			printf("NOT POSSIBLE\n");
	}
	return 0;
}