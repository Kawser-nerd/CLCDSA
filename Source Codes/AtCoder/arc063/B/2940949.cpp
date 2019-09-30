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
 
 8/3/2018
 
 19:50-20:20, 21:30-21:47 ACC
 
 Editorials:
  - http://arc063.contest.atcoder.jp/data/arc/063/editorial.pdf
  - https://youtu.be/iJwEPVN5MXs?t=1958
  - https://kimiyuki.net/writeup/algo/atcoder/arc-063-d/
  - http://ymduu.hatenablog.com/entry/2018/07/03/203121
  - http://hyoga.hatenablog.com/entry/2016/11/06/224713
  - http://xxxasdfghjk999.hatenablog.jp/entry/2018/07/25/232727
 
 keeping `min` in memory is impressive.
 `min` and `max` are independent. It's possible to compute previously.
 
 Summary:
  - keeping `min` in memory is neet
  - I should keep independency in mind more
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
int N;
LL A[MAX_N];
LL T;
void solve_org() {
  map<LL,int> D;
  LL btm=A[0];
  FOR(i,1,N) {
    if(A[i]<btm) btm=A[i];
    else if(A[i]>btm) {
      D[-(A[i]-btm)]++;
    }
  }
  cout<<D.begin()->second<<endl;
}

void solve() {
  LL mins[MAX_N];
  mins[0]=A[0];
  map<LL,int> D;
  FOR(i,1,N) mins[i]=min(mins[i-1],A[i]);
  FOR(i,1,N) D[-(A[i]-mins[i-1])]++;
  cout<<D.begin()->second<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>T;
  REP(i,N) cin>>A[i];
  solve();
  return 0;
}