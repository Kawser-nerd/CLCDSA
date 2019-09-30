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

int n, m;
char a[64][64];
char b[64][64];
int dx[4]={0, 1, 1, 1};
int dy[4]={1, 1, 0, -1};

bool in(int x, int y)
{
	return 1<=x && 1<=y && x<=n && y<=n;
}

bool f_test(int sx, int sy, int dir, char x)
{
	int i;
	int nx, ny;
	for(i=0;i<m;i++)
	{
		nx=sx+dx[dir]*i;
		ny=sy+dy[dir]*i;
		if(!in(nx, ny)) return false;
		if(b[nx][ny]!=x) return false;
	}
	return true;
}

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
		fscanf(fp, "%d%d", &n, &m);
		for(i=1;i<=n;i++) fscanf(fp, "%s", &a[i][1]);
		memset(b, 0, sizeof(b));
		for(j=1;j<=n;j++)
		{
			i=n;
			for(k=n;k>=1;k--)
			{
				for(;i>=1 && a[n+1-j][i]=='.';i--);
				if(i>=1) b[k][j]=a[n+1-j][i--];
				else b[k][j]='.';
			}
		}
		bool red=false, blue=false;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=0;k<4;k++)
				{
					if(f_test(i, j, k, 'R')) red=true;
					if(f_test(i, j, k, 'B')) blue=true;
				}
			}
		}
		fprintf(ofp, "Case #%d: ", t);
		if(red && blue) fprintf(ofp, "Both\n");
		else if(red) fprintf(ofp, "Red\n");
		else if(blue) fprintf(ofp, "Blue\n");
		else fprintf(ofp, "Neither\n");
	}
	
	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
