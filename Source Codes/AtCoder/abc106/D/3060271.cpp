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
 
 8/22/2018
 
 21:56-22:16 analysis
 22:28 1WA
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=5e2+1;
const int MAX_M=2e5+1;
int N,M,Q;
int L[MAX_M],R[MAX_M];
int P1[MAX_M],P2[MAX_M];
LL mx[MAX_N][MAX_N];
void solve() {
  ZERO(mx);
  REP(i,M) {
    int l=L[i],r=R[i];
    mx[0][r]+=1,mx[0][N]-=1,mx[l+1][r]-=1,mx[l+1][N]+=1;
  }
  
  /*
  REPE(i,N) {
    REPE(j,N) cout<<mx[i][j]<<" ";
    cout<<endl;
  }*/
  
  REPE(i,N) REP(j,N) mx[i][j+1]+=mx[i][j];
  REPE(j,N) REP(i,N) mx[i+1][j]+=mx[i][j];
  /*
  REPE(i,N) {
    REPE(j,N) cout<<mx[i][j]<<" ";
    cout<<endl;
  }*/
  
  REP(i,Q) {
    int l=P1[i],r=P2[i];
    cout<<mx[l][r]<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>M>>Q;
  REP(i,M) {
    cin>>L[i]>>R[i];
    L[i]--,R[i]--;
  }
  REP(i,Q) {
    cin>>P1[i]>>P2[i];
    P1[i]--,P2[i]--;
  }
  solve();
  return 0;
}