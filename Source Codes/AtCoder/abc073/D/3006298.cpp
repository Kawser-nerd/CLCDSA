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

const int MAX_V=210;

int M,R;

vi route;

int d[MAX_V][MAX_V];
int V;
int ans=INF;

void warshall_floyd(){
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}

signed main(){
    io();
    cin>>V>>M>>R;
    route.resize(R);
    rep(i,R){
        in(route[i]);
        route[i]--;
    }

    sort(all(route));

    fill(d[0],d[MAX_V-1],INF);
    rep(i,MAX_V) d[i][i]=0;
    int a,b,c;
    rep(i,M){
        cin>>a>>b>>c;
        a--;b--;
        d[a][b]=c;
        d[b][a]=c;
    }

    warshall_floyd();
    rep(i,V){
        rep(j,V) cerr<<d[i][j]<<" ";
        cerr<<endl;
    }

    int res;
    do{
        res=0;
        rep(i,R-1){
            res+=d[route[i]][route[i+1]];
        }
        //show(res);
        ans=min(ans,res);
    }while(next_permutation(all(route)));

    out(ans);

    return 0;
}