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
// 16:08-
const string P1="Fennec",P2="Snuke";
const int MAX_N=1e5+1;
int N;
VI E[MAX_N];
int C[MAX_N];

VI P;
void dfs(int u, int pre, VI &cur) {
  cur.push_back(u);
  if(u==N) {
    P=cur;
    return;
  }
  FORR(v,E[u]) if(v!=pre) {
    dfs(v,u,cur);
  }
  cur.pop_back();
}
void dfs2(int u, int c) {
  FORR(v,E[u]) if(C[v]==0) {
    dump2(v,c);
    C[v]=c;
    dfs2(v,c);
  }
}

void solve() {
  VI p={};
  dfs(1,-1,p);
  dumpAR(P);
  assert(SZ(P));
  ZERO(C);
  int l=0,r=SZ(P)-1;
  VI Q1,Q2;
  while(l<r) {
    Q1.push_back(P[l]),Q2.push_back(P[r]);
    C[P[l++]]=1,C[P[r--]]=2;
  }
  dump2(C[P.front()],C[P.back()]);
  dumpAR(Q1);
  dumpAR(Q2);
  FORR(u,Q1) dfs2(u,1);
  FORR(u,Q2) dfs2(u,2);
  
  int cnt[3]={};
  REPE(i,N) cnt[C[i]]++;
  dump2(cnt[1],cnt[2]);
  string res=cnt[1]>cnt[2]?P1:P2;
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  REPE(i,N) E[i].clear();

  cin>>N;
  REP(i,N-1) {
    int u,v;
    cin>>u>>v;
    E[u].push_back(v),E[v].push_back(u);
  }
  solve();
  return 0;
}