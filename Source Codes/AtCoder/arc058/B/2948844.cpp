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
 
 23:30-23:56 TLE on sample #4 locally
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=2e5+1;
int H,W,A,B;
const LL MOD=1e9+7;

LL fact[MAX_N],factinv[MAX_N],inv[MAX_N];
LL powmod(LL a, LL b) {
  assert(0<=a && a<MOD);
  assert(0<=b);
  
  LL res=1;
  for(LL mask=1; mask<=b; mask<<=1) {
    if(b&mask) res*=a, res%=MOD;
    a*=a; a%=MOD;
  }
  return res;
}
LL modinv(LL a, LL p=MOD) {
  return powmod(a, p-2);
}
// broken
LL choose(int n, int r) {
  if(n<r) return 0;
  r = min(n-r,r);
//  dump3(n,n-r,r);
//  dump3(fact[n],factinv[n-r],factinv[r]);
  LL a=(fact[n]*factinv[n-r])%MOD;
  LL res=(a*factinv[r])%MOD;
  return res;
}

LL f(int r1, int c1, int r2, int c2) {
  int dr=r2-r1,dc=c2-c1;
  return choose(dr+dc,dr);
  //return choose_factmod(dr+dc,dr);
}

void solve() {
  LL res=0;
  
  fact[0]=1,factinv[0]=1;
  FOR(i,1,MAX_N) fact[i]=fact[i-1]*i%MOD,factinv[i]=modinv(fact[i]);
  
  FOR(c,B,W) {
    int r=H-A-1;
    LL x=f(0,0,r,c),y=r<H-1?f(r+1,c,H-1,W-1):0LL;
    x*=y,x%=MOD;
    res+=x,res%=MOD;
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>H>>W>>A>>B;
  solve();
  return 0;
}