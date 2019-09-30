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
#define REP(i,l,r) REPEAT(i,l,r,true) //[l, r)
#define rep(i,n) REP(i,0,n)           //[0, n)
#define REPEAT(i,l,r,condition) for(int i=(condition)?l:r-1;(condition)?i<r:i>=l;(condition)?++i:--i) // false<-[l, r)->true
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define fs first
#define sc second
#define show(...) cerr<<#__VA_ARGS__<<" = ";_DEBUG(__VA_ARGS__)
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
#define showslr(n,l,r) cerr<<#n<<" = ";for(int i=l;i<r;i++){cerr<<n[i];}cerr<<endl //[l, r))

#define yes puts("Yes")
#define no puts("No")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

inline void io(){cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(20);}

void _DEBUG(){cerr<<endl;}
template<typename H,typename... T> void _DEBUG(H a,T...b){cerr<<a<<",";_DEBUG(b...);}

template<typename T> inline void in(T &e){cin>>e;}
template<typename H,typename... T>void in(H &a, T&... b){in(a);in(b...);}
template<typename T> inline void out(T e){cout<<e<<endl;}
template<typename H,typename... T> void out(H a, T... b){out(a);out(b...);}

const int INF=1LL<<55;
const int MOD=1000000007;
const double EPS=1e-8;

// ????? ????????????????
#define MAX_E 10000
#define MAX_V 1010

// ??from????to?????cost??
struct edge{
    int from,to;
    int cost;
};

edge es[MAX_E];

vector<bool> n(MAX_V,false);

int d[MAX_V];
int V,E;

// true???????????
bool find_negative_loop(){
    //memset(d,0,sizeof(d));

    for(int i=0;i<V;i++){
        for(int j=0;j<E;j++){
            edge e=es[j];
            if(d[e.from]==INF) continue;
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                n[e.to]=true;
                // n????????????????????
                if(i==V-1) return true;
            }
            if(n[e.from]) n[e.to]=true;
        }
    }
    return false;
}

// s????????????????????
void shortest_path(int s){
    for(int i=0;i<V;i++) d[i]=INF;
    d[s]=0;
    /*while(true)*/rep(i,V-1){
        //bool update=false;
        for(int i=0;i<E;i++){
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                //update=true;
            }
        }
        //if(!update) break;
    }
}

signed main(){
    io();
    in(V,E);
    rep(i,E){
        int a,b,c;
        in(a,b,c);
        a--;b--;c*=-1;
        edge e={a,b,c};
        es[i]=e;
        //show(es[i].from,es[i].to,es[i].cost);
    }
    shortest_path(0);
    find_negative_loop();
    if(n[V-1]){
        out("inf");
        return 0;
    }

    out(-d[V-1]);

    return 0;
}