#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int inf = int(1e9);
vi knapsack(const vector<pii> &as) {
  vi d(1, 0);
  for (pii p : as) {
    vi nd(sz(d) + p.first, -inf);

    forn (i, sz(nd)) {
      if (i < sz(d)) {
        nd[i] = max(nd[i], d[i]);
      }
      if (i >= p.first && d[i - p.first] >= 0) {
        nd[i] = max(nd[i], d[i - p.first] + p.second);
      }
    }
    d.swap(nd);
  }
  return d;
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  int asum = 0;
  vvi sps(n, vi(m));
  forn (i, n)
  forn (i2, m) {
    scanf("%d", &sps[i][i2]);
    asum += sps[i][i2];
    sps[i][i2] = -sps[i][i2];
  }

  assert(m == 1 || m == 2);
  int ans = 0;
  if (m == 1) {
    forn (i, n)
      ans += max(0, sps[i][0]);
  } else {
    forn (ty, 2) {
      vector<pii> pts;
      int ax = 0, ay = 0;
      int bx = 0, by = 0;
      forn (i, n) {
        int x = sps[i][0], y = sps[i][1];
        if (x >= 0 && y >= 0) {
          ax += x;
          ay += y;
        }
        if (x >= 0 && y < 0) {
          ax += x;
          ay += y;
          pts.pb(mp(x, -y));
        }
        if (x < 0 && y >= 0) {
          bx += x;
          by += y;
        }
      }
      vi sums = knapsack(pts);
      for (int dx = 0; dx < sz(sums); dx++) if (sums[dx] > -inf) {
        int resx = ax - dx;
        int resy = ay + sums[dx] + by;
        assert(0 <= resx);
        int cans = resx + max(0, resy);
        ans = max(ans, cans);
      }

      forn (i, n) swap(sps[i][0], sps[i][1]);
    }
  }
  printf("%d\n", ans + asum);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    assert(freopen((fn + ".in").c_str(), "r", stdin));
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int MARK;
  assert(scanf("%d", &MARK) >= 1);

  int START = 1, TC = MARK;
  if (MARK < 0) {
    START = TC = -MARK;
  }
  for (int TN = START; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
    fflush(stdout);
    fflush(stderr);
  }
  return 0;
}
