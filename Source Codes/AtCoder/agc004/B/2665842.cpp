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
 
 6/14/2018
 
 12:40-13:27 1WA
 13:28-13:50 pause
 
 Editorials:
  - https://youtu.be/LMfovZuqBsg?t=985
 
 Summary:
  - X*dold+A[P[i]] vs A[P[i]] ?
 
 */

// $ g++ -std=c++11 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=2e3+1;
int N,X;
LL A[MAX_N];
LL P[MAX_N];
const LL Inf=1e15;
int f(int from, int to) {
//  return (to-from+N)%N;
  return from<=to?to-from:N-(from-to);
}
void solve() {
  LL res=Inf;
  REP(i,N) P[i]=i;
  REP(d,N) {
    LL tot=0;
    REP(i,N) {
      LL dold=f(P[i],i);
      LL p=(i-d+N)%N;
//      LL a=1LL*X*dold+A[P[i]],b=1LL*X*d+A[p];
//      dump4(d,i,a,b);
      if(A[P[i]]>A[p]) P[i]=p;
      tot+=A[P[i]];
    }
//    dump3(d,tot,res);
    SMIN(res,tot+X*d);
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>X;
  REP(i,N) cin>>A[i];
  solve();
  return 0;
}