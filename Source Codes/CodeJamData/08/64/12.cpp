#include<stdio.h>
#include<vector>
using namespace std;
vector<int> my[105],you[105],our[105][105];
int r[105];
bool u[105];
int his;
bool get(int x)
{
	u[x]=true;
	int i,y;
	for(i=0;i<our[his][x].size();i++)
	{
		y=our[his][x][i];
		if(r[y]==-1||!u[r[y]]&&get(r[y]))
		{
			r[y]=x;
			return true;
		}
	}
	return false;
}
bool tt(int x,int fx,int y,int fy)
{
	int i,j,lx[105],ly[105],gx,gy;
	gx=gy=0;
	for(j=0;j<you[y].size();j++)
		if(you[y][j]!=fy)
			ly[gy++]=you[y][j];
	for(i=0;i<my[x].size();i++)
		if(my[x][i]!=fx)
			lx[gx++]=my[x][i];
	if(!gx&&!gy)
		return true;
	if(gx<gy)
		return false;
	for(j=0;j<gy;j++)
	{
		our[y][j].clear();
		for(i=0;i<gx;i++)
			if(tt(lx[i],x,ly[j],y))
				our[y][j].push_back(i);
	}
	his=y;
	memset(r,0XFF,sizeof(r));
	for(j=0;j<gy;j++)
	{
		memset(u,0,sizeof(u));
		if(!get(j))
			break;
	}
	if(j<gy)
		return false;
	return true;
}
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int c,o,i,p,q,n,m;
	scanf("%d",&c);
	for(o=1;o<=c;o++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			my[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&p,&q);
			p--;
			q--;
			my[p].push_back(q);
			my[q].push_back(p);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
			you[i].clear();
		for(i=0;i<m-1;i++)
		{
			scanf("%d%d",&p,&q);
			p--;
			q--;
			you[p].push_back(q);
			you[q].push_back(p);
		}
		for(i=0;i<n;i++)
		{
			if(tt(i,-1,0,-1))
				break;
		}
		if(i<n)
			printf("Case #%d: YES\n",o);
		else
			printf("Case #%d: NO\n",o);
	}
	return 0;
}
