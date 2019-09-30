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

void solve() {
  int n, f1, f;
  assert(scanf("%d %d.%d", &n, &f1, &f) == 3);
  f += f1 * 1000000;
  eprintf("n=%d, f=%d\n", n, f);

  static char buf[int(1e6) + 1];
  scanf("%s", buf);

  ll a1 = ll(4e12), b1 = ll(1);
  int ansl = -1;

  for (int l = 0; l < n; l++) {
    ll c1 = 0, call = 0;
    for (int r = l; r < n; r++) {
      c1 += buf[r] == '1'; call++;

      ll a2 = abs(c1 * 1000000 - f * call);
      ll b2 = call;
      if (a2 * b1 < a1 * b2) {
        a1 = a2;
        b1 = b2;
        ansl = l;
      }
      b2++;
    }
  }
  printf("%d\n", ansl);
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
