#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
//#include<string>
//#include<sstream>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const int MAXN=2e5+5;
const double eps=1e-10;
int tot;
int head[MAXN];
int n,m;
struct Node
{
    int from,to,nxt;
}e[MAXN];
bool dd(int s,int t,int k);
void age(int u,int v);
int main()
{
    int d,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            age(u,v);
        }
        if(dd(1,n,0))
            printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
void age(int u,int v)
{
    e[tot].from=u;
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot++;
}
bool dd(int s,int t,int k)
{
    if(s==n&&k==2) return true;
    for(int i=head[s];i!=-1;i=e[i].nxt)
    {
        int to=e[i].to;
        if(dd(to,n,k+1)) return true;
    }
    return false;
}