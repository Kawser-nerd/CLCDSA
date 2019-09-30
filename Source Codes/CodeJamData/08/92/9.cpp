#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,ans,x1,y1,x2,y2;
bool u[128][128];
bool tt(int x,int y)
{
	u[x][y]=true;
	ans++;
	int xx,yy;
	xx=x+x1;
	yy=y+y1;
	if(xx>=0&&xx<n&&yy>=0&&yy<m)
		if(!u[xx][yy])
			tt(xx,yy);
	xx=x+x2;
	yy=y+y2;
	if(xx>=0&&xx<n&&yy>=0&&yy<m)
		if(!u[xx][yy])
			tt(xx,yy);
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int cc,o;
	int x,y;
	scanf("%d",&cc);
	for(o=1;o<=cc;o++)
	{
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		scanf("%d%d",&x,&y);
		memset(u,0,sizeof(u));
		ans=0;
		tt(x,y);
		printf("Case #%d: %d\n",o,ans);
	}
	return 0;
}
		
	
