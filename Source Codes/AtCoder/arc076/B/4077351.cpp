#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int maxn=1e5+5;
int fa[maxn];
int tot;
struct way{
    int u,v;
	long long w;
}edge[maxn*4];
struct node
{
	int x,y,id;
}a[maxn];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
void link(int x,int y)
{
    int tx=find(x),ty=find(y);
    fa[ty]=tx;
}
bool cmp(way a,way b){return a.w<b.w;}
bool cmp1(node a,node b){return a.x<b.x;}
bool cmp2(node a,node b){return a.y<b.y;}
int main()
{
    int m,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	a[i].id=i;
    	scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n,cmp1);
	int cnt=0;
    for(int i=1;i<n;i++)
    {
    	cnt++;
    	edge[cnt].u=a[i].id;
    	edge[cnt].v=a[i+1].id;
    	edge[cnt].w=(long long)(a[i+1].x-a[i].x);
    	cnt++;
    	edge[cnt].u=a[i+1].id;
    	edge[cnt].v=a[i].id;
    	edge[cnt].w=(long long)(a[i+1].x-a[i].x);
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<n;i++)
    {
    	cnt++;
    	edge[cnt].u=a[i].id;
    	edge[cnt].v=a[i+1].id;
    	edge[cnt].w=(long long)(a[i+1].y-a[i].y);
    	cnt++;
    	edge[cnt].u=a[i+1].id;
    	edge[cnt].v=a[i].id;
    	edge[cnt].w=(long long)(a[i+1].y-a[i].y);
	}
    for(int i=1;i<=n;i++)    fa[i]=i;
    sort(edge+1,edge+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(find(edge[i].u)!=find(edge[i].v))
        {
            link(edge[i].u,edge[i].v);
            tot=tot+edge[i].w; 
        }
    }
    cout<<tot<<endl;
    return 0;
}