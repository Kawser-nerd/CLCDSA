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
 
 7/14/2018 AGC026
 
 21:10-23:00 time is up
 
 7/17/2018
 
 13:00-14:30, 22:00-23:00 read editorials
 
 7/18/2018
 
 9:45-
 
 Editorials:
  - https://img.atcoder.jp/agc026/editorial.pdf
  - https://www.youtube.com/watch?v=eB0eT-948Vw
  - http://betrue12.hateblo.jp/entry/2018/07/15/010448
  - http://kmjp.hatenablog.jp/entry/2018/07/16/0900_1
  - https://babcs2035.hateblo.jp/entry/2018/07/16/145823
  - http://hamko.hatenadiary.jp/entry/2018/07/15/015830
  - https://31536000.hatenablog.com/entry/2018/07/15/032932
  - http://ftb73.hatenablog.com/entry/2018/07/15/015322
  - http://kazune-lab.net/contest/2018/07/14/agc026/
   - solution with pure math
 
 Tweets:
  - https://togetter.com/li/1246851
  - https://twitter.com/kuuso1/status/1018141969594269698
  - https://twitter.com/_primenumber/status/1018142371639259136
  - https://twitter.com/threecourse/status/1018142424797872129
  - https://twitter.com/0x19f/status/1018143357292326912
  - https://twitter.com/tanakh/status/1018144318329008129
  - https://twitter.com/satanic0258/status/1018140826755448832
  - https://twitter.com/satanic0258/status/1018394273165688833
  - https://twitter.com/koyumeishi_/status/1018141526788960257
  - https://twitter.com/osrehun/status/1018141669919580160
  - https://twitter.com/furuya1223/status/1018141695081234435
  - https://twitter.com/tanakh/status/1018141771333685249
  - GCD is unevitable
   - https://twitter.com/ei1333/status/1018149060996263937
   - https://twitter.com/tempura_pp/status/1018149731715825664
   - https://twitter.com/ei1333/status/1018141131383554048
 
 I was only looking at a case where x>>C.
 x-B -> x-2*B -> x-3*B -> ... until x>C
 
 It's not general enough.
 There is a case where x<<C.
 x+D-B -> x+2*(D-B) -> ... until x<=C
 
 Keep adding/subtracting B => x (mod B) makes groups
 
 Bezout’s identity
  - https://mathtrain.jp/axbyc
  - https://ja.wikipedia.org/wiki/%E3%83%99%E3%82%BA%E3%83%BC%E3%81%AE%E7%AD%89%E5%BC%8F
 
 Key:
  - Keep adding/subtracting `x` => Group by `mod` x
  -
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_T=300+1;
int T;
LL A[MAX_T],B[MAX_T],C[MAX_T],D[MAX_T];
const string yes="Yes",no="No";
unordered_set<LL> S;
string f(LL x, LL B, LL C, LL D, int c) {
  if(S.count(x)) return yes;
  S.emplace(x);
  dump4(x,B,C,D);
  if(x<B) return no;
  LL p=max((x-C-1)/B,0LL);
  LL y=x-B*p;
  if(y<B) return no;
  y=x-B*(p+1);
  assert(y<=C);
  y+=D;
  if(x==y) return yes;
  return f(y,B,C,D,c+1);
//  return "*";
}

string solve_tle(LL A, LL B, LL C, LL D) {
  S.clear();
  if(A<B) return no;
  if(D<B) return no;
  if(B<=C) return yes;
  return f(A,B,C,D,0);
}

LL gcd(LL a, LL b) { return b==0?a:gcd(b,a%b); }

string solve(LL A, LL B, LL C, LL D) {
  if(A<B) return no;
  if(D<B) return no;
  if(B<=C) return yes;
  
//  dump4(A,B,C,D);
  LL g=gcd(B,D);
  LL k=(C-A)/g;
  LL p=1e18+1;
  FORE(d,-1,1) {
    LL kk=k+d;
    LL pp=kk*g+A;
    if(C<pp&&pp<p) p=pp;
  }
//  dump4(g,k,p,p<B);
  return p<B?no:yes;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>T;
  REP(i,T) {
    cin>>A[i]>>B[i]>>C[i]>>D[i];
  }
  REP(i,T) {
//    dump(i);
    cout<<solve(A[i],B[i],C[i],D[i])<<endl;
  }

  return 0;
}