#include<stdio.h>
#include<memory.h>
#include<string.h>
#define INF 999999
int n, m;
int a[128][128];
int path[128][128];
int dx[4]={-1, 0, 0, 1};
int dy[4]={0, -1, 1, 0};
int inv[4]={3, 2, 1, 0};
int ans[128][128], anscnt;
bool v[128][128];
void f1(int x, int y)
{
	v[x][y]=true; ans[x][y]=anscnt;
	int k, nx, ny;
	if(path[x][y]!=-1)
	{
		nx=x+dx[path[x][y]];
		ny=y+dy[path[x][y]];
		if(!v[nx][ny]) f1(nx, ny);
	}
	for(k=0;k<4;k++)
	{
		nx=x+dx[k]; ny=y+dy[k];
		if(nx<1 || ny<1 || nx>n || ny>m) continue;
		if(path[nx][ny]!=-1 && nx+dx[path[nx][ny]]==x && ny+dy[path[nx][ny]]==y && !v[nx][ny])
			f1(nx, ny);
	}
}
int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int t, tc;
	int i, j, k;
	int nx, ny;
	int mh, pt;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d%d", &n, &m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++) fscanf(fp, "%d", &a[i][j]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				mh=INF;
				path[i][j]=-1;
				for(k=0;k<4;k++)
				{
					nx=i+dx[k]; ny=j+dy[k];
					if(nx<1 || ny<1 || nx>n || ny>m) continue;
					if(mh>a[nx][ny]){mh=a[nx][ny]; pt=k;}
				}
				if(mh>=a[i][j]) continue;
				path[i][j]=pt;
			}
		}
		anscnt=0;
		memset(v, false, sizeof(v));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(v[i][j]) continue;
				anscnt++; f1(i, j);
			}
		}
		fprintf(ofp, "Case #%d:\n", t);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<m;j++)
			{
				fprintf(ofp, "%c ", ans[i][j]+'a'-1);
			}
			fprintf(ofp, "%c\n", ans[i][m]+'a'-1);
		}
	}
	return 0;
}
