//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <complex>
#include <bitset>
#include <functional>
#include <stack>
#include <regex>
#include <tuple>
#include <iomanip>

#define int long long
#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define show(n) cerr<<#n<<" = "<<n<<endl
#define showp(n) cerr<<n.fs<<", "<<n.sc<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
#define showsp(n) for(auto z:n){cerr<<z.fs<<" "<<z.sc<<", "}cerr<<endl

#define yes puts("Yes")
#define no puts("No")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

inline void io(){cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(20);}
template<typename T> inline void in(T &e){cin>>e;}
template<typename T> inline void out(T e){cout<<e<<endl;}

const int INF=1LL<<55;
const int MOD=1000000007;
const double EPS=1e-8;

const int MAX_V=100010;

int Q,K;

struct edge{
    int to;
    int cost;
};

int V; //???
vector<edge>G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
    priority_queue<pint,vector<pint>,greater<pint> > que;
    fill(d,d+V,INF);
    d[s]=0;

    que.push(pint(0,s));

    while(!que.empty()){
        pint p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pint(d[e.to],e.to));
            }
        }
    }
}

signed main(){
    io();
    in(V);
    int a,b,c;
    rep(i,V-1){
        scanf("%lld %lld %lld", &a,&b,&c);
        a--; b--;
        edge e={b,c};
        G[a].push_back(e);
        e.to=a;
        G[b].push_back(e);
    }
    scanf("%lld %lld", &Q,&K);
    K--;
    dijkstra(K);

    int x,y;
    rep(i,Q){
        scanf("%lld %lld", &x,&y);
        x--;y--;
        out(d[x]+d[y]);
    }

    return 0;
}