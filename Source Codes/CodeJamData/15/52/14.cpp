#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
//#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-7;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
	~__timestamper(){
		TIMESTAMP(end);
	}
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  vi sums(n - k + 1);
  forn (i, sz(sums))
    scanf("%d", &sums[i]);

  vector<pii> segs;
  forn (i, k) {
    int val = 0;
    int mi = 0, ma = 0;
    for (int i2 = i; i2 + k < n; i2 += k) {
      val += sums[i2 + 1] - sums[i2];
      mi = min(mi, val);
      ma = max(ma, val);
    }
    segs.pb(mp(mi, ma));
  }
  int nsum = sums[0] % k;
  if (nsum < 0) nsum += k;

  int ans = inf;
  forn (miid, k) {
    int cur = 0;
    int mav = segs[miid].second;

    forn (i, k) {
      int off = segs[miid].first - segs[i].first;
      cur += off;
      mav = max(mav, segs[i].second + off);
    }
    cur %= k;
    if (cur < 0) cur += k;

    int canOff = 0;
    forn (i, k) {
      int off = segs[miid].first - segs[i].first;
      int cma = segs[i].second + off;
      assert(cma <= mav);
      canOff += mav - cma;
    }
    while (cur != nsum && canOff) {
      if (++cur >= k) cur = 0;
      canOff--;
    }
    if (cur != nsum) {
      int need = nsum - cur;
      if (need < 0) need += k;
      mav += (need + k - 1) / k;
    }
    ans = min(ans, mav - segs[miid].first);
  }
  printf("%d\n", ans);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
    fflush(stderr);
    fflush(stdout);
  }
  return 0;
}
