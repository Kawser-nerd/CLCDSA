#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <time.h>
#include <random>
using namespace std;

int oe[100000];
vector<int> G[100000];

struct union_find{
    vector<int> par, rank;
    union_find(int n){
        par = vector<int>(n);
        rank = vector<int>(n);
        init(n);
    }
    void init(int n){
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(par[x]==x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(rank[x]<rank[y]){
            par[x]=y;
        }else{
            par[y]=x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

bool dfs(int v){
    for(auto g:G[v]){
        if(oe[g]==-1){
            if(oe[v])oe[g]=0;
            else oe[g]=1;
            if(dfs(g)) return true;
        }else{
            if(oe[g]==oe[v]) return true;
        }
    }
    return false;
}

int main(){
    int N,M;
    fill(oe,oe+100000,-1);
    cin>>N>>M;
    union_find UF(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        UF.unite(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int64_t sep=0,uni=0,single=0;
    for(int i=0;i<N;i++){
        if(UF.find(i)==i){
            if(!G[i].size()){
                single++;
                continue;
            }
            oe[i]=0;
            if(dfs(i)){
                uni++;
            }else{
                sep++;
            }
        }
    }
    int64_t ans = single*N*2-single*single;
    ans+=uni*uni;
    ans+=2*uni*sep;
    ans+=2*sep*sep;
    // cout<<sep<<' '<<uni<<' '<<single<<endl;
    cout<<ans<<endl;
    return 0;
}