#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <cstring>
#include <tuple>
#include <cassert>
#include <numeric>
using namespace std;
// type alias
typedef long long LL;
typedef vector < int > VI;
typedef unordered_map < int, int > MAPII;
typedef unordered_set < int > SETI;
typedef pair< int , int > II;
typedef tuple< int, int, int > III;
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))
// minmax
#define SMAX(a,b) a = max(a,b)
#define SMIN(a,b) a = min(a,b)
// debug cerr
#define TRACE false
#define dump(x) if(TRACE) { cerr << #x << " = " << (x) << endl; }
#define dump2(x,y) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << ", " << #a << " = " << (a) << endl; }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }

/*
 
 8/6/2018
 
 17:10-17:20 analysis
 17:35 RE
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=300+1;
int H,W,D,Q;
II P[MAX_N*MAX_N];
const int MAX_Q=1e5+1;
int L[MAX_Q],R[MAX_Q];
vector<LL> cum[MAX_N*MAX_N];
void solve() {
  REP(d,D) {
    int x=d;
    cum[d].clear();
    cum[d].push_back(0);
    while(x+D<H*W) {
      cum[d].push_back(cum[d].back());
      int xx=x+D;
      auto p1=P[x],p2=P[xx];
      LL cost=abs(p1.first-p2.first)+abs(p1.second-p2.second);
      cum[d].back()+=cost;
      dump4(d,x,xx,cost);
      x=xx;
    }
  }
  REP(i,Q) {
    int g=L[i]%D;
    int l=L[i]/D,r=R[i]/D;
    dump4(i,L[i],R[i],g);
    dump4(l,cum[g][l],r,cum[g][r]);
    cout<<cum[g][r]-cum[g][l]<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>H>>W>>D;
  REP(i,H)REP(j,W) {
    int p; cin>>p;
    P[p-1]={i,j};
  }
  cin>>Q;
  REP(i,Q) cin>>L[i]>>R[i],--L[i],--R[i];
  solve();
  return 0;
}