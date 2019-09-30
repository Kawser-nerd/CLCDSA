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
#include <iomanip>
using namespace std;
// type alias
typedef long long LL;
typedef pair< int , int > II;
typedef tuple< int, int, int > III;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef unordered_map<int,int> MAPII;
typedef unordered_set<int> SETI;
template<class T> using VV=vector<vector<T>>;
// minmax
template<class T> inline T SMIN(T& a, const T b) { return a=(a>b)?b:a; }
template<class T> inline T SMAX(T& a, const T b) { return a=(a<b)?b:a; }
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// collection
#define ALL(c) (c).begin(),(c).end()
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))

// stdout
#define println(args...) fprintf(stdout, ##args),putchar('\n');

// debug cerr
#define TRACE true
#define dump(x) if(TRACE) { cerr << #x << " = " << (x) << endl; }
#define dump2(x,y) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << ", " << #a << " = " << (a) << endl; }
#define dumpf(args...) if(TRACE) { fprintf(stderr, ##args); putchar('\n'); }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }
template<class Iter> void dumpc(Iter begin, Iter end) { if (TRACE) { for(; begin!=end; ++begin) { cerr<<*begin<<','; } cerr<<endl; } }

/*
 
 12/2/2018 ABC114
 
 21:19-22:40 give up and look at https://beta.atcoder.jp/contests/abc114/submissions/3702911 (by @kmjp)
 22:57 got AC
 
 I knew how to count # of divisors from prime factorization.
 However instead of diggint it, I was trying to solve from requirement of perfect square.
 
 https://img.atcoder.jp/abc114/editorial.pdf
 
 Summary:
  - I had an idea of prime factorization: 32400 = 2^4*3^4*5^2
  - However I didn't confirm (4+1)*(4+1)*(2+1) = 75 ?
 
 */

// 22:40 give up
//  22:57 got AC

// $ ../batch 756 | diff 756.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address 756.cpp && ./a.out
int N;

vector<LL> primeFactors(LL n) {
  assert(n>=1);
  vector<LL> res;
  for(LL p=2; p*p<=n; ++p) while(n%p==0) {
    res.push_back(p);
    n/=p;
  }
  if(n>1) res.push_back(n);
  return res;
}

int P[101]={};

int res[4];
void dfs(int p, VI T, int q) {
  if(p>=SZ(T)) {
    ++res[q];
    return;
  }
  REPE(n,100) if(P[n]>=T[p]) {
    int a=P[n];
    P[n]=0;
    dfs(p+1,T,q);
    P[n]=a;
  }
}
void solve() {
  for(int i=1; i<=N; ++i) {
    vector<LL> ps=primeFactors(i);
    FORR(p,ps) P[p]++;
  }
  dfs(0,{74},0);
  dfs(0,{2,24},1);
  dfs(0,{4,14},2);
  dfs(0,{2,4,4},3);
  res[3]/=2;
  cout<<res[0]+res[1]+res[2]+res[3]<<endl;
}

int dp[100]={};
void solve_dp() {
  for(int i=1; i<=N; ++i) {
    vector<LL> ps=primeFactors(i);
    FORR(p,ps) P[p]++;
  }
  dp[1]=1;
  for(int p=1; p<=100; ++p) if(P[p]>0) {
//    dump2(p,P[p]);
    for(int cnt=75; cnt>=1; --cnt) if(dp[cnt]) {
      for(int f=1; f<=P[p]; ++f) if(cnt*(f+1)<=75) dp[cnt*(f+1)]+=dp[cnt];
    }
  }
  cout<<dp[75]<<endl;
}
void test() {
  int X=16*81*25;
  int i=0;
  for(int p=1; p*p<=X; ++p) if(X%p==0) {
    dump3(++i,p,X/p);
  }
  vector<LL> ps=primeFactors(X);
  dumpAR(ps);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
//  test();
  
  cin>>N;
  solve();
  
  return 0;
}