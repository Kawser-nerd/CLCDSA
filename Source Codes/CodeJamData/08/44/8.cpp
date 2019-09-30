#include <vector>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>

FILE *Fin = fopen("D-large.in","r");
FILE *Fou = fopen("d.out","w");
//FILE *Fin = stdin;
//FILE *Fou = stdout;

int n,m,t;
char line[60000];
int cost[17][17][17];
int len, nb;

int opt[1<<16][16];
int mask[1<<16];

int main()
{
	int i,j,k,l,caseN;
	fscanf(Fin,"%d",&caseN);
	for (i=0; i<(1<<16); i++)
	{
		mask[i] = 0;
		for (j=0; j<16; j++)
			if (i&(1<<j)) mask[i]++;
	}
	for (int t=1; t<=caseN; t++)
	{
		fscanf(Fin,"%d\n",&n);
		fscanf(Fin,"%s",line);
		len = strlen(line);
		nb = len/n;

		for (i=0; i<n-1; i++)
		{
			for (j=0; j<n; j++)
				for (k=0; k<n; k++) if (j!=k)
				{
					cost[i][j][k] = 0;
					for (l=0; l<nb; l++)
						if (line[l*n+j] == line[l*n+k])
							cost[i][j][k] ++;
				}
		}
			for (j=0; j<n; j++)
				for (k=0; k<n; k++) if (j!=k)
				{
					cost[n-1][j][k] = 0;
					for (l=0; l<nb-1; l++)
						if (line[l*n+j] == line[(l+1)*n+k])
							cost[n-1][j][k] ++;
				}

		int ans = 0;
		for (k=0; k<n; k++) //start point
		{
			memset(opt,0x80,sizeof(opt));
			vector<pair<int, int> > bfs;
			bfs.push_back(make_pair(1<<k, k));
			opt[1<<k][k] = 0;
			for (int s=0; s<(1<<n); s++) if (s&(1<<k))
			{
				int state = mask[s];
				for (int p=0; p<n; p++) if (s&(1<<p))
				{
					for (j=0; j<n; j++) if ((s&(1<<j))==0)
					{
						int cc = cost[state-1][p][j];
						if (state==(n-1))
							cc += cost[state][j][k];
						if (opt[s][p] + cc > opt[s+(1<<j)][j] )
							opt[s+(1<<j)][j] = opt[s][p] + cc;
					}
				}
			}
			for (int p=0; p<n; p++)
				if (opt[(1<<n)-1][p]>ans)
					ans = opt[(1<<n)-1][p];
		}

		fprintf(Fou,"Case #%d: %d\n",t,len-ans);
	}
	return 0;
}

