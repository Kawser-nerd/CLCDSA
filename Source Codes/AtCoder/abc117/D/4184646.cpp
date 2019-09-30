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
#define REP(i,l,r) REPEAT(i,l,r,true) // [l, r)
#define rep(i,n) REP(i,0,n)           // [0, n)
#define REPEAT(i,l,r,condition) for(int i=(condition)?l:r-1;(condition)?i<r:i>=l;(condition)?++i:--i) // false<-[l, r)->true
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define fs first
#define sc second
#define show(...) cerr<<#__VA_ARGS__<<" = ";_DEBUG(__VA_ARGS__)
#define showlr(n,l,r) cerr<<#n<<" = ";for(int i=l;i<r;i++){cerr<<n[i]<<", ";}cerr<<endl // [l, r)

#define yes puts("Yes")
#define no puts("No")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

struct io{io(){cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(20);}}io;

template<class T> istream& operator >>(istream &is, vector<T> &v){for(T &e:v)is>>e;return is;}
template<class T> ostream& operator <<(ostream &os, vector<T> v){os<<"{";for(T &e:v)os<<e<<(v.size()-(int)(&e-&v[0])>1?", ":"");os<<"}";return os;}

void _DEBUG(){}
template<typename H,typename... T> void _DEBUG(H a,T...b){cerr<<a<<(sizeof...(b)?",":"\n");_DEBUG(b...);}

inline void in(){}
template<typename H,typename... T>void in(H &a, T&... b){cin>>a;in(b...);}
inline void out(){}
template<typename H,typename... T> void out(H a, T... b){cout<<a<<(sizeof...(b)?" ":"\n");out(b...);}

template<class T> void resz(int n,T& v){v.resize(n);}
template<class H,class... T> void resz(int n,H& a,T&... b){a.resize(n);resz(n,b...);}

const int INF=1LL<<55;
const int MOD=1000000007;
const double EPS=1e-8;

#define bit(x) (1LL<<(x))

int n,k;
vi a;
vector<vi> dp(51, vi(2,-1));

signed main(){

    in(n,k);
    resz(n,a);
    in(a);

    dp[0][0]=0;
    REP(i,1,50){
        int num=0;
        // show(i,bit(i),bit(49-i));
        rep(j,n) if(a[j]&(bit(49-i))) num++;

        int res0=bit(49-i)*num,res1=bit(49-i)*(n-num);

        if(dp[i-1][0]!=-1){
            if(k&bit(49-i)){
                dp[i][0]=dp[i-1][0]+res1;
            }else{
                dp[i][0]=dp[i-1][0]+res0;
            }
        }

        if(dp[i-1][0]!=-1){
            if(k&bit(49-i)){
                dp[i][1]=dp[i-1][0]+res0;
            }
        }

        if(dp[i-1][1]!=-1){
            dp[i][1]=max(dp[i][1],dp[i-1][1]+max(res0,res1));
        }

        // show(i,49-i,dp[i][0],dp[i][1]);
    }
    out(max(dp[49][0],dp[49][1]));

    return 0;
}