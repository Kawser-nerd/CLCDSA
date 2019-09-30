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
 
 8/8/2018
 
 16:36-17:36 give up
 19:15-21:30 read editorials and got AC (I spent 1 hour to resolve precision error. WHY precision 8 is needed?)
 
 Editorials:
  - https://img.atcoder.jp/abc076/editorial.pdf
  - https://youtu.be/T1zXzsoK268?t=1804
  - simulation
   - http://ferin-tech.hatenablog.com/entry/2017/10/28/231616
   - http://www.neetaro.com/entry/atcoder-beginner-contest-abc-076
   - http://kazune-lab.net/contest/2017/10/28/abc076/
  - dp
   - https://www.hamayanhamayan.com/entry/2017/10/28/230944
   - https://kimiyuki.net/writeup/algo/atcoder/abc-076-d/
   - http://hamko.hatenadiary.jp/entry/2017/10/28/224055
 
 I tried to compute possible range of velocity at T[i].
 However actually total time is upper-bounded by 2*10^4.
 It's possible to calculate area by "manual integral".
 Also velocity should satisfy limit which is coming from both-ends.
 We need to calculate it in both ways.
 
 Key:
  - T is small. We can manually compute integral by simulation
  -
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
//const int MAX_N=2*100*200+1;
const int MAX_N=1e6+10;
int N;
int V[100],T[100];
int v[MAX_N];
void solve() {
  REPE(i,MAX_N) v[i]=1e8;
  int t=0;
  v[0]=0;
  REP(i,N) {
    int vv=V[i];
    int du=T[i];
    SMIN(v[t],vv);
    REP(_,du) ++t,SMIN(v[t],vv);
//    cout<<i<<","<<t<<endl;
  }
  SMIN(v[t],0);
  int T=t;
  FORE(i,1,T) {
//    if(i==140)cout<<v[i]<<","<<v[i-1]+1<<endl;
    SMIN(v[i],v[i-1]+1);
  }
  for(int i=T-1; i>=0; --i) {
//    if(i==140)cout<<v[i]<<","<<v[i+1]+1<<endl;
    SMIN(v[i],v[i+1]+1);
  }
//  cout<<T<<endl;
//  REPE(i,T) cout<<i<<","<<v[i]<<endl;
  LL res=0;
  //REP(i,T) res+=(v[i]+v[i+1])*0.5;
  REP(i,T) res+=(v[i]+v[i+1]);
  double ans=res*0.125;
  cout<<setprecision(12)<<ans<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>T[i],T[i]*=2;
  REP(i,N) cin>>V[i],V[i]*=2;
  solve();
  return 0;
}