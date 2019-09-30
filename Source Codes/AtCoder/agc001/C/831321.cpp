#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <set>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define LL long long
#define ULL unsigned long long
#define eps 1e-9
#define N 2010
#define M 600050
#define pii pair<int,int>
#define MP make_pair
#define inf 0x3f3f3f3f
#define md ((ll+rr)>>1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define ls rt<<1
#define rs rt<<1|1
#define Pi acos(-1.0)
#define mod 1000000007
#define ui unsigned int
LL powmod(LL a,LL b,LL p){
    if(b < 0) return 0;
    LL res = 1; a %= p;
    for(;b;b>>=1){
        if(b & 1) res = res * a % p;
        a = a * a % p;
    }
    return res;
}

int fst[N],nxt[M],vv[M],e;

void init(){
    e = 0;
    memset(fst,-1,sizeof fst);
}

void add(int u,int v){
    vv[e] = v,nxt[e] = fst[u],fst[u] = e++;
    vv[e] = u,nxt[e] = fst[v],fst[v] = e++;
}

int dis[N][N];

void dfs(int u,int f,int o){
    for(int i = fst[u]; ~i; i = nxt[i]){
        int v = vv[i];
        if(v == f)continue;
        dis[o][v] = dis[o][u] + 1;
        dfs(v, u, o);
    }
}

pair<int, int> edge[N];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    init();
    for(int i = 1; i < n; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u, v);
        edge[i] = MP(u,v);
    }
    
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
        dfs(i, 0, i);
    }
    
    int ans = inf;
    if(k % 2 == 0){
        for(int i = 1; i <= n; i++){
            int tmp = 0;
            for(int j = 1; j <= n; j++){
                if(dis[i][j] > k / 2) tmp++;
            }
            ans = min(ans,tmp);
        }
    }else{
        for(int i = 1; i < n; i++){
            int u = edge[i].first;
            int v = edge[i].second;
            int tmp = 0;
            for(int j = 1; j <= n; j++)
                if(min(dis[u][j],dis[v][j]) > k/2) tmp++;
            ans = min(ans,tmp);
        }
    }
    printf("%d\n",ans);
}