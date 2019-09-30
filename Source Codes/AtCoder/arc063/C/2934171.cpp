#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int INF=1<<30;
vector<int>edge[N];
int deep[N];
void nosolution(){
    puts("No");
    exit(0);
}
void dfs1(int u,int fa,int d){
    deep[u]=d;
    for(int i=0,sz=edge[u].size();i<sz;i++){
        int v=edge[u][i];
        if(v==fa)
            continue;
        dfs1(v,u,d+1);
    }
}
int val[N],mn[N],mx[N];
void dfs2(int u,int fa){
    if(val[u]==-1)
        mn[u]=-INF,mx[u]=INF;
    else
        mn[u]=mx[u]=val[u];
    for(int i=0,sz=edge[u].size();i<sz;i++){
        int v=edge[u][i];
        if(v==fa)
            continue;
        dfs2(v,u);
        if(mx[v]<mn[u]-1||mn[v]>mx[u]+1)
            nosolution();
        mn[u]=max(mn[u],mn[v]-1);
        mx[u]=min(mx[u],mx[v]+1);
    }
}
int ans[N];
void dfs3(int u,int fa,int t){
    if(t+1<=mx[u])
        ans[u]=t+1;
    else if(t-1>=mn[u])
        ans[u]=t-1;
    for(int i=0,sz=edge[u].size();i<sz;i++){
        int v=edge[u][i];
        if(v==fa)
            continue;
        dfs3(v,u,ans[u]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int q;
    scanf("%d",&q);
    memset(val,-1,sizeof val);
    int x;
    for(int i=1;i<=q;i++){
        scanf("%d",&x);
        scanf("%d",&val[x]);
    }
    dfs1(1,-1,1);
    for(int i=1;i<=n;i++){
        if(val[i]!=-1&&(((val[i]&1)^(deep[i]&1))!=((val[x]&1)^(deep[x]&1)))){
            nosolution();
        }
    }
    dfs2(1,-1);
    dfs3(1,-1,mx[1]-1);
    puts("Yes");
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}