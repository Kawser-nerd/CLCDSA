#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define INF 999999999

int n;
int a[128][128];
int ver[128], hor[128];

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int i, j, k, l;
	int t, tc;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d", &n);
		memset(a, 0, sizeof(a));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++){fscanf(fp, "%d", &a[i][n-i+j*2-1]); a[i][n-i+j*2-1]++;}
		}
		for(;i<2*n;i++)
		{
			for(j=1;j<=2*n-i;j++){fscanf(fp, "%d", &a[i][(i-n)+j*2-1]); a[i][(i-n)+j*2-1]++;}
		}
		ver[0]=hor[0]=0;
		for(k=0;k<=2*n;k++)
		{
			for(i=1;k-i>=1 && k+i<2*n;i++)
			{
				for(j=1;j<2*n;j++)
				{
					if(a[k-i][j]>0 && a[k+i][j]>0 && a[k-i][j]!=a[k+i][j])
						break;
				}
				if(j<2*n) break;
			}
			if(k-i==0 || k+i==2*n)
				ver[++ver[0]]=k;
			for(i=1;k-i>=1 && k+i<2*n;i++)
			{
				for(j=1;j<2*n;j++)
				{
					if(a[j][k-i]>0 && a[j][k+i]>0 && a[j][k-i]!=a[j][k+i])
						break;
				}
				if(j<2*n) break;
			}
			if(k-i==0 || k+i==2*n)
				hor[++hor[0]]=k;
		}
		int ans=INF;
		for(i=1;i<=ver[0];i++)
		{
			for(j=1;j<=hor[0];j++)
			{
				int x=ver[i], y=hor[j];
				int mlen=0;
				for(k=1;k<2*n;k++)
				{
					for(l=1;l<2*n;l++)
					{
						if(a[k][l]) mlen=max(mlen, abs(k-x)+abs(l-y));
					}
				}
				if(ans>mlen+1) ans=mlen+1;
			}
		}
		fprintf(ofp, "Case #%d: %d\n", t, ans*ans-n*n);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
