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

int n;
char a[128][128];
double wp[128];
double owp[128];
double oowp[128];

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
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d", &n);
		for(i=1;i<=n;i++) fscanf(fp, "%s", &a[i][1]);
		for(i=1;i<=n;i++)
		{
			double t1=0, t2=0;
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(a[i][j]!='.') t2++;
				if(a[i][j]=='1') t1++;
			}
			wp[i]=t1/t2;
			owp[i]=0.0;
			int cnt=0;
			for(j=1;j<=n;j++)
			{
				if(i==j || a[i][j]=='.') continue;
				cnt++;
				t1=0.0; t2=0.0;
				for(k=1;k<=n;k++)
				{
					if(k==i || k==j) continue;
					if(a[j][k]!='.') t2++;
					if(a[j][k]=='1') t1++;
				}
				owp[i]+=(t1/t2);
			}
			owp[i]/=(double)(cnt);
		}
		for(i=1;i<=n;i++)
		{
			oowp[i]=0.0;
			int cnt=0;
			for(j=1;j<=n;j++)
			{
				if(i==j || a[i][j]=='.') continue;
				cnt++;
				oowp[i]+=owp[j];
			}
			oowp[i]/=(double)(cnt);
		}
		fprintf(ofp, "Case #%d:\n", t);
		for(i=1;i<=n;i++) fprintf(ofp, "%.12lf\n", 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "cat ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
