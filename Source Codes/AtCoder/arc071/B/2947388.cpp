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
 
 8/4/2018
 
 13:30-14:30 give up
 14:30-16:30 read editorials
 
 I tried to count rectangles though, I couldn't move forward AT ALL.
 
 Editorials:
  - https://atcoder.jp/img/arc071/editorial.pdf
  - https://youtu.be/HAxMNuhoQ3E?t=1813
 
 2D -> 1D (independence). Fxck.
 N<=1e5, M<=1e5. That means we MUST solve something for `x` and `y` separtely. Fxck.
 
 Key:
  - N and M are large. Solve them independently in O(N)
  - Combine result of X and result of Y
  - ? {a*b : a?A, b?B } = ?{a?A}*?{b?B}
  - ? {x[j]-x[i] : i<j } = ? { (2*i-N+1)*x[i] : i=0..N-1 } = ? { (i+1)*(N-i-1)*L[i] : i=0..N-2 }
 
 Summary:
  - Narrow down analysis based on constraint
  - Independence of X and Y in Cartesian coordinate system is SOOOOOOOOOOOOOO typical
  -
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
int N,M;
LL X[MAX_N],Y[MAX_N];
const LL MOD=1e9+7;
LL f(vector<LL> ns) {
  LL res=0;
  int L=SZ(ns);
  REP(i,L) res+=((1LL*(i+1)*(L-i)%MOD)*ns[i])%MOD,res%=MOD;
  return res;
}
void solve_length() {
  vector<LL> A(N-1),B(M-1);
  REP(i,N-1) A[i]=X[i+1]-X[i];
  REP(i,M-1) B[i]=Y[i+1]-Y[i];
  LL res=f(A);
  res*=f(B),res%=MOD;
  cout<<res<<endl;
}

LL g(LL Z[MAX_N], int L) {
  LL res=0;
  REP(i,L) res+=1LL*(2LL*i-L+1)*Z[i]%MOD,res%=MOD;
  return res;
}

void solve() {
  LL res=g(X,N);
  res*=g(Y,M),res%=MOD;
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>M;
  REP(i,N) cin>>X[i];
  REP(i,M) cin>>Y[i];
  solve();
  return 0;
}