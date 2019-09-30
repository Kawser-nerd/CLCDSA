#include<stdio.h>
#include<string.h>
int i,j,h,w,n,a[100][100],wa[100][100],mark[10001],ti,s;
int calc(int x,int y)
{
	int xt=x,yt=y;
	if (wa[x][y]!=-1) return wa[x][y];
	if (x&&a[x-1][y]<a[xt][yt])
	{
		xt=x-1;
		yt=y;
	}
	if (y&&a[x][y-1]<a[xt][yt])
	{
		xt=x;
		yt=y-1;
	}
	if (y+1<w&&a[x][y+1]<a[xt][yt])
	{
		xt=x;
		yt=y+1;
	}
	if (x+1<h&&a[x+1][y]<a[xt][yt])
	{
		xt=x+1;
		yt=y;
	}
	if (xt!=x||yt!=y) wa[x][y]=calc(xt,yt);
	else wa[x][y]=s++;
	return wa[x][y];
}
int main()
{
	scanf("%d",&n);
	for (ti=1;ti<=n;ti++)
	{
		scanf("%d%d",&h,&w);
		for (i=0;i<h;i++)
			for (j=0;j<w;j++)
				scanf("%d",&a[i][j]);
		memset(wa,-1,sizeof(wa));
		s=0;
		for (i=0;i<h;i++)
			for (j=0;j<w;j++)
				if (wa[i][j]==-1)
					calc(i,j);
		printf("Case #%d:\n",ti);
		memset(mark,-1,sizeof(mark));
		s=0;
		for (i=0;i<h;i++)
			for (j=0;j<w;j++)
			{
				if (mark[wa[i][j]]==-1) mark[wa[i][j]]=s++;
				printf("%c",'a'+mark[wa[i][j]]);
				if (j==w-1) printf("\n");
				else printf(" ");
			}
	}
	return 0;
}
