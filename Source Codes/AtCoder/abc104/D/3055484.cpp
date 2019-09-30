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
 
 8/21/2018
 
 15:25-15:27 analysis
 16:10 give up
 
 17:20-17:45 read editorials and add solution
 
 I've never come up with dp. Also I couldn't make formula of number of '?' and 'c' separately. sigh ?
 
 Editorials:
  - https://youtu.be/DEGyESFF8iE?t=1900
  - https://img.atcoder.jp/abc104/editorial.pdf
   - dp
  - https://www.hamayanhamayan.com/entry/2018/08/05/232127
  - http://hamko.hatenadiary.jp/entry/2018/08/05/224003
  - http://hamuhei4869.hatenablog.com/entry/2018/08/11/074415
  - http://kazune-lab.net/contest/2018/08/05/abc104/#d---we-love-abc
  - http://sugardragon5.hatenadiary.com/entry/2018/08/05/235931
   - this formula is exactly what I wanted to make
  - https://babcs2035.hateblo.jp/entry/2018/08/12/193155
 
 Summary:
  - I tried to solve by cumulative sum. However it was waste of time ??????????
  - poor math taste ????????????????????
  - I didn't have idea to keep both count of '?' and current counting ????????????????????????????????????????
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
int N;
string S;
LL A[MAX_N],C[MAX_N],Q[MAX_N];
LL P3[MAX_N];
const LL MOD=1e9+7;
void solve_org() {
  ZERO(A),ZERO(C),ZERO(Q);
  P3[0]=1;
  REP(i,N) P3[i+1]=P3[i]*3LL%MOD;
  REP(i,N) {
    A[i+1]=A[i]+(S[i]=='A');
    C[i+1]=C[i]+(S[i]=='C');
    Q[i+1]=Q[i]+(S[i]=='?');
  }
  LL res=0;
  FOR(i,1,N-1) if(S[i]=='B'||S[i]=='?') {
    LL a=A[i]*P3[Q[i]]%MOD;
    if(Q[i]>0)a=(a+Q[i]*P3[Q[i]-1]%MOD)%MOD;
    LL q=Q[N]-Q[i+1];
    LL c=(C[N]-C[i+1])*P3[q]%MOD;
    if(q>0) c=(c+q*P3[q-1]%MOD)%MOD;
//    dump3(i,C[N]-C[i+1],q);
//    dump3(i,a,c);
    (res+=a*c%MOD)%=MOD;
  }
  cout<<res<<endl;
}

string ABC="ABC";
LL dp[MAX_N][4];
void solve() {
  ZERO(dp);
  dp[0][0]=1;
  REP(i,N)REP(j,4) {
    if(j<3) {
      if(ABC[j]==S[i]) (dp[i+1][j+1]+=dp[i][j])%=MOD;
      if(S[i]=='?') {
        (dp[i+1][j+1]+=dp[i][j])%=MOD; // match
        (dp[i+1][j]+=3LL*dp[i][j]%MOD)%=MOD; // not match
      } else {
        (dp[i+1][j]+=dp[i][j])%=MOD;
      }
    } else {
      (dp[i+1][j]+=(S[i]=='?'?3LL:1LL)*dp[i][j]%MOD)%=MOD;
    }
  }
  cout<<dp[N][3]<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>S;
  N=SZ(S);
  solve();
  return 0;
}