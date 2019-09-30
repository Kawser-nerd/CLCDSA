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
using namespace std;
typedef long long LL;
const LL INF=1e18;
const int MAXN=2e5+100;
const double eps=1e-10;
bool vis[MAXN];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int u,v;
        bool flag=false;
        for(int i=1;i<=n;i++)
            vis[i]=false;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            if(flag) continue;
            if(u==1)
            {
                if(vis[v])
                {
                    flag=true;
                }
                vis[v]=true;
            }else if(v==n)
            {
                if(vis[u])
                {
                    flag=true;
                }
                vis[u]=true;
            }
        }
        if(flag) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
	return 0;
}