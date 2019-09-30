#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);


vector<string> ans(8);

bool dfs(int rem, int x, int y, int z, int w) {
  if (rem == 0) return true;

  rep(i, 8)rep(j, 8) {
    if (x & (1 << j)) continue;
    if (y & (1 << i)) continue;
    if (z & (1 << (i + j))) continue;
    if (w & (1 << (i + 7 - j))) continue;
    if (dfs(rem - 1, x | (1 << j), y | (1 << i), z | (1 << (i + j)), w | (1 << (i + 7 - j)))) {
      ans[i][j] = 'Q';
      return true;
    }
  }
  return false;
}

bool solve(vector<string> vs) {
  ans = vs;
  int x = 0;
  int y = 0;
  int z = 0;
  int w = 0;
  rep(i, 8)rep(j, 8) {
    if (vs[i][j] == 'Q') {
      if (x & (1 << j)) return false;
      if (y & (1 << i)) return false;
      if (z & (1 << (i + j))) return false;
      if (w & (1 << (i + 7 - j))) return false;
      x |= 1 << j;
      y |= 1 << i;
      z |= 1 << (i + j);
      w |= 1 << (i + 7 - j);
    }
  }
  return dfs(5, x, y, z, w);
}

int main() {
  std::ios::sync_with_stdio(false);
  vector<string> vs(8);
  while(cin >> vs[0]) {
    rep(i, 7) cin >> vs[i + 1];
    if (solve(vs)) {
      rep(i, 8) cout << ans[i] << endl;
    } else {
      cout << "No Answer" << endl;
    }
  }
  return 0;
}