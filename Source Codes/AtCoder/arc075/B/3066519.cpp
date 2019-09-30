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

const int INF=1LL<<30;
const int MOD=1000000007;
const double EPS=1e-8;

int n,a,b;
vi hp;

signed main(){
    io();
    in(n,a,b);
    hp.resize(n);
    rep(i,n) in(hp[i]);

    int ok=INF,ng=0;
    a-=b;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        int need=0;
        for(auto e:hp){
            need+=(max(e-b*mid,0LL)+(a-1))/a;
            if(need > mid) break;
        }
        show(ok,ng,mid,need);
        if(need<=mid) ok=mid;
        else ng=mid;
    }
    out(ok);

    return 0;
}