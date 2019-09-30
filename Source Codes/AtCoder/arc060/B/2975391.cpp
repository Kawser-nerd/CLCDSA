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
 
 15:50-16:20 give up
 23:10- read editorials and add solution (1WA)
 
 f(b,N) gradually increases. However it's not monotonical.
 I guessed that there is a good way to narrow down search scope.
 However I had no luck to find it.
 
 Editorials:
  - http://arc060.contest.atcoder.jp/data/arc/060/editorial.pdf
  - https://www.youtube.com/watch?v=LzxPxJ-cSHk
 
 Basic idea is brute-force. Let's see how modular arithmetic of large `b` behaves.
 We are "dividing" N by `b`. If `b` >= ?N, the division can happen ONLY ONCE.
 Then..
 
  N = b*p + q (p<=b and 0<=q<b) ... (1)
 
 Also S = p + q ... (2) holds.
 
 (1)-(2) <=> N - S = p * (b - 1)
 
 such (p,b) can be found by searching divisors with trial division in O(?N).
 
 Now we can resolve b in [?N..N].
 It's possible to check `s` of `b` in 2..?N(?10^6) with O(?N*lg N) just by brute-force.
 
 Key:
  - Find all valid `b` which satisfies f(b,n)=s
  - `b` in [?N..N] produces at most two digits. It's reduced to divisor enumeration
 
 Summary:
  - Hmmm solution of this problem is cracily smart
  - O(?N) approach is very typical when division is related
  - Dividing by large number reduces large search space when division is part of operations
  - Taste of number seems to be very important
   - If I can figure out that number of digits gets smaller for larger number, this solution may come up with
   - I should train the "taste" more by playing around examples
  - Brute-force is basic approach.
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const LL Inf=1e12;
LL N,S;

LL f(LL b, LL n) {
//  dump2(b,n);
  return n<b?n:f(b,n/b)+n%b;
}

bool ok(LL b, LL p) {
  if(p>=b) return false;
  LL q=N-b*p;
  if(q<0||q>=b) return false;
  if(p+q!=S) return false;
  return true;
}

LL solve() {
  for(LL b=2; b*b<=N; ++b) if(f(b,N)==S) {
    return b;
  }
  LL M=N-S;
  if(M==0) return N+1;
  if(M<0) return -1;
  LL res=Inf;
  for(LL x=1; x*x<=M; ++x) if(M%x==0) {
    LL y=M/x;
//    dump2(x,y);
    if(ok(y+1,x)) SMIN(res,y+1);
    if(ok(x+1,y)) SMIN(res,x+1);
  }
  return res==Inf?-1:res;
}

LL g(LL b, LL n, VI &X) {
  LL d=n%b;
  X.push_back(d);
  return n<b?n:g(b,n/b,X)+n%b;
}

void test() {
  FORE(i,2,100) {
    VI X;
    dump2(i,g(i,5000,X));
    dumpAR(X);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
//  VI X;
//  dump(g(3,9,X));
//  dumpAR(X);
  //test();
  
  cin>>N>>S;
  cout<<solve()<<endl;
  return 0;
}