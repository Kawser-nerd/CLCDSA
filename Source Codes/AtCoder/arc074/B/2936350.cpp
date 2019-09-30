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
 
 23:50-24:26 analysis
 25:00 give up
 
 I wasted some tiem for unnecessary problem transformation :(
 one bug due to small set query update
 => I have no idea how to keep min N elements in right side
 
 8/2/2018
 
 15:00-15:48 got AC
 
 Computation of largest set in left can be performed independent of computation of smallest set in right side.
 We can keep the result of them in memory and compute difference later.
 
 Editorials:
  - https://youtu.be/O2wcqAqGQG8?t=1263
  -
 
 Summary:
  - My approach was correct. Design of algorithm was shit
   - move divider from left to right was correct
   - maintenance of smallest N numbers in right side was wrong
   - maintenance of largest N numbers in left side was correct
   - By symmetry, computation of right side should work like left side by pre-computation
   - Querying on-the-fly is unnecessary ?
  - Symmetry property => compute with the same way
  - Independence of problem => compute independently
  - Interesting technique to keep largest set in min-priority queue and vice versa
  - I should use priority queue instead of ordered set or ordered map more often
  - two implementation bugs ??
   - `continue` is not updating `L` or `R`
   - i=2*N is missing
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
LL A[3*MAX_N];
int N;

void add(LL x, map<LL,int> &M, LL &sum) {
  M[x]++;
  sum+=x;
}

void rem(LL x, map<LL,int> &M, LL &sum) {
  if(M.count(x)) {
    --M[x];
    sum-=x;
    if(M[x]==0) M.erase(x);
  }
}

void solve_wrong() {
  map<LL,int> M1,M2;
  LL sum1=0,sum2=0;
  REP(i,N) add(A[i],M1,sum1);
  FOR(i,N,2*N) add(A[i],M2,sum2);
  FOR(i,2*N,3*N) {
    LL a=A[i];
    auto high=M2.rbegin()->first;
    if(high>a) {
      rem(high,M2,sum2);
      add(a,M2,sum2);
    }
  }
  dump2(sum1,sum2);
  LL res=sum1-sum2;
  FOR(i,N,2*N) {
    LL a=A[i];
    LL low=M1.begin()->first;
    if(low<a) rem(low,M1,sum1),add(a,M1,sum1);
    LL high=M2.rbegin()->first;
    if(high>a) rem(high,M2,sum2);
    dump3(i,sum1,sum2);
    SMAX(res,sum1-sum2);
  }
  cout<<res<<endl;
}

const LL Inf=1e14+100;
LL L[3*MAX_N],R[3*MAX_N];
void solve() {
  int NN=3*N;
  REP(i,NN) L[i]=-Inf,R[i]=Inf;
  
  // left
  LL sum1=0;
  priority_queue<LL,vector<LL>, greater<LL>> Q1;
  REP(i,NN) {
    LL a=A[i];
    /*
    if(SZ(Q1)>=N) {
      LL minn=Q1.top();
      if(minn>=a) { L[i]=sum1; continue; }
      Q1.pop(),sum1-=minn;
    }
    Q1.push(a),sum1+=a;
    L[i]=sum1;
     */
    
    // cleaner way from @yutaka1999
    Q1.push(a),sum1+=a;
    if(SZ(Q1)>N) {
      LL minn=Q1.top();
      Q1.pop(),sum1-=minn;
    }
    L[i]=sum1;
  }
  
  
  // right
  LL sum2=0;
  priority_queue<LL> Q2;
  for(int i=NN-1; i>=0; --i) {
    LL a=A[i];
    /*
    if(SZ(Q2)>=N) {
      LL maxn=Q2.top();
      if(maxn<=a) { R[i]=sum2; continue; }
      Q2.pop(),sum2-=maxn;
    }
    Q2.push(a),sum2+=a;
//    dump3(i,a,sum2);
    R[i]=sum2;
     */
    
    // cleaner way from @yutaka1999
    Q2.push(a),sum2+=a;
    if(SZ(Q2)>N) {
      LL maxn=Q2.top();
      Q2.pop(),sum2-=maxn;
    }
    R[i]=sum2;
  }
  
  LL res=-Inf;
  FORE(i,N,2*N) {
//    dump4(i,L[i-1],R[i],L[i-1]-R[i]);
    SMAX(res,L[i-1]-R[i]);
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,3*N) cin>>A[i];
  solve();
  
  return 0;
}