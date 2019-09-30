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

const int T=1e5+10;

int n,c;
vi imos;
vi chnl[35];
int s,t,x;

signed main(){
    io();
    cin>>n>>c;
    imos.resize(2*T+10);
    REP(i,1,c+1) chnl[i].resize(2*T+10);

    rep(i,n){
        cin>>s>>t>>x;
        if(chnl[x][2*s]==-1){
            chnl[x][2*s]++;
        }else{
            chnl[x][2*s-1]++;
        }

        if(chnl[x][2*t-1]==1){
            chnl[x][2*t-1]--;
        }else{
            chnl[x][2*t]--;
        }
    }
/*
    REP(i,1,c+1){
        rep(j,2*t+1){
            cerr<<i<<","<<j<<" = "<<chnl[i][j]<<endl;
        }
    }
*/
    REP(i,1,c+1){
        rep(j,2*T){
            imos[j]+=chnl[i][j];
        }
    }

    int ans=-1;
    rep(i,2*T) {
        imos[i+1]+=imos[i];
        ans=max(imos[i+1],ans);
    }
    //rep(i,25) show(imos[i]);
    
    out(ans);

    return 0;
}