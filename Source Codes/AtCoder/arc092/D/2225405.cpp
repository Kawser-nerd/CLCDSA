#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX_V 1000
int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];//?????????
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];//?????????????????

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < G[v].size(); ++i){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(int i = 0; i < rG[v].size(); ++i){
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}
void scc(){
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < V; ++v){
        if(!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i =(int) vs.size()-1; i >= 0; i--){
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return;
}
int num[1000][1000];//num[i][j] = i??j??????????????(2???????2???)
int hoge[1000];//u->v????????????????
void dfs(int now,const int u,const int v){
    num[u][now]++;
    if(num[u][now]>=3){
        //??2?????now???2?????
        num[u][now] = 2;
        return;
    }
    if(num[u][now]==2){
        if(hoge[now] == v){
            num[u][now] = 1;
            return;
        }
    }
    if(num[u][now]==1){
        hoge[now] = v;
    }
    rep(i,G[now].size()){
        if(G[now][i] != u){
            dfs(G[now][i],u,v);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    V = n;
    vector<int>a(m),b(m);
    rep(i,m){
        scanf("%d%d",&a[i],&b[i]);
        a[i]--,b[i]--;
        add_edge(a[i],b[i]);
    }
    scc();
    rep(i,n){
        rep(k,n)hoge[k] = -1;
        rep(j,G[i].size()){
            dfs(G[i][j],i,G[i][j]);
        }
    }
    rep(i,m){
        bool flag = false;
        if(cmp[a[i]] == cmp[b[i]]){
            if(num[a[i]][b[i]]==2)flag = true;
        }else{
            if(num[a[i]][b[i]]==1)flag = true;
        }
        if(flag){
            puts("same");
        }else{
            puts("diff");
        }
    }
    return 0;
}