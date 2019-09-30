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

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
// 17:15-
const int MAX_M=2e5+1,MAX_N=1e5+1;
int N,M;
const string yes="Yes",no="No";
int L[MAX_M],R[MAX_M];
LL D[MAX_M];
unordered_map<int,LL> IN[MAX_N],OUT[MAX_N];
LL dist[MAX_N];
bool solve() {
  MINUS(dist);
  REP(i,M) {
    int u=L[i],v=R[i];
    LL d=D[i];
    OUT[u][v]=d,IN[v][u]=d;
  }
  
  queue<int> Q;
  REP(i,N) if(IN[i].empty()&&SZ(OUT[i])) Q.emplace(i),dist[i]=0;
  while(SZ(Q)) {
    int u=Q.front(); Q.pop();
    FORR(kvp,OUT[u]) {
      int v=kvp.first; LL d=kvp.second;
      LL d2=dist[u]+d;
      if(dist[v]!=-1&&d2!=dist[v]) return false;
      dist[v]=d2;
      IN[v].erase(u);
      if(IN[v].empty()) Q.push(v);
    }
  }
  REP(i,N) if(SZ(IN[i])) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>M;
  REP(i,M) cin>>L[i]>>R[i]>>D[i];
  string res=solve()?yes:no;
  cout<<res<<endl;
  return 0;
}