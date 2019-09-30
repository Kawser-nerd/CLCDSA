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
 
 8/9/2018
 
 14:00-14:25 analysis
 14:51 redesign algorithm
 15:02 1WA and gave up
 
 18:10- read editorials and add solution
 
 Editorials:
  - https://youtu.be/VJntQuR2zNI?t=1988
 
 Left side or right side of rectangle should be picked from N points.
 Top/bottom side should be picked from N points as well.
 We can run N^4 loops to select them.
 
 |-------------| <- y[i]
 |             |
 |             |
 |-------------| <- y[j]

 ^            ^
 X[i]         X[j]
 
 We don't need to specify edge points to calculate area.
 What we need to compute area is max/min X and max/min Y.
 
  area = (max X - min X) * (max Y - min Y)
 
 Thus selection of X-coordinate and Y-coordinate is independent!!
 It's possible to count number of points inside the rectangle in O(N).
 O(N^5) algorithm should work.
 
 Key:
  - brute-force
  - we select x-coordinate and y-coordinate independently
 
 Summary:
  - It's typical that X-coordinate and Y-coordinate are independent
  - I haven't even looked for O(N^5) algorithm...
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=50+1;
int N,K;
pair<LL,LL> P[MAX_N];
void solve_wrong() {
  LL res=4e18+10;
  sort(P,P+N);
  REP(i,N) {
    priority_queue<LL> Q1,Q2;
    LL x0,y0; tie(x0,y0)=P[i];
    FOR(j,i,N) {
      LL x,y; tie(x,y)=P[j];
      (y<y0?Q2:Q1).emplace(abs(y0-y));
      if(SZ(Q1)+SZ(Q2)>K) (Q2.empty()||Q1.top()>Q2.top()?Q1:Q2).pop();
      if(SZ(Q1)+SZ(Q2)==K) {
        LL dx=x-x0,dy=(SZ(Q1)?Q1.top():0)+(SZ(Q2)?Q2.top():0);
        SMIN(res,dx*dy);
      }
    }
  }
  cout<<res<<endl;
}

LL X[MAX_N],Y[MAX_N];
void solve() {
  LL res=4e18+10;
  REP(i1,N)REP(i2,N)if(X[i1]<=X[i2])REP(j1,N)REP(j2,N)if(Y[j1]<=Y[j2]) {
    LL x1=X[i1],x2=X[i2],y1=Y[j1],y2=Y[j2];
    int cnt=0;
    REP(i,N) cnt+=(x1<=X[i]&&X[i]<=x2&&y1<=Y[i]&&Y[i]<=y2);
    if(cnt>=K) SMIN(res,(x2-x1)*(y2-y1));
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>K;
  REP(i,N) {
    LL x,y; cin>>x>>y;
    P[i]={x,y};
    X[i]=x,Y[i]=y;
  }
  solve();
  return 0;
}