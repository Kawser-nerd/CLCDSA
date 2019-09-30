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

bool _solve() {
  int n, d;
  scanf("%d%d", &n, &d);
  vi as(n);
  forn (i, n) scanf("%d", &as[i]);
  assert(2 * d <= n);

  vi diff(2 * d);
  forn (i, min(n - 1, 2 * d)) diff[i] = as[i + 1] - as[i];
  if (2 * d == n) {
    diff[2 * d - 1] = as[0] - as[n - 1];
  }

  for (int i = 0; i + 1 < n; i++) {
    if (diff[i % (2 * d)] != as[i + 1] - as[i]) return false;
  }
  n = 2 * d;
  if (accumulate(diff.begin(), diff.end(), 0) != 0) return false;

  int ans = 0;
  int begin = 0;
  while (n > 1) {
    {
      int tmp = 0;
      forn (i, n) tmp = max(tmp, abs(diff[i]));
      assert(tmp <= int(1e6));
    }
//    forn (i, n) eprintf("%d%c", diff[i], "\n "[i + 1 < n]);
    assert(n % 2 == 0);
    d = n / 2;
    forn (i, d) {
      int k = diff[d + i] - diff[i];
      if (k % 2) return false;
      k /= 2;
      ans += abs(k);
      diff[i] += k;
      diff[d + i] -= k;
      assert(diff[i] == diff[d + i]);
      if (k > 0) {
        begin += k;
      }
    }
    n /= 2;
    diff.resize(d);
  }
  assert(!diff[0]);
//  eprintf("begin=%d\n", begin);
  if (begin > as[0]) {
    return false;
  }
  printf("%d\n", ans);
  return true;
}

void solve() {
  if (!_solve()) {
    printf("CHEATERS!\n");
  }
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
