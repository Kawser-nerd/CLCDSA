#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int h,w,d[1000][1000],k,x,y,ans=1<<30,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
queue<pair<int,int> > q;
char s[1000][1000];
int main()
{
	scanf("%d%d%d",&h,&w,&k);
	memset(d,-1,sizeof d);
	for(int i=0;i<h;i++)
	{
		scanf("%s",s[i]);
		for(int j=0;j<w;j++)
			if(s[i][j]=='S')x=i,y=j;
	}
	q.push(make_pair(x,y));
	d[x][y]=k;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop();
		ans=min(ans,min(min(x,y),min(h-x-1,w-y-1)));
		if(!x||!y||x==h-1||y==w-1)ans=0;
		else for(int r=0;r<4;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			if(s[tx][ty]!='#'&&d[tx][ty]<d[x][y]-1)
			{
				d[tx][ty]=d[x][y]-1;
				q.push(make_pair(tx,ty));
			}
		}
	}
	printf("%d\n",(ans+k-1)/k+1);
	return 0;
}