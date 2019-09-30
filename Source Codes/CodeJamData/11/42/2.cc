#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

bool debug = false;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;
typedef set<string> ss;
typedef set<pii> spii;

const double pi = 2.0*acos(0.0);

int CASES;

void init() {
  assert(scanf("%d", &CASES) == 1);
}

int print(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  vfprintf(stderr, err, pvar);
  return vfprintf(stdout, err, pvar);
}

int dprint(const char *err, ...) { 
  if (debug) {
    va_list pvar;
    va_start(pvar, err);
    return vfprintf(stderr, err, pvar);
  }
  return 0;
}


int grid[600][600];
int R, C, D;

ll xsum[600][600];
ll ysum[600][600];
ll wsum[600][600];

bool ok(ll K) {
  debug = (K== 5);
  for (int r = 0; r + K <= R; ++r)
    for (int c = 0; c + K <= C; ++c) {
      int r2 = r+K, c2 = c+K;
      //      debug = (K == 5 && r2 == 6 && c2 == 6);
      ll ws = wsum[r2][c2] - wsum[r][c2] - wsum[r2][c] + wsum[r][c] 
	- grid[r+1][c+1] - grid[r2][c+1] - grid[r+1][c2] - grid[r2][c2];
      assert(ws > 0);
      ll xs = xsum[r2][c2] - xsum[r][c2] - xsum[r2][c] + xsum[r][c] 
	- (ll)(c+1)*(grid[r+1][c+1]+grid[r2][c+1])
	- (ll)(c2)*(grid[r+1][c2]+grid[r2][c2]);
      assert(xs > 0);
      //      dprint("k %lld r %d c %d: xs = %lld expect (%d)*%lld / 2\n", K, r, c, xs, (c+1+c2), ws);
      if (2*xs != ws*(c+1+c2)) continue;
      ll ys = ysum[r2][c2] - ysum[r][c2] - ysum[r2][c] + ysum[r][c] 
	- (ll)(r+1)*(grid[r+1][c+1]+grid[r+1][c2])
	- (ll)(r2)*(grid[r2][c+1]+grid[r2][c2]);
      //      dprint("k %lld r %d c %d: ys = %lld expect (%d)*%lld / 2\n", K, r, c, ys, (r+1+r2), ws);
      assert(ys > 0);
      if (2*ys != ws*(r+1+r2)) continue;
      return true;
    }
  return false;
}

void solve(int P) {
  assert(scanf("%d%d%d", &R, &C, &D) == 3);

  memset(xsum, 0, sizeof(xsum));
  memset(ysum, 0, sizeof(ysum));
  memset(wsum, 0, sizeof(wsum));
  for (int i = 1; i <= R; ++i) {
    char str[1000];
    scanf("%s", str);
    for (int j = 1; j <= C; ++j) {
      grid[i][j] = D + str[j-1]-'0';
      xsum[i][j] = j*grid[i][j] + xsum[i][j-1] + xsum[i-1][j] - xsum[i-1][j-1];
      ysum[i][j] = i*grid[i][j] + ysum[i][j-1] + ysum[i-1][j] - ysum[i-1][j-1];
      wsum[i][j] = grid[i][j] + wsum[i][j-1] + wsum[i-1][j] - wsum[i-1][j-1];
      //      printf("%d %d: grid %d, xsum %lld, ysum %lld\n",   i, j, grid[i][j], xsum[i][j], ysum[i][j]);
    }
  }

  int K;
  for (K = min(R, C); K >= 3; --K) {
    if (ok(K)) break;
  }
  
  if (K < 3) 
    print("Case #%d: IMPOSSIBLE\n", P);
  else
    print("Case #%d: %d\n", P, K);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
