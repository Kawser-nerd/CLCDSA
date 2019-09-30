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
 
 8/2/2018
 
 20:00-20:24 1WA
 21:15 give up
 
 21:15-21:30, 23:30- read editorials
 
 Editorials:
  - https://atcoder.jp/img/arc072/editorial.pdf
  - https://youtu.be/j2o5c6Xp3xw?t=1763
  - http://hamko.hatenadiary.jp/entry/2017/04/22/230513
  - http://naoyat.hatenablog.jp/entry/ARC072D
 
 I tried to find "lose" state. However no luck ?
 Making a table was a key to find out it.
 
 I thought (1,0) is lose state. However (1,1) can happen. I wasted a lot of time. sigh ??
 
 x2=x1-2*i
 y2=y1+i
 
 => (y2-y1)/(x2-x1)=-1/2
 
 x2=x1+i
 y2=y1-2*i
 
 => (y2-y1)/(x2-x1)=-2
 
 Thus state transition happens like line with slope -1/2 or -2.
 If we do experiment, it's like below:
 
   0123456 X
   ----------
 0|LLWWWWWWWW
 1|LLLWWWWWWW
 2|WLLLWWWWWW
 3|WWLLLWWWWW
 4|WWWLLLWWWW
 5|WWWWLLLWWW
 6|WWWWWLLLWW
 7|WWWWWWLLLW
 8|WWWWWWWLLL
 9|WWWWWWWWLL
 Y
 
 From this we figure out that |x-y|<=1 is "lose" state.
 
 Summary:
  - Not only looking at math property, do experiment for small N
 
 */
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
//const int MAX_N=1e5+1;
//LL A[MAX_N];
LL X,Y;

const string p1="Alice",p2="Brown";
bool solve_wrong() {
  LL maxn=max(X,Y);
  if(maxn<2LL) return false;
  if((X+Y)%2LL==0LL) return maxn>=2LL;
  return maxn>=4LL;
}

bool solve() {
  return abs(X-Y)>1;
}

int memo[101][101];
int f(int x, int y) {
  if(x+y<=1) return 0;
  int &res=memo[x][y];
  if(res>=0) return res;
  SETI S;
  for(int i=1; 2*i<=max(x,y); ++i) {
    if(x-2*i>=0&&y+i<100) S.emplace(f(x-2*i,y+i));
    if(y-2*i>=0&&x+i<100) S.emplace(f(x+i,y-2*i));
  }
  int mex=0;
  while(S.count(mex)) ++mex;
  return res=mex;
}

void test() {
  MINUS(memo);
  REP(x,100){
    REP(y,100) {
      cout<<(f(x,y)==0?'L':'W');
    }
    cout<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
//  test();
  
  cin>>X>>Y;
  cout<<(solve()?p1:p2)<<endl;
  
  return 0;
}