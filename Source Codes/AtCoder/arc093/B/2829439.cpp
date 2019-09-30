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
 
 7/12/2018
 
 12:05-12:23,12:42-13:42 give up
 15:45-16:00 add solution
 
 Key:
  - Very large board => No need to paint optimally
  - No checkboard!!!
 
 Summary:
  - Start analysis from check board => death ?
   - https://twitter.com/eiya5498513/status/977905602222374913
  - I had a plan to put floating one block. However I didn't have idea to paint black/white firstly ?
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
// 12:05-12:23,12:42-13:42 give up
const int MAX_N=100+1;
int A,B;
int G[MAX_N][MAX_N]={};
void solve_wrong() {
  ZERO(G);
  int a=A,b=B;
  if(a<b) swap(a,b);
  if(a>=2*b) {
    REP(i,50) {
      dump3(i,a,b);
      if(b>1) assert(a>=b);
      int i1=2*i,i2=i1+1;
      REP(j,50) {
        int j1=2*j,j2=j1+1;
        if(a>0) G[i1][j1]=1,--a;
        if(b>1) G[i2][j2]=1,--b,--a;
      }
    }
  } else {
    
  }
  REP(i,100) {
    REP(j,100) cout<<G[i][j];
    cout<<endl;
  }
}

void solve() {
  ZERO(G);
  REP(i,100) REP(j,100) G[i][j]=j>=50?0:1;
  --A,--B;
  REP(k,50) REP(l,24) {
    int i=2*k+1,j=2*l+1;
    if(A) G[i][j]=0,--A;
  }
  REP(k,50) REP(l,24) {
    int i=2*k+1,j=50+2*l+1;
    if(B) G[i][j]=1,--B;
  }

  cout<<100<<' '<<100<<endl;
  REP(i,100) {
    REP(j,100) cout<<(G[i][j]?'#':'.');
    cout<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>A>>B;
  solve();
  return 0;
}