#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
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

#define INF 99999999

int n;
int D, I, M;
int p[128];
int d[128][512];
int ans;

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int i, j, k;
	int t, tc;
	int s, e;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d%d%d%d", &D, &I, &M, &n);
		for(i=1;i<=n;i++) fscanf(fp, "%d", &p[i]);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=255;j++) d[i][j]=INF;
		}
		for(j=0;j<=255;j++) d[0][j]=0;
		for(i=0;i<=n;i++)
		{
			priority_queue<pair<int, int> > q;
			for(j=0;j<=255;j++) q.push(make_pair(d[i][j], j));
			while(!q.empty())
			{
				pair<int, int> cur=q.top(); q.pop();
				if(cur.first!=d[i][cur.second]) continue;
				j=cur.second;
				s=max(0, j-M); e=min(255, j+M);
				if(abs(j-p[i+1])<=M && d[i+1][p[i+1]]>d[i][j])
					d[i+1][p[i+1]]=d[i][j];
				for(k=s;k<=e;k++)
				{
					if(d[i][k]>d[i][j]+I)
					{
						d[i][k]=d[i][j]+I;
						q.push(make_pair(d[i][k], k));
					}
					if(d[i+1][k]>d[i][j]+abs(k-p[i+1]))
						d[i+1][k]=d[i][j]+abs(k-p[i+1]);
					if(d[i+1][k]>d[i][j]+D+I)
						d[i+1][k]=d[i][j]+D+I;
					if(d[i+1][j]>d[i][j]+D)
						d[i+1][j]=d[i][j]+D;
				}
			}
		}
		ans=D*n;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=255;j++)
			{
				if(d[i][j]==INF) continue;
				if(ans>d[i][j]+D*(n-i))
					ans=d[i][j]+D*(n-i);
			}
		}
		fprintf(ofp, "Case #%d: %d\n", t, ans);
	}
	
	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
