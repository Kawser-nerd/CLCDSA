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
#define TRACE false
#define dump(x) if(TRACE) { cerr << #x << " = " << (x) << endl; }
#define dump2(x,y) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << ", " << #a << " = " << (a) << endl; }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }

/*
 
 8/3/2018
 
 24:50-25:02 analysis
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
//const int MAX_N=1e5+1;
LL H,W;
int N;
set<II> S;
//int A[MAX_N],B[MAX_N];
LL res[10];

II offsetsPrev(int pos, int d) {
  return {(9+pos-d)%3-pos,(pos-d-2)/3};
}
II offsetsNext(int pos, int d) {
  return {(pos+d)%3-pos,(d+pos)/3};
}

void solve() {
  ZERO(res);
  FORR(p,S) {
    int r=p.first,c=p.second;
    REP(i,9) {
      dump3(r,c,i);
      int p=i%3;
      // prev check
      int cnt=0;
      FORE(x,1,i) {
        int coff,roff; tie(coff,roff)=offsetsPrev(p,x);
        int rr=r+roff,cc=c+coff;
        if(r==2&&c==3&&i==4) dump3(rr,cc,S.count({rr,cc}));
        if(rr<0||cc<0||rr>=H||cc>=W) cnt=100;
        if(S.count({rr,cc})) ++cnt;
      }
      if(cnt) continue;
      
      // next check
      cnt=1;
      FOR(x,1,9-i) {
        int coff,roff; tie(coff,roff)=offsetsNext(p,x);
        int rr=r+roff,cc=c+coff;
        if(r==0&&c==3&&i==1)dump3(x,rr,cc);
        if(S.count({rr,cc})) ++cnt;
        if(rr<0||cc<0||rr>=H||cc>=W) cnt=-100;
      }
      dump4(r,c,i,cnt);
      if(1<=cnt&&cnt<10) res[cnt]++;
    }
  }
  res[0]=(H-2)*(W-2)-accumulate(res+1,res+10,0LL);
  REP(i,10) cout<<res[i]<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
//  REP(d,9) dump3(d,offsetsPrev(0,d).first,offsetsPrev(0,d).second);
//  REP(d,9) dump3(d,offsetsNext(2,d).first,offsetsNext(2,d).second);

  cin>>H>>W>>N;
  REP(i,N) {
    int r,c; cin>>r>>c;
    S.emplace(--r,--c);
  }
  solve();
  return 0;
}