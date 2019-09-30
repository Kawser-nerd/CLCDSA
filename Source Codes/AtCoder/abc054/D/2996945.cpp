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
 
 8/11/2018
 
 16:10-16:15 analysis
 16:16-16:32 implement and got AC
 
 Editorials:
  - https://atcoder.jp/img/abc054/editorial.pdf
  - https://youtu.be/UFMvexj1hY4?t=3353
 
 Summary:
  - I haven't writtern knapsack dp for a while. It took some time to fix a bug.
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=40+1;
const int MAX_V=410;
int N,MA,MB;
int A[MAX_N],B[MAX_N],C[MAX_N];
int dp[MAX_N][MAX_V][MAX_V];
const int Inf=1e5;
LL gcd(LL a, LL b) { return b==0?a:gcd(b,a%b); }
void solve_dp1() {
  REPE(i,N)REP(a,MAX_V)REP(b,MAX_V)dp[i][a][b]=Inf;
  dp[0][0][0]=0;
  REP(i,N)REP(a,MAX_V)REP(b,MAX_V) {
    int va=A[i],vb=B[i],c=C[i];
    if(a+va<MAX_V&&b+vb<MAX_V)SMIN(dp[i+1][a+va][b+vb],dp[i][a][b]+c);
    SMIN(dp[i+1][a][b],dp[i][a][b]);
//    if(a+va==3&&b+vb==3) dump4(i,a,b,dp[i+1][a+va][b+vb]);
  }
  int res=Inf;
  REP(a,MAX_V)REP(b,MAX_V) {
    int g=gcd(a,b);
    if(g==0) continue;
//    dump3(a,b,g);
    int aa=a/g,bb=b/g;
    if(aa==MA&&bb==MB) SMIN(res,dp[N][a][b]);
  }
  cout<<(res>=Inf?-1:res)<<endl;
}

int dp2[MAX_V][MAX_V];
void solve() {
  REPE(i,N)REP(a,MAX_V)REP(b,MAX_V)dp2[a][b]=Inf;
  dp2[0][0]=0;
  REP(i,N)for(int a=MAX_V; a>=0; --a)for(int b=MAX_V; b>=0; --b) {
    int va=A[i],vb=B[i],c=C[i];
    if(a+va<MAX_V&&b+vb<MAX_V)SMIN(dp2[a+va][b+vb],dp2[a][b]+c);
    //    if(a+va==3&&b+vb==3) dump4(i,a,b,dp[i+1][a+va][b+vb]);
  }
  int res=Inf;
  REP(a,MAX_V)REP(b,MAX_V) {
    int g=gcd(a,b);
    if(g==0) continue;
    int aa=a/g,bb=b/g;
    if(aa==MA&&bb==MB) SMIN(res,dp2[a][b]);
  }
  cout<<(res>=Inf?-1:res)<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>MA>>MB;
  REP(i,N) cin>>A[i]>>B[i]>>C[i];
  solve();
  return 0;
}