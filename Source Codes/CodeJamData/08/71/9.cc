#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <glpk.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define BEND(v) v.begin(),v.end()
//#define dump(x) cerr << #x << " = " << (x) << endl;
#define dump(...)
typedef long long ll; typedef long double ld;

int cas=0;
int N,M[1024];
int adj[1024][16];
bool issub[1024];
map<string,int> mp;
int nxt;
int canon(const string& s) {
  if (mp.count(s)) return mp[s];
  return mp[s] = nxt++;
}
int dp[1024][1<<10];
const int inf = 123456789;
int dodp(int v, int mask) {
  assert(0 <= v && v < 1024);
  assert(0 <= mask && mask < (1<<10));
  dump(v);
  dump(mask);
  int& ans = dp[v][mask];
  if (ans != -1) return ans;
  ans = inf;

  int act = 0, tot = 0;
  FOR(i,M[v]) if (adj[v][i] != -1) tot++;
  FOR(i,M[v]) if ((mask & (1<<i)) && adj[v][i] != -1) act++;
  dump(act);
  dump(tot);

  if (!act) return ans = 1;

  FOR(i,M[v]) if (mask & (1<<i)) {
    int w = adj[v][i];
    if (w == -1) continue;

    dump(w);
    int v1 = dodp(w, (1<<M[w])-1);
    int v2 = 1 + dodp(v, mask & (~(1<<i)));
    dump(v1);
    dump(v2);
    //assert(v1 <= 4);
    if (v2 > 4) {
      dump("ALERT");
      dump(v);
      dump(mask);
    }
    //assert(v2 <= 4);
    int now = max(v1, v2);
    dump(now);
    ans = min(ans,now);
  }
  assert(ans < inf);
  dump(ans);

  return ans;
}
void doit() {
  memset(issub,0,sizeof(issub));
  mp.clear();
  nxt = 0;
  scanf("%d",&N);
  FOR(i,N) {
    char buf[32];
    scanf(" %s",buf);
    string nm(buf);
    assert(nm.size() && isupper(nm[0]));
    int j = canon(nm);
    scanf("%d",&M[j]);
    assert(M[j] <= 10);
    FOR(k,M[j]) {
      scanf(" %s",buf);
      string aa(buf);
      adj[j][k] = -1;
      if (islower(aa[0])) continue;
      adj[j][k] = canon(aa);
      issub[canon(aa)] = 1;
    }
  }

  int root = -1;
  FOR(i,N) if (!issub[i]) {
    assert(root == -1);
    root = i;
  }
  assert(root != -1);

  memset(dp,-1,sizeof(dp));
  int ans = dodp(root,(1<<M[root])-1);
  //dump(dodp(1,7));
  dump(dodp(0,0));
  dump(dodp(0,2));
  dump(dodp(0,3));
  //assert(dodp(1,0) == 1);
  //assert(dodp(0,7) == 4);
  //assert(ans < inf);
  printf("Case #%d: %d\n",++cas,ans);
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
