#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>
#include <string>
#include <tuple>
#include <deque>
#include <set>
#include <map>
#include <stack>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long
const int INF = 1 << 29;
const ll llINF = 10000000000000000;

const int MOD = 1000000007;

#define MAX_N 100100
typedef pair<int, int> P;
typedef pair<ll, ll> llP;

class UnionFindTree{
private:
    int par[MAX_N];
    int urank[MAX_N];
    int size[MAX_N];
public:
    int init(int n);
    int find(int x);
    int unite(int x, int y);
    int same(int x, int y);
    int parnum(int x){return par[x];}
    int ranknum(int x){return urank[x];}
    int sizenum(int x){return size[find(x)];}
};

int UnionFindTree::init(int n){
    REP(i, n){
        par[i] = i;
        urank[i] = 0;
        size[i] = 1;
    }
    return 0;
}

int UnionFindTree::find(int x){
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
}

int UnionFindTree::unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)return 0;
    if(urank[x] < urank[y]){
        par[x] = y;
        size[y] += size[x];
    }else{
        par[y] = x;
        size[x] += size[y];
        if(urank[x] == urank[y])urank[x] ++;
    }
    return 0;
}

int UnionFindTree::same(int x, int y){
    return find(x) == find(y);
}


int asteroids2(){
    struct edge{int from, to, cost;};
    edge es[205000];
    int d[2020];
    int N, M;
    cin >> N >> M;
    int  E = 4 * N + 2 * M;
    REP(i, N){
        int p;
        cin >> p;
        es[2 * i] = edge{0, i + 1, p};
        es[2 * i + 1] = edge{i + 1, 0, 0};
    }
    REP(i, N){
        int q;
        cin >> q;
        es[2 * i + 2 * N] = edge{i + 1 + N, 0, q};
        es[2 * i + 1 + 2 * N] = edge{0, i + 1 + N, 0};
    }
    REP(i, 2 * N){
        d[i] = INF;
    }
    d[0] = 0;
    REP(i, M){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        y += N;
        es[2 * i + 4 * N] = edge{y, x, b};
        es[2 * i + 1 + 4 * N] = edge{x, y, -a};
    }
    
    
    bool negativeroop = false;
    REP(kurikaesi, 2 * N + 1){
        REP(i, E){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(kurikaesi == 2 * N)negativeroop = true;
            }
        }
        if(d[0] < 0){
            printf("no\n");
            return 0;
        }
    }
    if(negativeroop)printf("no\n");
    else printf("yes\n");
    
    return 0;
}


int scoreatack(){
    ll d[1010][1010] = {INF};
    int V;
    int E;
    cin >> V >> E;
    REP(i, V){
        REP(j, V){
            d[i][j] = -llINF / 100;
        }
    }
    REP(i, V){
        d[i][i] = 0;
    }
    REP(i, E){
        int s, t, de;
        cin >> s >> t >> de;
        s--;
        t--;
        d[s][t] = de;
    }
    
    REP(k, V){
        REP(i, V){
            REP(j, V){
                if(d[i][j] < d[i][k] + d[k][j])d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    bool isinf = false;
    REP(i, V){
        if(d[i][i] > 0 && d[0][i] > -llINF / 200 && d[i][V - 1] > -llINF / 200)isinf = true;
    }
    
    if(isinf)printf("inf\n");
    else printf("%lld\n", d[0][V - 1]);
    return 0;
}

int warshall_floyd(){
    ll d[1010][1010] = {INF};
    int V;
    int E, r;
    cin >> V >> E >> r;
    REP(i, V){
        REP(j, V){
            d[i][j] = INF;
        }
    }
    REP(i, V){
        d[i][i] = 0;
    }
    REP(i, E){
        int s, t, de;
        cin >> s >> t >> de;
        d[s][t] = de;
    }
    REP(k, V){
        REP(i, V){
            REP(j, V){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    bool nc = false;
    REP(i, V){
        if(d[i][i] < 0 && d[r][i] < INF / 2)nc = true;
    }
    if(nc)printf("NEGATIVE CYCLE\n");
    else{
        REP(i, V){
            if(d[r][i] > INF / 2)printf("INF\n");
            else printf("%lld\n", d[r][i]);
        }
    }
    
    return 0;
}


int bellmanford(){
    struct edge{int from, to, cost;};
    edge es[2010];
    int d[1010];
    int V, E, s;
    cin >> V >> E >> s;
    REP(i, V){
        d[i] = INF;
    }
    d[s] = 0;
    REP(i, E){
        int ss, tt, dd;
        cin >> ss >> tt >> dd;
        es[i] = edge{ss, tt, dd};
    }
    bool negativeroop = false;
    REP(kurikaesi, V){
        REP(i, E){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(kurikaesi == V - 1)negativeroop = true;
            }
        }
    }
    if(negativeroop)printf("NEGATIVE CYCLE\n");
    else{
        REP(i, V){
            if(d[i] > INF / 2)printf("INF\n");
            else printf("%d\n", d[i]);
        }
    }
    return 0;
}

int sakerarenaibus(){
    int d[1010][1010] = {INF};
    int V;
    int E;
    cin >> V >> E;
    REP(i, V){
        REP(j, V){
            d[i][j] = INF;
        }
    }
    REP(i, V){
        d[i][i] = 0;
    }
    REP(i, E){
        int s, t, de;
        cin >> s >> t >> de;
        s--;
        t--;
        d[s][t] = de;
        d[t][s] = de;
    }
    REP(k, V){
        REP(i, V){
            REP(j, V){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    int saikounosaitei = INF;
    REP(i, V){
        int saitei = 0;
        REP(j, V){
            saitei = max(saitei, d[i][j]);
        }
        saikounosaitei = min(saitei, saikounosaitei);
    }
    
    return saikounosaitei;
}

int main(){
    printf("%d\n", sakerarenaibus());
}