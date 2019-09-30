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
 
 8/25/2018
 
 16:20-16:50 give up
 
 Only O(N) or O(N*lg N) algorithm works. Thus I imagined dfs or union-find may work though, I couldn't mover forward..
 I also tried to keep picking up new vertices greedily though, I was not sure if that's correct.
 Actually this strategy was correct. Missing part was proving that it always finds such path.
 
 8/26/2018
 
 21:30- read editorials
 
 Editorials:
  - https://youtu.be/ypRiuUxMbGk?t=1193
  - https://atcoder.jp/img/agc013/editorial.pdf
  - https://kimiyuki.net/writeup/algo/atcoder/agc-013-b/
  - http://potetisensei.hatenablog.com/entry/2018/03/23/163135
  - http://tokumini.hatenablog.com/entry/2018/07/27/144143
  - http://hamko.hatenadiary.jp/entry/2017/07/28/115045
  - http://kazune-lab.net/contest/2017/04/16/agc013/#b---hamiltonish-path
 
 Summary:
  - Keep finding greedy like way was close. I should try to dig it more deeply.
  - I didn't have clear implementation image. So I couldn't move forward.
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
int N,M;
VI E[MAX_N];
int viz[MAX_N];
deque<int> Q;

bool dfs(int u, bool dir) {
  if(dir) Q.push_back(u);
  else Q.push_front(u);
  viz[u]=true;
  
  bool done=true;
  FORR(v,E[u]) {
    done&=viz[v];
    if(!done) {
      dfs(v,dir);
      break;
    }
  }
  return done;
}

void solve(int u, int v) {
  viz[u]=viz[v]=1;
  dfs(u,1);
  dfs(v,0);
  cout<<SZ(Q)<<endl;
  while(SZ(Q)) {
    cout<<Q.front()<<(SZ(Q)==1?'\n':' ');
    Q.pop_front();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>M;
  int u,v;
  REP(i,M) {
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  solve(u,v);
  return 0;
}