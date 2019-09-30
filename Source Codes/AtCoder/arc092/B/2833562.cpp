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
 
 22:10-23:20 give up
 
 I tried to compute each bit from LSB to MSB. However I'm in stuck due to carry ?
  - https://twitter.com/kojingharang/status/975005026933288960
  - https://twitter.com/tanakh/status/975004849757503488
 
 7/13/2018
 
 14:45- Read editorials and add solution (3WA due to
 
 
 Hmmm this is really hard to reduce. There are two operations for A[i] and B[i].
  - summation
  - XOR
 
 I tried to expand (a+b)^(c+d)^... However it's hard to handle carry in less siginificant bits.
 
 https://twitter.com/rickytheta/status/975009343916490753 is showing detailed process of analysis.
 
 n[i-1..0] affects 2^i bit in summation.
 Find number of `b`s which ranges in [T-A[i],2T-A[i]) or [3T-A[i],4T-A[i])
 
 Editorials:
  - https://youtu.be/DqqPuIZvJTk?t=2463
  - https://img.atcoder.jp/arc092/editorial.pdf
  - http://kmjp.hatenablog.jp/entry/2018/03/20/0900
 
 Tweets:
  - https://twitter.com/rickytheta/status/975009343916490753
   - analysis flow
  - https://twitter.com/__math/status/975005610751111168
   - experiment
  - https://twitter.com/rickytheta/status/975004017540571137
  - https://twitter.com/konjo_p/status/975003916965355521
  - https://twitter.com/konjo_p/status/975004292082941953
 
 Key:
  - Fix A[i] and count number of ON bit in { A[i]+B[0], A[i]+B[1], .., A[i]+B[N-1] }
  - Leverage range of summation. k-th bit is ON when A[i]+B[j] ranges in [T,2T) or [3T,4T) where T=2^k
 
 Summary:
  - When I'm in stuck, I should try other approaches sooner
  - Moreover I should train sense to figure out current approach is feasible or not
  - Listing all possible approaches before digging the first idea may be useful for hard problem? ?
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
// 22:10-23:20 give up
const int MAX_N=2e5+1;
int N;
LL A[MAX_N],B[MAX_N];
void solve() {
  LL res=0;
  REP(k,31) {
    LL cnt=0;
    vector<LL> BB(N);
    LL mask=(1LL<<(k+1))-1;
    REP(i,N) BB[i]=B[i]&mask;
    sort(BB.begin(),BB.end());
    LL T=1LL<<k;
    REP(i,N) {
      LL a=A[i]&mask;
      REP(j,2) {
        auto r=lower_bound(BB.begin(),BB.end(),(2LL*j+2LL)*T-a),l=lower_bound(BB.begin(),BB.end(),(2LL*j+1LL)*T-a);
        cnt+=r-l;
      }
    }
    dump2(k,cnt);
    int x=(cnt%2==1);
    if(x) res|=1<<k;
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>A[i];
  REP(i,N) cin>>B[i];
  solve();
  return 0;
}