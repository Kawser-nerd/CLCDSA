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

const int INF=1LL<<62;
const int MOD=1000000007;
const double EPS=1e-8;

int N,K;

vi x,y;

vi rectx(2),recty(2);

int ans=INF;
int sum;

signed main(){
    io();
    cin>>N>>K;
    x.resize(N+1);y.resize(N+1);
    rep(i,N) cin>>x[i]>>y[i];

    rep(i,N){
        REP(j,i+1,N){
            rep(k,N){
                REP(l,k+1,N){
                    rectx[0]=x[i];
                    rectx[1]=x[j];
                    recty[0]=y[k];
                    recty[1]=y[l];
                    sort(all(rectx));
                    sort(all(recty));
                    sum=0;
                    rep(m,N){
                        if(rectx[0]<=x[m]&&x[m]<=rectx[1]&&recty[0]<=y[m]&&y[m]<=recty[1]){
                            sum++;
                        }
                    }
                    if(sum>=K){
                        //show(rectx[1]-rectx[0]);
                        //show(recty[1]-recty[0]);
                        //show(abs((rectx[1]-rectx[0])*(recty[1]-recty[0])));
                        ans=min(ans,abs((rectx[1]-rectx[0])*(recty[1]-recty[0])));
                    }
                }
            }
        }
    }
    out(ans);

    return 0;
}