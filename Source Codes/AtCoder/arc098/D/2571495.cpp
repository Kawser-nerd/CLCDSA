// do the game in reverse order
// you start with a certain amount (minimize this amount)
// pick any vertex
// do these operations as many times as possible
// 1. get the donation money, and check if there is enough money for this node
// 2. check if there is enough money for this node, then move to an adjacent node
// note: you can only get the donation money for one node at most once

// binary search + disjoint set is possible?
// order the edges by the amount needed to traverse this edge

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

int t1,t2;

int n,m;

std::vector<int> g[100005];

int a[100005];
int b[100005];

// disjoint set stuff
std::vector<int> todo;
bool todo2[100005];     // determine if a vertex is in todo

std::priority_queue<std::pair<int,int> > pq[100005];
int endval;
int up[100005];
int sz[100005];
long long money[100005];
bool active[100005];

int getroot(int u)
{
    if (u==up[u]) return u;
    return up[u]=getroot(up[u]);
}

void join2(int u,int v)
{
    up[v]=u;
    sz[u]+=sz[v];
    money[u]+=money[v]-endval;
    active[u]=1;
    while (!pq[v].empty()) {
        pq[u].push(pq[v].top());
        pq[v].pop();
    }
}

int join(int u,int v)
{
    // return the root of their union
    u=getroot(u);
    v=getroot(v);
    if (u==v) return u;
    if (sz[u]>=sz[v]) {
        join2(u,v);
        return u;
    }
    else {
        join2(v,u);
        return v;
    }
}

bool good(int x)
{
    endval=x;
    memset(active,0,sizeof active);
    // make the pq
    for (int i=1; i<=n; i++) {
        up[i]=i;
        sz[i]=1;
        money[i]=x+b[i];
        if (money[i]>=a[i]) active[i]=1;
        while (!pq[i].empty()) pq[i].pop();
        for (int j:g[i]) pq[i].push({b[j]-a[j],j});
    }
    // do vertices
    for (int i=1; i<=n; i++) {
        int u=getroot(i);
        if (!active[u]) continue;
        //printf("start at %d\n",i);
        // do this vertex
        while (!pq[u].empty() && -pq[u].top().first<=money[u]) {
            int v=pq[u].top().second;
            pq[u].pop();
            //printf("do %d -> %d\n",u,v);
            u=join(u,v);
        }
    }
    // check
    for (int i=2; i<=n; i++) {
        if (getroot(1)!=getroot(i)) return 0;
    }
    return 1;
}

int lo=0;
int hi=0x3f3f3f3f;
int mid;

long long ans;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++) scanf("%d%d",a+i,b+i);
    for (int i=0; i<m; i++) {
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    if (n==1) {
        if (a[1]>b[1]) printf("%d\n",a[1]);
        else printf("%d\n",b[1]);
        return 0;
    }
    //good(0); return 0;
    while (lo<hi) {
        mid=(lo+hi)/2;
        if (good(mid)) hi=mid;
        else lo=mid+1;
        //printf("%d %d\n",lo,hi);
    }
    ans=lo;
    for (int i=1; i<=n; i++) ans+=b[i];
    printf("%lld\n",ans);
}