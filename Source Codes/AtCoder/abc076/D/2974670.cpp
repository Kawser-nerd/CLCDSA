/*#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>*/
#include <fstream> // for greed plugin
#include <iostream>
#include <algorithm> // max,min
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
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef long long LL;
using namespace std;

/*
 
 8/8/2018
 
 16:36-17:36 give up
 19:15- read editorials and got AC
 
 Editorials:
  - https://img.atcoder.jp/abc076/editorial.pdf
  - https://youtu.be/T1zXzsoK268?t=1804
  - simulation
   - http://ferin-tech.hatenablog.com/entry/2017/10/28/231616
   - http://www.neetaro.com/entry/atcoder-beginner-contest-abc-076
   - http://kazune-lab.net/contest/2017/10/28/abc076/
  - dp
   - https://www.hamayanhamayan.com/entry/2017/10/28/230944
   - https://kimiyuki.net/writeup/algo/atcoder/abc-076-d/
   - http://hamko.hatenadiary.jp/entry/2017/10/28/224055
 
 I tried to compute possible range of velocity at T[i].
 However actually total time is upper-bounded by 2*10^4.
 It's possible to calculate area by "manual integral".
 Also velocity should satisfy limit which is coming from both-ends.
 We need to calculate it in both ways.
 
 Key:
  - T is small. We can manually compute integral by simulation
  -
 
 */
const int MOD = 1e9+7;
const int SIZE=1e6+10;
int t[SIZE],v[SIZE],a[SIZE],m;

template <class T>
void mii(T& x,T y){
  if(x>y)x=y;
}

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
//const int MAX_N=2*100*200+1;
int N;
void solve() {
  REP(i,SIZE) a[i]=MOD;
  int it=0;
  a[0]=0;
  REP(i,N) {
    mii(a[it],v[i]);
    REP(j,t[i]) {
      it++;
      mii(a[it],v[i]);
    }
  }
  mii(a[it],0);
  REPP(i,1,it+1) {
    mii(a[i],a[i-1]+1);
  }
  for(int i=it-1; i>=0; i--) {
    mii(a[i],a[i+1]+1);
  }
  LL an=0;
  REP(i,it) an+=(a[i]+a[i+1]);
//  printf("%.12f\n",an*0.125);
  double ans=an*0.125;
  cout<<setprecision(8)<<ans<<endl;
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>t[i],t[i]*=2;
  REP(i,N) cin>>v[i],v[i]*=2;
  solve();
  return 0;
}