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
#define dump2(x,y) if(TRACE) { cerr << #x << " = " <<setprecision(15)<< (x) << ", " << #y << " = " <<setprecision(15)<< (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " <<setprecision(15)<< (x) << ", " << #y << " = " <<setprecision(15)<< (y) << ", " << #z << " = " <<setprecision(15)<< (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " <<setprecision(15)<< (x) << ", " << #y << " = " <<setprecision(15)<< (y) << ", " << #z << " = " <<setprecision(15)<< (z) << ", " << #a << " = " <<setprecision(15)<< (a) << endl; }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }

/*
 
 8/10/2018
 
 17:15-17:25 analysis
 17:45 1WA
 
 19:00-19:33 AC after precision adjustment (sum by LL and use long doulbe instead of double)
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=50+1;
int N,A,B;
LL V[MAX_N];
LL C[MAX_N][MAX_N];
long double eps=1e-6;
void solve() {
//  sort(V,V+N);
//  REP(i,N) dump2(i,V[i]);
  
  ZERO(C);
  REP(i,MAX_N) {
    C[i][0]=1;
    FORE(j,1,i)C[i][j]=C[i-1][j]+C[i-1][j-1];
  }
  
  long double res1=-1;
  LL res2=0;
  FORE(n,A,B) {
    vector<pair<long double,int>> A(N); REP(i,N) A[i]={(long double)V[i]/n,i};
    sort(A.rbegin(),A.rend());
    LL sum=0;
    REP(i,n) sum+=V[A[i].second];
    long double a=(long double)sum/n;
    
    // NG if divided value is used
//    long double a=0;
//    REP(i,n) a+=A[i].first;

    if(a-res1>eps) res1=a,res2=0;
    if(abs(res1-a)<eps) {
      int l=n-1;
      while(l>=0&&V[A[l].second]==V[A[n-1].second]) --l;
      int k=n-1-l;
      int r=n-1;
      while(r<N&&V[A[r].second]==V[A[n-1].second]) ++r;
      int nn=k+r-n;
      res2+=C[nn][k];
    }
  }
  cout<<setprecision(15)<<res1<<endl;
  cout<<res2<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>A>>B;
  REP(i,N) cin>>V[i];
  solve();
  return 0;
}