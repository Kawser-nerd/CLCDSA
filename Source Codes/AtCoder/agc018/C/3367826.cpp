#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAXN 300006
using namespace std;
long long ans,ansl[MAXN],ansr[MAXN];
int X,Y,Z,n;
struct node
{
	long long x,y,z;
}a[MAXN];
priority_queue<long long> q;
bool cmp(node a,node b)
{
	return a.x-a.y>b.x-b.y;
}
int main()
{
	scanf("%d%d%d",&X,&Y,&Z);
	n=X+Y+Z;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=X+Z;i++)
	{
		q.push(a[i].z-a[i].x);
		ansl[i]=ansl[i-1]+a[i].x;
		if(i>X)
		{
			ansl[i]+=q.top();
			q.pop();
		}
	}
	while(!q.empty())
		q.pop();
	for(int i=X+Y+Z;i>X;i--)
	{
		q.push(a[i].z-a[i].y);
		ansr[i]=ansr[i+1]+a[i].y;
		if(i<=X+Z)
		{
			ansr[i]+=q.top();
			q.pop();
		}
	}
	for(int i=X;i<=X+Z;i++)
		ans=max(ans,ansl[i]+ansr[i+1]);
	printf("%lld",ans);
}