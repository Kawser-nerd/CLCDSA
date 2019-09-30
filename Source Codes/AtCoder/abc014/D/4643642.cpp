#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int root;
vector<int> g[100001];
int parent[17][100001];
int depth[100001];

void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<g[v].size();i++){
        if(g[v][i]!=p){
            dfs(g[v][i],v,d+1);
        }
    }
}

void init(int V){
    dfs(root,-1,0);
    for(int i=0;i+1<17;i++){
        for(int j=1;j<=V;j++){
            if(parent[i][j]<0){
                parent[i+1][j]=-1;
            }
            else{
                parent[i+1][j]=parent[i][parent[i][j]];
            }
        }
    }
}

int lca(int x,int y){
    if(depth[x]>depth[y]){
        swap(x,y);
    }
    for(int i=0;i<17;i++){
        if((depth[y]-depth[x]) >> i&1){
            y=parent[i][y];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=16;i>=0;i--){
        if(parent[i][x]!=parent[i][y]){
            x=parent[i][x];
            y=parent[i][y];
        }
    }
    return parent[0][x];
}

int main(){
    int n,x,y,q,z;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    root=1;
    init(n);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&x,&y);
        z=lca(x,y);
        printf("%d\n",1+depth[x]+depth[y]-2*depth[z]);
    }
}