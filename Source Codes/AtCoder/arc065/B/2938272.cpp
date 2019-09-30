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
 
 8/2/2018
 
 25:30-25:15 give up
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_V=2e5+1;
int V,K,L;

struct UF {
public:
  int groupNum;
  UF(int N) {
    uf=vector<int>(N);
    rank=vector<int>(N);
    for(int i=0; i<N; ++i) uf[i]=i,rank[i]=0;
    groupNum=N;
  }
  
  int find(int i) {
    return uf[i]==i?i:uf[i]=find(uf[i]);
  }
  
  bool same(int x, int y) {
    return find(x)==find(y);
  }
  
  void unite(int x, int y) {
    x=find(x);
    y=find(y);
    if(x==y) return;
    groupNum--;
    
    if (rank[x]==rank[y]) {
      uf[x]=y;
      rank[y]++;
      return;
    }
    
    if (rank[x]<rank[y]) {
      uf[x]=y;
    } else {
      uf[y] =x;
      if(rank[x]==rank[y]) ++rank[x];
    }
  }
private:
  vector<int> rank;
  vector<int> uf;
};

vector<UF> uf(2,UF(MAX_V));

void solve() {
  map<II,int> M;
  REP(i,V) M[{uf[0].find(i),uf[1].find(i)}]++;
  REP(i,V) cout<<M[{uf[0].find(i),uf[1].find(i)}]<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>V>>K>>L;
  int A[2]={K,L};
  REP(i,2) REP(_,A[i]) {
    int u,v; cin>>u>>v;
    --u,--v;
    uf[i].unite(u,v);
  }
  solve();
  
  return 0;
}