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
 
 8/5/2018
 
 16:05-16:15 analysis
 16:16-16:30 implement and got AC
 
 Editorials:
  - https://atcoder.jp/img/arc069/editorial.pdf
  - https://youtu.be/hetSRNLGOtk?t=1673
 
 Reducing to 0/1 modular arithmetic problem is cool.
 Solution with mod by @sky58: https://beta.atcoder.jp/contests/arc069/submissions/1115139
 
 How can we come up with mod property?
 
 Suppose we have x,y,z ? {S(0),W(1)}
 x==z => S[i]=1, x!=z => S[i]=0
 
 This is identical to x+z (mod 2) = S[i]
 If animal is wolf, this is inverted. Inversion can be represented by +1 in (mod 2).
 Thus,
 
  S[i] = x+y+z (mod 2)
 
 This is leveraging two properties:
  - z=(x==y) and x?{0,1} <=> z=(x+y)%2 and x?{0,1}
  - y=A if x=0, y=!A if x!=0 <=> y=(A+1)%2
 
 Key:
  - brute-force two initial animals and verify it
 
 Summary:
  - I have solved similar problem in SRM
  - modular arithmetic ++
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
//const int MAX_N=1e5+1;
int N;
string S;
const char sh='S',wo='W';
const char A[2]={sh,wo};
map<char,int> key={{sh,0},{wo,1}};
char f(char me, char nei, char ans) {
  if(me==sh&&ans=='o') return nei;
  if(me==wo&&ans=='x') return nei;
  return A[key[nei]^1];
}

void solve_org() {
  REP(mask,4) {
    string X=string(N,'#');
    X[0]=(mask&1)?sh:wo;
    X[1]=((mask>>1)&1)?sh:wo;
    bool ok=true;
    REP(i,N) {
//      if(X[i]=='#') dump2(i,X[i]);
      assert(X[i]!='#');
      int l=(N+i-1)%N,r=(i+1)%N;
      assert(X[l]!='#'||X[r]!='#');
      if(X[l]!='#'&&X[r]!='#') {
        ok&=f(X[i],X[l],S[i])==X[r]&&f(X[i],X[r],S[i])==X[l];
      } else if(X[l]=='#') X[l]=f(X[i],X[r],S[i]);
      else X[r]=f(X[i],X[l],S[i]);
    }
    if(ok) {
      // assertion
      REP(i,N) {
        int l=(N+i-1)%N,r=(i+1)%N;
        assert(f(X[i],X[l],S[i])==X[r]&&f(X[i],X[r],S[i])==X[l]);
      }
      
      cout<<X<<endl;
      return;
    }
  }
  cout<<-1<<endl;
}

void solve() {
  map<char,int> F={{'o',1},{'0',0}};
  const char A[2]={wo,sh};
  VI X(N,0);
  REP(mask,4) {
    X[0]=mask&1,X[1]=(mask>>1)&1;
    FOR(i,1,N-1) X[i+1]=(F[S[i]]+X[i-1]+X[i])%2;
    if(X[0]!=(X[N-2]+X[N-1]+F[S[N-1]])%2) continue;
    if(F[S[0]]!=(X[N-1]+X[0]+X[1])%2) continue;
    string res(N,'?'); REP(i,N)res[i]=A[X[i]];
    cout<<res<<endl;
    return;
  }
  cout<<-1<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>S;
  solve();
  return 0;
}