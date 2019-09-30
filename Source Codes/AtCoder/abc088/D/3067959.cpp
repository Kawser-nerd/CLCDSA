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
 
 8/24/2018
 
 16:00-16:08 analysis
 16:16 submit and got TLE
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
vector< pair < int, int > >  moves = { {0,1}/*R*/,{1,0}/*D*/,{0,-1}/*L*/,{-1,0}/*U*/ };
const int MAX_N=50+1;
int H,W;
LL D[MAX_N][MAX_N];
string G[MAX_N];
const int Inf=1e8;
int  solve() {
  REP(i,H)REP(j,W)D[i][j]=Inf;
  queue<II> Q; Q.emplace(0,0); D[0][0]=0;
  if(G[0][0]=='#') return -1;
  
  while(SZ(Q)) {
    int i,j; tie(i,j)=Q.front(); Q.pop();
//    dump4(SZ(Q),i,j,D[i][j]);
    FORR(m,moves) {
      int ii=i+m.first,jj=j+m.second;
      if(ii<0||ii>=H||jj<0||jj>=W) continue;
      if(G[ii][jj]=='#') continue;
      if(D[ii][jj]<=D[i][j]+1) continue;
      D[ii][jj]=D[i][j]+1;
      Q.emplace(ii,jj);
    }
  }
  if(D[H-1][W-1]==Inf) return -1;
  int cnt=0;
  REP(i,H)REP(j,W)cnt+=G[i][j]=='.';
  return cnt-D[H-1][W-1]-1;
}

int genRandNum(int lb, int ub) {
  // Helper to generate random integer in range [lb, ub)
  int x = rand() % (int)(ub - lb);
  return x + lb;
}
vector<int> genRandSeq(int size, int lb, int ub) {
  if (size==0) return {};
  vector<int> res(size);
  generate(res.begin(), res.end(), [&]() {
    return genRandNum(lb, ub);
  });
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  /*
  while(true) {
    H=50,W=50;
    REP(i,50) {
      VI x=genRandSeq(50,0,2);
      string s;
      REP(j,50)s+=x[i]?'#':'.';
      G[i]=s;
      cout<<s<<endl;
    }
    cout<<solve()<<endl;
  }
    */
  
  cin>>H>>W;
  REP(i,H) cin>>G[i];
  cout<<solve()<<endl;
  return 0;
}