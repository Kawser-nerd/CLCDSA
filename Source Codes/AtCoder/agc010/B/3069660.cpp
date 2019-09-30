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
 
 8/24/2018
 
 15:10-15:41 analysis
 15:44 submit and got 1WA
 
 2
 500000000 1000000000
 
 should be YES
 
 15:54 give up
 
 21:10- read editorials
 
 Editorial:
  - https://atcoder.jp/img/agc010/editorial.pdf
  - https://youtu.be/WdKN1-pvpB0?t=1220
 
 Handling +1,+2,+3,..,+N is not easy.
 We want to transform problem to easier form so that we can solve in O(N) or O(N* lg N) time.
 
 Suppose N=5, one operation is adding below to original `A`.
 
 -2, -3, -4, -5, -1
 
 This is not easy to handle.
 However if we convert them to sequence of difference, all the elements but one are `1`
 
   +1  +1  +1   -4  +1
    ^   ^   ^   ^   ^
 -2, -3, -4, -5, -1, (-2)
 
 Sum of operations are necessary and sufficient to Sum of difference as shown below:
 
 3) 6, 9, 12, 10,  8 <=> 3, 3, -2, -2, -2
   -2 -3  -4  -5  -1    -1 -1  -1  +4  -1
 2) 4, 6,  8,  5,  7 <=> 2, 2, -3,  2, -3
   -3 -4  -5  -1  -2    -1 -1  +4  -1  -1
 1) 1, 2,  3,  4,  5 <=> 1, 1,  1,  1, -4
    1  2   3   4   5    -1 -1  -1  -1  +4
 0) 0, 0,  0,  0,  0     0, 0,  0,  0,  0
 
 So we can make sequence of difference D of A. Note that order of operations doesn't matter.
 Each operation changes D[i] with either `1` or `-N-1`
 If `K` operations happen, D[i]<=K and D[i] is multiple of N from below equation:
 Suppose `i` is N-1 in `x` operations..
 
     1*(K-x) - (N-1)*x = D[i]
 <=> K - D[i] = N * x
 
 Key:
  - if adding 1,2,3,..,N, look at sequence of differences which is `1`
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
int N;
LL A[MAX_N];
int b[MAX_N]={};
bool solve_wrong() {
  LL tot=accumulate(A,A+N,0LL);
  LL turn=1LL*N*(N+1)/2;
  dump3(tot,turn,tot%turn);
  if(tot%turn!=0) return false;
  LL p=tot/turn;
  REP(i,N) A[i]-=p;
  REP(i,N) dump2(i,A[i]);
  ZERO(b);
  REP(i,N) b[A[i]%N]++;
  bool ok=true;
  REP(i,N) {
    dump2(i,b[i]);
    if(b[i]!=1) ok=false;
  }
  return ok;
}

LL D[MAX_N];
bool solve() {
  LL tot=accumulate(A,A+N,0LL);
  LL turn=1LL*N*(N+1)/2;
//  dump3(tot,turn,tot%turn);
  if(tot%turn!=0) return false;
  LL K=tot/turn;
  REP(i,N) D[i]=A[(i+1)%N]-A[i];
  bool ok=true;
  REP(i,N) ok&=(D[i]<=K&&(K-D[i])%N==0);
  return ok;
}

const string yes="YES",no="NO";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>A[i];
  cout<<(solve()?yes:no)<<endl;
  return 0;
}