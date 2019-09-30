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
 
 8/6/2018
 
 16:32-17:00 pause
 18:20-18:50 give up
 
 21:00-22:40 read editorials and got ACC
 
 Editorials:
  - https://atcoder.jp/img/arc067/editorial.pdf
  - https://youtu.be/geZKa28g93o?t=1168
  - https://www.hamayanhamayan.com/entry/2018/05/06/110926
  - https://31536000.hatenablog.com/entry/2018/05/06/024450
  - http://kazune-lab.net/contest/2018/05/05/abc096/#d---five-five-everywhere
 
 Tweets:
  - https://togetter.com/li/1224581
  - https://twitter.com/pazzle1230/status/992760912376348674
  - https://twitter.com/_olphe/status/992761057398566913
  - https://twitter.com/satanic0258/status/992761100725698561
  - https://twitter.com/naoppy_ac/status/992761290002083841
  - https://twitter.com/drken1215/status/992761384764030977
  - https://twitter.com/dsytk7/status/992761694752403456
 
 In the construction problem, typically finding reasonable strategy in affordable complexity is necessary. No need to be optimal.
 I seeked for strategy which leverages parity of the sum of any 5 elements or parity of total of `N` elements.
 If parity is a key, representing number as `2*k+1` may not be clear. Thus I just use `odd`/`even`.
 However it didn't work because `2` may not be part of selected 5 elements. All the odd prime numbers did not work either.
 
 I needed to EXTEND this idea. So parity doesn't work. Now we can look at 3*k+r (0<r<3) or 4*k+r (0<r<3)..
 It's time to use p*k+r representation to step into other mod world.
 
 1) 3*k+1 => sum = 3*?k+5 cannot guarantee composit number ?
 2) 3*k+2 => 3*?k+10 ?
 3) 4*k+1 => 4*?k+5 ?
 4) 4*k+2 => this is not prime number for k>0 ?
 
 Now we may find out that sum of 5*k+1 is surely divisible by `5`
 
 x) 5*k+1 => 5*(?k+1) ?
 
 Key:
  - Composite number <=> Divisible by x>=2 <=> 0 (mod x)
 
 Summary:
  - I tried to solve with parity. However no luck ????????
  - Parity is just one of (mod x). Look at other mod numbers if you cannot move forward ????????????????
  - Or experiment in small Ns
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
//const int MAX_N=55+1;
int N;
const int MAX_P=55555;
int P[MAX_P+1];
void solve() {
  REPE(n,MAX_P)P[n]=true;
  P[0]=P[1]=false;
  VI res;
  for(int p=2; p*p<=MAX_P; ++p) if(P[p]) {
    for(int q=p*p; q<=MAX_P; q+=p) P[q]=false;
  }
  REPE(p,MAX_P)if(SZ(res)<N&&P[p]&&p%5==4) res.push_back(p);
  REP(i,N)cout<<res[i]<<(i==N-1?'\n':' ');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  solve();
  return 0;
}