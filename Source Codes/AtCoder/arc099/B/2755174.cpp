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
 
 6/23/2018
 
 21:20-22:40 Time is up
 
 6/29/2018
 
 10:00- Read editorials
 
 Editorials:
  - https://img.atcoder.jp/arc099/editorial.pdf
  - https://youtu.be/aTMRqHCZHaA?t=1582
  - http://drken1215.hatenablog.com/entry/2018/06/24/010600
  - http://hamko.hatenadiary.jp/entry/2018/06/23/233924
 
 Tweets:
  - https://togetter.com/li/1240118
  - https://twitter.com/evima0/status/1010519753910149120
  - https://twitter.com/kroton_pc/status/1010554549315047425
  - https://twitter.com/chokudai/status/1010526972982714368
  - https://twitter.com/kirika_comp/status/1010526986286972928
  - https://twitter.com/tanakh/status/1010521774679678978
  - https://twitter.com/beet_aizu/status/1010517902158487552
  - https://twitter.com/rickytheta/status/1010518108178542592
  - https://twitter.com/kirika_comp/status/1010518739333234688
  - https://twitter.com/satanic0258/status/1010518809399083008
   - LIS
  - https://twitter.com/_TTJR_/status/1010518888969166848
  - https://twitter.com/hamko_intel/status/1010518895038361600
  - https://twitter.com/btk15049/status/1010519832050069505
  - https://twitter.com/tanakh/status/1010520182706466816
 
 Key:
  - Solve f(n) = x s.t. x/S(x) is minimal in x>=n
  - Candidate of f(n) is abcdef?99999 (try ? in all columns)
 
 Summary:
  - My simple guess was wrong. I couldn't solve by myself ?
  -
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
int K;
set<LL> S;
// 21:56 1WA

int ds(LL x) {
  int res=0;
  while(x>0) res+=x%10,x/=10;
  return res;
}

LL f(LL n) {
  long double mi=1e15; LL res=-1;
  LL P10[17]; P10[0]=1LL;
  REP(i,16) P10[i+1]=P10[i]*10;
  REPE(i,16) {
    LL x=n/P10[i];
    if(x==0) continue;
    int d=n%10;
    FOR(j,d,10) {
      LL y=(x/10LL*10LL+j)*P10[i]+(P10[i]-1);
//      dump4(n,i,j,y);
      if(y<n) continue;
      int sy=ds(y);
      long double fy=1.0*y/sy;
      if(fy<mi) res=y,mi=fy;
    }
    /*
    FORE(d,1,11) {
      LL x=1LL*d*P10[i]-1;
//      dump2(x,n);
      if(x<n) continue;
      int sx=ds(x);
      long double fx=1.0*x/sx;
//      dump3(x,n,fx);
      if(fx<mi) res=x,mi=fx;
    }*/
  }
  return res;
}

void solve() {
//  dump(f(8));
  LL n=0;
  REP(i,K) {
    n=f(n+1);
    cout<<n<<endl;
  }
}

void solve_wrong() {
  LL pow=1;
  REP(i,K) {
    LL a=(i%9)+2;
    if(i%9==0&&i!=0) pow*=10LL;
//    dump3(a,pow,a*pow-1);
    LL res=a*pow-1;
    S.emplace(res);
    dump2(res,ds(res));
    assert(ds(res)==i+1);
//    cout<<res<<endl;
  }
}

void test() {
  vector<pair<long double,int>> X;
  FORE(n,1,1e3) {
    long double a=1.0*n/ds(n);
    X.emplace_back(a,n);
  }
  sort(X.begin(),X.end());
  REP(i,SZ(X)) dump2(X[i].second,X[i].first);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>K;
//  assert(K<=170);
  solve();
//  test();
  
  return 0;
}