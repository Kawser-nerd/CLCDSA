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

 6/23/2018 ARC099
 
 21:00-21:17 ACC
 
 Editorials:
  - https://img.atcoder.jp/arc099/editorial.pdf
  - https://youtu.be/aTMRqHCZHaA?t=1265
  - http://drken1215.hatenablog.com/entry/2018/06/24/003500
  - http://hamko.hatenadiary.jp/entry/2018/06/23/232445

 Tweets:
  - https://togetter.com/li/1240118
  - https://twitter.com/satanic0258/status/1010518785072091136
  - https://twitter.com/evima0/status/1010519641666404353
  - https://twitter.com/tanakh/status/1010520181586608128
  - https://twitter.com/beet_aizu/status/1010517902158487552
  - https://twitter.com/btk15049/status/1010518530146496512
  - https://twitter.com/hagyu_aya/status/1010518079690792960
  - https://twitter.com/rickytheta/status/1010518108178542592
  - https://twitter.com/_TTJR_/status/1010518888969166848
  - https://twitter.com/hamko_intel/status/1010518895038361600
 
*/

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
// 9:17 AC
const int MAX_N=1e5+1;
LL A[MAX_N];
int N,K;

void solve_org() {
  int res=N;
  int p=-1;
  REP(i,N) if(A[i]==1) p=i;
  assert(p!=-1);
  
  FOR(i,p-K,p) {
    int l=max(0,i+1),r=max(0,N-(i+K)-1);
    int a=(l+K-2)/(K-1),b=(r+K-2)/(K-1);
    SMIN(res,a+b+1);
  }
  cout<<res<<endl;
}

void solve() {
  int res=(N-1+K-2)/(K-1);
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>K;
  REP(i,N) cin>>A[i];
  solve();
  
  return 0;
}