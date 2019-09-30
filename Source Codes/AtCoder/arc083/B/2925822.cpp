#include <iostream>
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
#define TRACE true
#define dump(x) if(TRACE) { cerr << #x << " = " << (x) << endl; }
#define dump2(x,y) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << ", " << #a << " = " << (a) << endl; }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }

/*
 
 7/30/2018
 
 18:00-18:45 pause
 20:40-21:06 TLE
 21:20 give up
 
 24:00- read editorials and add solution
 
 Editorials:
  - https://atcoder.jp/img/arc083/editorial.pdf
  - https://youtu.be/nCHz87GMdpo?t=1762
 
 I tried to build graph greedily from edges with smaller weight.
 However O(N^3*lg N) could not beat 2 secs time limit ?
 I couldn't come up with another approach ??
 
 If graph exists, given matrix should satisfy properties of FW's algorithm:
 
  ?k, dist[i][k]+dist[k][j]>=dist[i][j]
 
 If this is satisfied, we can remove redundant edges.

 If we find some `k` which satisfies dist[i][k]+dist[k][j]=dist[i][j], we can remove edge between `i` and `j`.
 That's possible because dist[i][k]+dist[k][j] is achieving shortest distance.
 We keep removing those edges. Remaining edge achieves minimal distance.
 
 How can I come up with this idea? ?
 
 Summary:
  - O(N^3*lg N) is not too bad. However I spent too much time to reach it. I couldn't make another effort to other solution
  -
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_V=300+1;
LL A[MAX_V][MAX_V];
int V;
// 18:00-18:45 pause
// 20:40-21:06 TLE
// 21:20 give up
const LL Inf=1e17;

vector<pair<LL,int>> G[MAX_V];
LL D[MAX_V];
LL dist(int s, int d) {
  REPE(i,V) D[i]=Inf;
  set<pair<LL,int>> Q;
  D[s]=0; Q.emplace(0,s);
  while(SZ(Q)) {
    LL d; int u;
    auto it=Q.begin();
    tie(d,u)=*it; Q.erase(it);
    FORR(p,G[u]) {
      LL w=p.first; int v=p.second;
      LL d2=d+w;
      if(d2<D[v]) {
        auto it2=Q.find({D[v],v});
        if(it2!=Q.end()) Q.erase(it2);
        Q.emplace(d2,v);
        D[v]=d2;
      }
    }
  }
  return D[d];
}

// 4 secs for test case #11
LL solve_TLE(vector<tuple<LL,int,int>> S) {
  LL res=0;
  FORR(t,S) {
    LL w; int u,v;
    tie(w,u,v)=t;
    LL d=dist(u,v);
    if(d<w) return -1;
    if(d==w) continue;
    
    G[u].emplace_back(w,v);
    G[v].emplace_back(w,u);
    res+=w;
  }
  return res;
}

LL solve() {
  REP(k,V)REP(i,V)REP(j,V) if(A[i][k]+A[k][j]<A[i][j]) return -1;
  LL res=0;
  REP(j,V)REP(i,j) res+=A[i][j];
  REP(j,V)REP(i,j) {
    bool ok=true;
    REP(k,V) if(k!=i&&k!=j&&A[i][k]+A[k][j]==A[i][j]) ok=false;
    if(!ok) res-=A[i][j];
  }
  
//  REP(j,V)REP(i,j) dump3(i,j,A[i][j]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>V;
  vector<tuple<LL,int,int>> X;
  REP(i,V)REP(j,V) cin>>A[i][j];
  
  /*
  REP(j,V)REP(i,j) {
    LL d=A[i][j];
    X.emplace_back(d,i,j);
  }
  sort(X.begin(),X.end());
   */
  cout<<solve()<<endl;

  return 0;
}