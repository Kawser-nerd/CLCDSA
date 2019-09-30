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
#define TRACE true
#define dump(x) if(TRACE) { cerr << #x << " = " << (x) << endl; }
#define dump2(x,y) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << ", " << #a << " = " << (a) << endl; }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }

/*
 
 8/10/2018
 
 16:30-16:37 analysis
 16:54 ok there exists negative weight...
 17:01 got WA (3 out of 30)
 17:13 give up
 
 Editorials:
  - https://youtu.be/6gxJ8Fy8O3I?t=1294
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e3+1;
int N,M;
vector<pair<LL,int>> E[MAX_N];
const LL Inf=1e18;

int viz[MAX_N];
bool dfs(int u) {
//  dump2(u,viz[u]);
  if(viz[u]==-1) return true;
  if(viz[u]==1) return false;
  bool res=false;
  viz[u]=-1;
  FORR(p,E[u]) {
    res|=dfs(p.second);
  }
  viz[u]=1;
  return res;
}

LL D[MAX_N];
void dfs2(int u, LL d) {
  if(D[u]>=d) return;
  dump2(u,d);
  D[u]=d;
  if(u==N-1) return;
  FORR(p,E[u]) dfs2(p.second,d+p.first);
}

void solve_wrong() {
  ZERO(viz);
  if(dfs(0)) {
    cout<<"inf"<<endl;
    return;
  }
  MINUS(D);
  dfs2(0,0);
  REP(i,N) dump2(i,D[i]);
  cout<<D[N-1]<<endl;
}

void dfsdfs(int u) {
  if(viz[u]) return;
  viz[u]=true;
  FORR(p,E[u]) dfsdfs(p.second);
}

void solve_wrong2() {
  REP(i,N) D[i]=-Inf;
  D[0]=0;
  
  ZERO(viz);
  dfsdfs(0);
  
  REP(_,N) {
    REP(u,N)FORR(p,E[u]) {
      LL w; int v; tie(w,v)=p;
      if(!viz[u]||!viz[v]) continue;
      LL d2=D[u]+w;
      if(d2>D[v]) D[v]=d2;
    }
  }
  
  REP(u,N)FORR(p,E[u]) {
    LL w; int v; tie(w,v)=p;
    if(!viz[u]||!viz[v]) continue;
    LL d2=D[u]+w;
    if(d2>D[v]) {
      cout<<"inf"<<endl;
      return;
    }
  }
  cout<<D[N-1]<<endl;
}

void solve() {
  REP(i,N) D[i]=-Inf;
  D[0]=0;
  
  ZERO(viz);
  dfsdfs(0);
  
  REP(_,N) {
    REP(u,N)FORR(p,E[u]) {
      LL w; int v; tie(w,v)=p;
      if(!viz[u]||!viz[v]) continue;
      LL d2=D[u]+w;
      if(d2>D[v]) D[v]=d2;
    }
  }
  LL res=D[N-1];
  REP(_,N) {
    REP(u,N)FORR(p,E[u]) {
      LL w; int v; tie(w,v)=p;
      if(!viz[u]||!viz[v]) continue;
      LL d2=D[u]+w;
      if(d2>D[v]) D[v]=d2;
    }
  }
  if(res==D[N-1]) cout<<D[N-1]<<endl;
  else cout<<"inf"<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>M;
  REP(i,M) {
    int u,v; LL w; cin>>u>>v>>w;
    --u,--v;
    E[u].emplace_back(w,v);
  }
  solve();
  return 0;
}