#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105

struct node
{
	int p, q;
};

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char data[MAXN][MAXN];
	static struct node wp[MAXN];
	static double WP[MAXN];
	static double OWP[MAXN];
	static double OOWP[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		scanf("%d\n",&N);
		int i, j, k;
		for (i = 0; i < N; i++) scanf("%s\n",data[i]);
		for (i = 0; i < N; i++)
		{
			memset(wp,0,sizeof(wp));
			for (j = 0; j < N; j++)
			{
				for (k = 0; k < N; k++)
				{
					if ((k != i) && (data[j][k] != '.'))
					{
						wp[j].q++;
						if (data[j][k] == '1') wp[j].p++;
					}
				}
			}
			WP[i] = (double)(wp[i].p) / (double)(wp[i].q);
			OWP[i] = 0.0;
			int cnt = 0;
			for (j = 0; j < N; j++)
			{
				if (data[i][j] != '.')
				{
					OWP[i] += (double)(wp[j].p) / (double)(wp[j].q);
					cnt++;
				}
			}
			OWP[i] /= (double)(cnt);
		}
		for (i = 0; i < N; i++)
		{
			OOWP[i] = 0.0;
			int cnt = 0;
			for (j = 0; j < N; j++)
			{
				if (data[i][j] != '.')
				{
					OOWP[i] += OWP[j];
					cnt++;
				}
			}
			OOWP[i] /= (double)(cnt);
		}
		printf("Case #%d:\n",iT+1);
		for (i = 0; i < N; i++) printf("%.10lf\n",0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i]);
	}
	return 0;
}
