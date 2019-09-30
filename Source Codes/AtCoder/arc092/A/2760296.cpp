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
 
 6/30/2018
 
 13:11-13:20 AC by matching
 
 Editorials:
  - https://img.atcoder.jp/arc092/editorial.pdf
  -
  - http://hamayanhamayan.hatenablog.jp/entry/2018/03/18/085108
   - matching
  - http://kazune-lab.net/contest/2018/03/17/arc092/
   - sort & greedy
 
 Key:
  - matching or sweep line (greedy)
 
 Summary:
  - Matching solution is straightforward
  - I couldn't solve by sweep line ?
   - fixing one dimension in ascendent order is very typical approach ?
 
 */
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=101;
int N;
int A[MAX_N],B[MAX_N],C[MAX_N],D[MAX_N];
const int MAX_V=1e4;
class MaxBipartiteMatching {
public:
  MaxBipartiteMatching(int V) : V(V) {}
  
  void addEdge(int u, int v) {
    assert(u<V&&v<V);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  
  int solve() {
    int res=0;
    memset(match, -1, sizeof(match));
    for(int u=0; u<V; ++u) if(match[u]<0) {
      memset(viz,0,sizeof viz);
      res+=dfs(u);
    }
    
    return res;
  }
private:
  int V;
  vector<int> E[MAX_V];
  int match[MAX_V];
  bool viz[MAX_V];
  
  // find augmenting path in residual network
  bool dfs(int u) {
    viz[u]=true;
    for(auto v : E[u]) {
      int w=match[v];
      if(w<0||(!viz[w]&&dfs(w))) {
        match[v]=u;
        match[u]=v;
        return true;
      }
    }
    return false;
  }
};

void solve_matching() {
  MaxBipartiteMatching M(2*N);
  REP(i,N)REP(j,N) if(A[i]<C[j]&&B[i]<D[j]) {
    M.addEdge(i,N+j);
  }
  cout<<M.solve()<<endl;
}

void solve() {
  set<int> S;
  // x,y,color
  vector<tuple<int,int,int>> X;
  REP(i,N) X.emplace_back(A[i],B[i],0);
  REP(i,N) X.emplace_back(C[i],D[i],1);
  sort(X.begin(),X.end());
  int res=0;
  REP(i,2*N) {
    int x,y,c;
    tie(x,y,c)=X[i];
    if(c==0) S.emplace(y);
    else {
      auto it=S.lower_bound(y);
      if(it==S.begin()) continue;
      --it;
      ++res;
      S.erase(it);
    }
  }
  
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>A[i]>>B[i];
  REP(i,N) cin>>C[i]>>D[i];
  solve();
  return 0;
}