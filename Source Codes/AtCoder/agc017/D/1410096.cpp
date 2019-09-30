// sketchy code

#include <stdio.h>
#include <vector>

int t1,t2;

int n;

std::vector<int> g[100005];
bool vis[100005];
int nimsum[100005];

void dfs(int u)
{
    vis[u]=1;
    for (int v:g[u]) {
        if (vis[v]) continue;
        dfs(v);
        nimsum[u]^=nimsum[v]+1;
    }
    //printf("%d val %d\n",u,nimsum[u]);
}

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d",&n);
    for (int i=1; i<n; i++) {
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1);
    printf(nimsum[1]?"Alice":"Bob");
}