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
 
 8/1/2018
 
 17:40-18:55 AC
 
 I spent a lot of time to go through wrong approach :(
 
 Editorials:
  - https://atcoder.jp/img/arc068/editorial.pdf
  - https://youtu.be/Y9v0a4d0vzk?t=1250
  - https://kimiyuki.net/writeup/algo/atcoder/arc-068-d/
  - http://beet-aizu.hatenablog.com/entry/2017/01/30/155009
  - http://nafmo.hatenablog.jp/entry/2017/03/08/210624#D%E5%95%8F%E9%A1%8CCard-Eater
 
 Editorial solution is super simple.
 
  res = K%2==0?K:K-1
 
 Note that N is odd. Otherwise this does not work.
 
 Suppose there are `x` `k`s.
 If x>2, we can keep reducing `k` only by `k`s.
 k k k k k (x=5) => k k k (x=3: two `k`s are removed) => k (x=1: two `k`s are removed)
 Eventually we get one or two `k`(s).
 
 Suppose there are `x` groups with two numbers like 2 2 3 4 5 5 6 7 7 8 8 (4 groups).
 
 two numbers keep decreasing by two like 2 2 5 5 => 2 5
 
 Eventually we get one or zero two numbers.
 
 2 2 3 4 5 5 6 7 7 8 8 =>   2 3 4 5 6 7 8
 2 2 3 4 5 5 6 7 7 8   => 2 2 3 4 5 6 7 8 => 2 4 5 6 7
 
 A group of two numbers remain, one group should be removed. => res = K-1
 Otherwise all the existing groups remain.                   => res = K
 
 We keep removing two numbers from odd numbers and eventually get `K` or `K-1`.
 Then parity never changes. `K` or `K-1` should be odd too.
 Thus we can check `K`. If it's odd, we can return `K`. Otherwise we can return `K-1`.
 
 Code looking at only K:
  - https://beta.atcoder.jp/contests/arc068/submissions/1082961
  - https://beta.atcoder.jp/contests/arc068/submissions/1083600
 
 Summary:
  - I couldn't complete parity approach described in editorials ?
  - Eventually I solved by greedy with complicated implementation ??
  - I didn't analyze `odd` N condition deeply. Thus I needed super complex solution ????
  - Parity is often useful to reduce problems. Keep in mind.
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
LL A[MAX_N];
int N;

void solve_wrong() {
  sort(A,A+N);
  int l=0,r=N-1;
  auto movel=[&]() {
    while(l<N-1&&A[l]!=A[l+1]) ++l;
  };
  auto mover=[&]() {
    while(r>0&&A[r]!=A[r-1]) --r;
  };
  movel(),mover();
  while(l<r&&A[l]!=A[r]) {
    if(A[l]!=A[l+1]) {
      dump3(l,A[l],A[l+1]);
//      dumpAR(A);
    }
    if(A[r]!=A[r-1]) {
      dump3(r,A[r-1],A[r]);
//      dumpAR(A);
    }

    assert(A[l]==A[l+1]&&A[r]==A[r-1]);
    ++l,--r;
    movel(),mover();
    dump2(l,r);
  }
  MAPII M;
  REP(i,N) M[A[i]]++;
  
  dump4(l,A[l],r,A[r]);
  int res=SZ(M);
  if(A[l]==A[r]&&M[A[l]]%2==0) res--;
  cout<<res<<endl;
}

void solve_org() {
  sort(A,A+N);
  MAPII M; set<int> S;
  REP(i,N) M[A[i]]++,S.emplace(A[i]);
  VI X(S.begin(),S.end());
  int NN=SZ(X);
//  dump(NN);
//  REP(i,NN) dump3(i,X[i],M[X[i]]);
  
  int l=0,r=NN-1;
  auto movel=[&]() {
    while(l<NN&&M[X[l]]==1) ++l;
  };
  auto mover=[&]() {
    while(r>=0&&M[X[r]]==1) --r;
  };
  movel(),mover();
  while(l<r) {
    assert(M[X[l]]>1&&M[X[r]]>1);
    M[X[l]]--,M[X[r]]--;
    movel(),mover();
  }
//  dump4(l,r,X[l],M[X[l]]);
  int res=NN;
  if(l==r&&(M[X[l]]%2==0)) --res;
  cout<<res<<endl;
}

// editorial solution
void solve() {
  int cnt[MAX_N]={};
  REP(i,N)cnt[A[i]]++;
  int res=0;
  FOR(i,1,MAX_N) if(cnt[i]) ++res;
  if(res%2==0) --res;
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>A[i];
  solve();
  
  return 0;
}