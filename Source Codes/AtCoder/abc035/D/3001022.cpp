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

ll tresurehant(){
    ll N, M, T;
    cin >> N >> M >> T;
    struct edge {ll to, cost;};
    vector<edge> G[2][MAX_N];
    ll d[2][MAX_N] = {llINF};
    ll treasure[MAX_N];
    REP(i, N){
        cin >> treasure[i];
    }
    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        edge cnewkouro = {b,c};
        edge dnewkouro = {a,c};
        G[0][a].push_back(cnewkouro);
        G[1][b].push_back(dnewkouro);
    }
    REP(ikikaeri, 2){
        priority_queue<llP, vector<llP>, greater<llP>> que;
        fill(d[ikikaeri], d[ikikaeri] + N, llINF);
        d[ikikaeri][0] = 0;
        que.push(llP(0, 0));
        while(!que.empty()){
            llP p = que.top();que.pop();
            ll v = p.second;
            if(d[ikikaeri][v] < p.first)continue;
            REP(i, G[ikikaeri][v].size()){
                edge e = G[ikikaeri][v][i];
                if(d[ikikaeri][e.to] > d[ikikaeri][v] + e.cost){
                    d[ikikaeri][e.to] = d[ikikaeri][v] + e.cost;
                    que.push(llP(d[ikikaeri][e.to], e.to));
                }
            }
        }
    }
    ll saidai = 0;
    REP(i, N){
        if(T > d[0][i] + d[1][i] && d[0][i] + d[1][i] >= 0){
            if(saidai <= (T - d[0][i] - d[1][i]) * treasure[i]){
                saidai = (T - d[0][i] - d[1][i]) * treasure[i];
            }
        }
    }
    
    return saidai;
}

int funatabi(){
    int n, k;
    cin >> n >> k;
    struct edge {int to, cost;};
    vector<edge> G[MAX_N];
    vector<int> henji;
    int d[MAX_N] = {-1};
    REP(nyuuryoku, k){
        int saisho;
        cin >> saisho;
        if(saisho == 0){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            priority_queue<P, vector<P>, greater<P>> que;
            fill(d, d + n, INF);
            d[a] = 0;
            que.push(P(0, a));
            while(!que.empty()){
                P p = que.top();que.pop();
                int v = p.second;
                if(d[v] < p.first)continue;
                REP(i, G[v].size()){
                    edge e = G[v][i];
                    if(d[e.to] > d[v] + e.cost){
                        d[e.to] = d[v] + e.cost;
                        que.push(P(d[e.to], e.to));
                    }
                }
            }
            if(d[b] == INF)henji.push_back(-1);
            else henji.push_back(d[b]);
        }else{
            int c, d, e;
            cin >> c >> d >> e;
            c--;d--;
            edge cnewkouro = {d,e};
            edge dnewkouro = {c,e};
            G[c].push_back(cnewkouro);
            G[d].push_back(dnewkouro);
        }
    }
    REP(i ,henji.size()){
        printf("%d\n", henji[i]);
    }
    return 0;
}

int savingsnuuk(){
    struct senro{
        int next;
        int yen;
        int snuuk;
    };
    bool used[2][MAX_N] = {false};
    vector<senro> sunuke[MAX_N];
    ll ryoukin[3][MAX_N] = {0};
    REP(i, 2){
        REP(j, MAX_N){
            ryoukin[i][j] = llINF;
        }
    }
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    REP(i, m){
        int u,v,a,b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        senro uto = {v,a,b};
        senro vto = {u,a,b};
        sunuke[u].push_back(uto);
        sunuke[v].push_back(vto);
    }
    priority_queue<P, vector<P>, greater<P> > que[2];
    ryoukin[0][s] = 0;
    ryoukin[1][t] = 0;
    que[0].push(P(0,s));
    que[1].push(P(0,t));
    REP(tuuka, 2){
        while(!que[tuuka].empty()){
            P p = que[tuuka].top();
            que[tuuka].pop();
            int v = p.second;
            if(ryoukin[tuuka][v] < p.first) continue;
            REP(i, sunuke[v].size()){
                senro e = sunuke[v][i];
                int cost;
                if(tuuka == 0)cost = e.yen;
                else cost = e.snuuk;
                if(ryoukin[tuuka][e.next] > ryoukin[tuuka][v] + cost){
                    ryoukin[tuuka][e.next] = ryoukin[tuuka][v] + cost;
                    que[tuuka].push(P(ryoukin[tuuka][e.next], e.next));
                }
            }
        }
    }
    
    ryoukin[2][n] = llINF;
    REP(i, n){
        ryoukin[2][n - i - 1] = min(ryoukin[2][n - i], ryoukin[0][n - i - 1] + ryoukin[1][n - i - 1]);
    }
    REP(i, n){
        printf("%lld\n", 1000000000000000 - ryoukin[2][i]);
    }
    return 0;
}

int main(){
    printf("%lld\n", tresurehant());
}