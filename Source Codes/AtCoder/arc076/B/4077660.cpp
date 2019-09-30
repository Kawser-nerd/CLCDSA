/*
    _____
  .'|||||'.
 /  >   <  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
    |||||
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
struct part{
LL v;
int id;
};
struct part1{
int x,y;
LL v;
};
bool cmp(struct part a, struct part b)
{
    return(a.v<b.v);
}
int f[100010];
int find1(int x)
{
    if (f[x]==x) return(x); else f[x]=find1(f[x]);
    return(f[x]);
}
bool cmp1(struct part1 a, struct part1 b)
{
    return(a.v<b.v);
}
struct part x[100010],y[100010];
struct part1 a[200010];
int n;
int main()
{
scanf("%d",&n);
for (int i=1;i<=n;i++)
{
    LL xx,yy;
    scanf("%lld%lld",&xx,&yy);
    x[i].v=xx;
    x[i].id=i;
    y[i].v=yy;
    y[i].id=i;
}
sort(x+1,x+1+n,cmp);
sort(y+1,y+1+n,cmp);
int o=0;
for (int i=1;i<=n-1;i++)
{
    o++;
    a[o].x=x[i].id;
    a[o].y=x[i+1].id;
    a[o].v=x[i+1].v-x[i].v;
}
for (int i=1;i<=n-1;i++)
{
    o++;
    a[o].x=y[i].id;
    a[o].y=y[i+1].id;
    a[o].v=y[i+1].v-y[i].v;
}
sort(a+1,a+1+o,cmp1);
for (int i=1;i<=n;i++)
    f[i]=i;
int k=0;
LL ans=0;
for (int i=1;i<=o;i++)
{
    int fa=find1(a[i].x);
    int fb=find1(a[i].y);
    if (fa!=fb)
    {
        f[fa]=fb;
        ans+=a[i].v;
        k++;
    }
    if (k==n-1) break;
}
printf("%lld\n",ans);
    return(0);
}