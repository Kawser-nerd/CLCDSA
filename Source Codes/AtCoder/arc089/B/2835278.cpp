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
 
 7/13/2018
 
 16:35-17:00, 18:10-18:30 give up
 18:30-19:05 read editorials
 19:05-19:47 1WA
 
 Editorials:
  -
 
 Key:
  - K is cyclic => modular arithmetic
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
// 16:35-17:00, 18:10-18:30 give up
const int MAX_K=1e3+1;
int N,K;
int G[2][2*MAX_K][2*MAX_K]={};
int cum[2][2*MAX_K][2*MAX_K]={};
int f(int i1, int j1, int i2, int j2, int c) {
  int res=cum[c][i2][j2]-cum[c][i2][j1]-cum[c][i1][j2]+cum[c][i1][j1];
  if(res<0) {
    dump4(i1,j1,i2,j2);
    dump4(cum[c][i2][j2],cum[c][i2][j1],cum[c][i1][j2],cum[c][i1][j1]);
    dump2(c,res);
  }
  assert(res>=0);
  return res;
}

void solve() {
  int KK=2*K;
//  REP(i,KK)REP(j,KK) dump3(i,j,G[1][i][j]);
  REP(c,2)REP(i,KK)REP(j,KK) {
    cum[c][i+1][j+1]=cum[c][i+1][j]+cum[c][i][j+1]+G[c][i][j]-cum[c][i][j];
//    dump4(i,j,c,cum[c][i+1][j+1]);
  }
  int res=0;
  REP(i,K)REP(j,K) REP(c,2) {
    int c1=c,c2=c^1;
    int w=f(0,0,i,j,c1)+f(i,j,i+K,j+K,c1)+f(i+K,j+K,KK,KK,c1)+f(i+K,0,KK,j,c1)+f(0,j+K,i,KK,c1);
    int b=f(0,j,i,j+K,c2)+f(i,0,i+K,j,c2)+f(i,j+K,i+K,KK,c2)+f(i+K,j,KK,j+K,c2);
//    dump4(i,j,w,b);
    SMAX(res,w+b);
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ZERO(G),ZERO(cum);
  cin>>N>>K;
  REP(i,N) {
    int x,y; char c;
    cin>>x>>y>>c;
    G[c=='B'][x%(2*K)][y%(2*K)]++;
  }
  solve();
  return 0;
}