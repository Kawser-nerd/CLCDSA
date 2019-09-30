#include <stdio.h>
#include <stdlib.h>

#define N 110

int main()
{
	int cas, c, team, i, j, tmp, wl[N][2];
	double wp[N], owp[N], oowp[N];
	char adj[N][N];
	scanf("%d", &cas);
	for(c=1; c<=cas; c++)
	{
		scanf("%d", &team);
		for(i=0; i<team; i++)
			scanf("%s", adj[i]);
		for(i=0; i<team; i++)
		{
			wp[i] = 0;
			wl[i][0] = 0;
			wl[i][1] = 0;
			for(j=0; j<team; j++)
			{
				if(adj[i][j] == '1')
				{
					wl[i][0]++;
					wp[i] += 1;
				}
				if(adj[i][j] == '0')
					wl[i][1]++;
			}
			wp[i] = (double)wp[i]/(wl[i][0]+wl[i][1]);
		}
		for(i=0; i<team; i++)
		{
			owp[i] = 0;
			for(j=0; j<team; j++)
			{
				if(adj[i][j] == '1')
					owp[i] += (double)(wl[j][0])/(wl[j][0] + wl[j][1] - 1);
				if(adj[i][j] == '0')
					owp[i] += (double)(wl[j][0]-1)/(wl[j][0] + wl[j][1] - 1);
			}
			owp[i] = owp[i]/(wl[i][0]+wl[i][1]);
		}

		for(i=0; i<team; i++)
		{
			oowp[i] = 0;
			tmp = 0;
			for(j=0; j<team; j++)
			{
				if(adj[i][j] == '1' || adj[i][j] == '0')
				{
					tmp++;
					oowp[i] += owp[j];
				}
				/*if(adj[i][j] == '0')
					tmp++;*/
			}
			oowp[i] = oowp[i]/tmp;
		}
		printf("Case #%d:\n", c);
		for(i=0; i<team; i++)
			printf("%.6lf\n", 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);
			//printf("%lf\n", owp[i]);

	}
	return 0;
}
