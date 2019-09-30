// get the graph diameter

#include <stdio.h>
#include <vector>
#include <string.h>

#define INFLL 0x3f3f3f3f3f3f3f3f

int t1,t2;
int n;

std::vector<int> g[105];
int dist[105][105];

int d,d1,d2;
std::vector<int> diameter;

int dist2[105];
int subchild[105];

void dfs(int u)
{
    int cnt=0;
    for (int v:g[u]) {
        if (dist2[v]) continue;
        dist2[v]=dist2[u]+1;
        dfs(v);
        cnt++;
    }
    if (subchild[dist2[u]]<cnt) {
        subchild[dist2[u]]=cnt;
    }
}

int ans1;
long long ans2,anst;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    memset(dist,0x3f,sizeof dist);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) dist[i][i]=0;
    for (int i=1; i<n; i++) {
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        dist[t1][t2]=dist[t2][t1]=1;
    }
    // stupid way of getting the diameter
    for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) {
        if (dist[i][j]>dist[i][k]+dist[k][j]) {
            dist[i][j]=dist[i][k]+dist[k][j];
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) {
        if (d<dist[i][j]) {
            d=dist[i][j];
            d1=i;
            d2=j;
        }
    }
    while (d1!=d2) {
        diameter.push_back(d1);
        for (int i:g[d1]) {
            if (dist[d1][d2]>dist[i][d2]) {
                d1=i;
                break;
            }
        }
    }
    diameter.push_back(d2);
    //for (int i:diameter) printf("%d ",i); printf("is diameter\n");
    // do stuff with the diameter
    // not sure what this code is doing
    if (diameter.size()%2==1) {
        dist2[diameter[diameter.size()/2]]=1;
        dfs(diameter[diameter.size()/2]);
        ans1=diameter.size()/2+1;
        // if this was the center
        ans2=1;
        for (int i=1; i<ans1; i++) {
            ans2*=subchild[i];
            //printf("%d s %d\n",i,subchild[i]);
        }
        // if another vertex is also the center
        for (int v:g[diameter[diameter.size()/2]]) {
            memset(dist2,0,sizeof dist2);
            memset(subchild,0,sizeof subchild);
            dist2[diameter[diameter.size()/2]]=1;
            dist2[v]=1;
            dfs(diameter[diameter.size()/2]);
            dfs(v);
            anst=ans2;
            ans2=2;
            for (int i=1; i<ans1; i++) {
                ans2*=subchild[i];
                //printf("%d -> %d s %d\n",v,i,subchild[i]);
            }
            if (ans2>anst) {
                ans2=anst;
            }
        }
    }
    else {
        dist2[diameter[diameter.size()/2]]=1;
        dist2[diameter[diameter.size()/2-1]]=1;
        dfs(diameter[diameter.size()/2]);
        dfs(diameter[diameter.size()/2-1]);
        ans1=diameter.size()/2;
        ans2=2;
        for (int i=1; i<ans1; i++) {
            ans2*=subchild[i];
            //printf("%d s %d\n",i,subchild[i]);
        }
    }
    printf("%d %lld\n",ans1,ans2);
}