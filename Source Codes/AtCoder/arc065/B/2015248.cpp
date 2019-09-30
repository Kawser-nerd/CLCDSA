#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=5e5+1212;

int n,m1,m2;
int edgenum;
bool vis[maxn];
int head[maxn],Next[maxn],b[maxn],V[maxn];
int num[maxn];
vector <int> human[maxn],vv;
bool book[maxn];
void add(int u,int v)
{
    V[++edgenum]=v;
    Next[edgenum]=head[u];
    head[u]=edgenum;
}

void DFS(int u)
{
    vis[u]=true;
    int pos=b[u];
    if(book[pos]==false) vv.push_back(pos);
    human[pos].push_back(u);
    for(int i=head[u];i!=-1;i=Next[i])
    {
        int v=V[i];
        if(vis[v]==false) DFS(v);
    }
}

int f(int x)
{
    if(b[x]==x) return x;
    else return b[x]=f(b[x]);
}
int main()
{
    int u,v;
    while(scanf("%d %d %d",&n,&m1,&m2)!=EOF)
    {
        for(int i=1;i<=n;i++) b[i]=i;
        for(int i=1;i<=m1;i++)
        {
            scanf("%d %d",&u,&v);
            int t1=f(u),t2=f(v);
            b[t2]=t1;
        }
        for(int i=1;i<=n;i++) b[i]=f(i);
        memset(vis,false,sizeof(vis));
        memset(head,-1,sizeof(head));
        memset(book,false,sizeof(book));
        memset(num,0,sizeof(num));
        edgenum=0;
        for(int i=1;i<=m2;i++)
        {
            scanf("%d %d",&u,&v);
            add(u,v);
            add(v,u);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                DFS(i);
                for(int j=0;j<(int)vv.size();j++)
                {
                    int pos=vv[j];
                    for(int s=0;s<(int)human[pos].size();s++)
                    {
                        int q=human[pos][s];
                        num[q]+=human[pos].size();
                    }
                    human[pos].clear();
                }
                vv.clear();
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i==n) printf("%d\n",num[i]);
            else printf("%d ",num[i]);
        }
    }
    return 0;
}