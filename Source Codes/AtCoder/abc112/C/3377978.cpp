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
#define showslr(n,l,r) cerr<<#n<<" = ";for(int i=l;i<r;i++){cerr<<n[i]<<", ";}cerr<<endl //[l, r)

#define yes puts("Yes")
#define no puts("No")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

inline void io(){cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(20);}

void _DEBUG(){cerr<<endl;}
template<typename H,typename... T> void _DEBUG(H a,T...b){cerr<<a<<",";_DEBUG(b...);}

inline void in(){}
template<typename H,typename... T>void in(H &a, T&... b){cin>>a;in(b...);}
inline void out(){}
template<typename H,typename... T> void out(H a, T... b){cout<<a<<endl;out(b...);}

void RESIZE(int sz){}
template<class H,class... T> void RESIZE(int sz,H &a,T&... b){
    a.resize(sz);
    RESIZE(sz,b...);
}

const int INF=1LL<<55;
const int MOD=1000000007;
const double EPS=1e-8;

int n;
vi x,y,h;

signed main(){
    io();

    in(n);
    RESIZE(n,x,y,h);
    rep(i,n){
        in(x[i],y[i],h[i]);
    }
    rep(j,101){
        rep(i,101){
            bool f=true;
            int htmp=-1;
            rep(k,n){
                if(h[k]>0){
                    int dx=abs(i-x[k]),dy=abs(j-y[k]);
                    htmp=h[k]+dx+dy;
                    break;
                }
            }
            rep(k,n){
                int dx=abs(i-x[k]),dy=abs(j-y[k]);
                if(htmp-dx-dy<0){
                    if(h[k]!=0){
                        f=false;
                        break;
                    }
                }else{
                    if(htmp!=h[k]+dx+dy){
                        f=false;
                        break;
                    }
                }
            }
            if(f){
                printf("%lld %lld %lld\n",i,j,htmp);
                return 0;
            }
        }
    }

    return 1;
}