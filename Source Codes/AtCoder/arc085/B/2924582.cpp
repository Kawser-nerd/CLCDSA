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
 
 7/29/2018
 
 22:55-23:10, 24:25-24:36 AC
 
 Editorials:
  - https://img.atcoder.jp/arc085/editorial.pdf
  - http://hamayanhamayan.hatenablog.jp/entry/2017/11/11/225532
 
 Tweets:
  - https://togetter.com/li/1170503
  - dp
   - https://twitter.com/rickytheta/status/929343099712634880
   - https://twitter.com/drken1215/status/929343249830965248
   - https://twitter.com/catupper/status/929343524130119680
   - https://twitter.com/satanic0258/status/929343687854776320
   - https://twitter.com/Yazaten/status/929343748227481600
   - https://twitter.com/kojingharang/status/929343754183499776
   - https://twitter.com/kuuso1/status/929343848123215873
   - https://twitter.com/merom686/status/929344087685136384
   - https://twitter.com/HIR180/status/929346827484241920
  - O(1) math
   - https://twitter.com/beet_aizu/status/929343085988823041
   - https://twitter.com/beet_aizu/status/929343374565425153
   - https://twitter.com/fmhr__/status/929344112502890497
   - https://twitter.com/DEGwer3456/status/929344759688134657
   - https://twitter.com/tatuyan_edson/status/929347292171190272
   - https://twitter.com/DEGwer3456/status/929347707642175488
   - https://twitter.com/u2xr_/status/929348046093029381
 
 http://nozomi.2ch.sc/test/read.cgi/prog/1505047495/
 
 698 ?????????2017/11/12(?) 00:51:36.26 .net
 >>694
 Y??????????Y???????????1??????????????abs(a[N-1]-a[N])??????????????
 Y????????????????abs(a[N-1]-a[N])??????
 ????X??????????????1???????????abs(a[N-1]-a[N])????????
 
 699 ?????????2017/11/12(?) 00:51:38.64 .net
 >>694
 Y????????? |a_{N-1}-a_N| ?????????????????
 ???????X??? |a_{N-1}-a_N| ???????????????? N-1 ???????????????
 Y??????????????????????????????
 
 --
 
 X is the first person to make a choice. Now X has three options:
 1. take all              => |A[N-1]-W|
 2. take all but the last => |A[N-1]-A[N-2]|
 3. take before A[N-2]
 
 If X takes #3, Y can select |A[N-1]-A[N-2]|.
 Y chooses optimally. Result score of Y's choice should be at most |A[N-1]-A[N-2]|.
 If |A[N-1]-A[N-2]| is smallest, Y chooses it.
 Otherwise, Y may choose different one.
 
 However X can block it by taking choice #1 or #2.
 X behaves optimally too. max { |A[N-1]-W|, |A[N-1]-A[N-2]| } is the result if N>1.
 
 Summary:
  - I solved by dp
  - O(1) solution is so smart ?
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=2000+1;
int N;
LL Z,W;
LL A[MAX_N];
LL memo[MAX_N][2];

LL f(int s, int p) {
  LL &res=memo[s][p];
  if(res>=0) return res;
  int s2=s==0?W:A[s-1];
  res=abs(A[N-1]-s2);
  FOR(i,s,N-1) {
    if(p==0) SMAX(res,f(i+1,p^1));
    else SMIN(res,f(i+1,p^1));
  }
  return res;
}
void solve_org() {
  MINUS(memo);
  LL res=f(0,0);
  cout<<res<<endl;
}

void solve() {
  LL res=abs(A[N-1]-W);
  if(N>1) SMAX(res,abs(A[N-1]-A[N-2]));
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>Z>>W;
  REP(i,N) cin>>A[i];
  solve();
  return 0;
}