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
 
 26:30-27:20 RE in sample 1 :(
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
pair<LL,int> X[MAX_N],Y[MAX_N];
int N;

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

LL solve() {
  sort(X,X+N),sort(Y,Y+N);
//  dump(N);
  vector<tuple<LL,int,int>> XX,YY;
  REP(i,N-1) {
    XX.emplace_back(X[i+1].first-X[i].first,X[i+1].second,X[i].second);
    YY.emplace_back(Y[i+1].first-Y[i].first,Y[i+1].second,Y[i].second);
//    dump4(i,get<0>(XX[i]),get<1>(XX[i]),get<2>(XX[i]));
//    dump4(i,get<0>(YY[i]),get<1>(YY[i]),get<2>(YY[i]));
  }
  sort(XX.begin(),XX.end()),sort(YY.begin(),YY.end());
//  dump(SZ(XX));
  
  LL res=0;
  UF uf(N+1);
  int i=0,j=0;
  while(i<N-1||j<N-1) {
    tuple<LL,int,int> a={-1,-1,-1};
    if(i>=N-1) a=YY[j++];
    else if(j>=N-1) a=XX[i++];
    else {
      if(XX[i]<YY[j]) a=XX[i++];
      else a=YY[j++];
    }
    LL d; int u,v; tie(d,u,v)=a;
    assert(d!=-1);
//    dump2(i,j);
//    dump3(d,u,v);
    if(uf.same(u,v)) continue;
    res+=d;
    uf.unite(u,v);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) {
    int x,y;
    cin>>x>>y;
    X[i]={x,i},Y[i]={y,i};
  }
  cout<<solve()<<endl;
  
  return 0;
}