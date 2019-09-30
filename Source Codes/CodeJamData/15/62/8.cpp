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

const int MOD = int(1e9) + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}
int minv(int x) {
  assert(1 <= x && x < MOD);
  return mpow(x, MOD - 2);
}

const int MAXN = int(1e6) + 10;
int facs[MAXN + 1];
int ifacs[MAXN + 1];

int C(int n, int k) {
  assert(0 <= k && k <= n && n <= MAXN);
  return mmul(facs[n], mmul(ifacs[k], ifacs[n - k]));
}

int all[MAXN + 1];
int invk[MAXN + 1];
int non3[MAXN + 1];

void precalc() {
  facs[0] = ifacs[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    facs[i] = mmul(facs[i - 1], i);
  }
  ifacs[MAXN] = minv(facs[MAXN]);
  for (int i = MAXN; i > 0; i--) {
    ifacs[i - 1] = mmul(ifacs[i], i);
  }
  forn (i, MAXN + 1)
    assert(mmul(facs[i], ifacs[i]) == 1);
  assert(facs[5] == 120);

  forn (i, MAXN + 1)
    all[i] = mmul(facs[i], facs[i]);

  invk[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    int add = ifacs[i];
    if (i % 2 == 1) add = MOD - add;
    madd(invk[i] = invk[i - 1], add);
  }

  non3[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    non3[i] = mmul(all[i], invk[i]);
  }
}

void solve() {
  int n, x;
  scanf("%d%d", &n, &x);

  int ans = 0;
  for (int cnt3 = x; cnt3 <= n; cnt3++) {
    int cans = non3[n - cnt3];
    int curc = C(n, cnt3);
    cans = mmul(cans, curc);
    cans = mmul(cans, curc);
    cans = mmul(cans, facs[cnt3]);
    madd(ans, cans);
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
    assert(freopen((fn + ".in").c_str(), "r", stdin));
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int MARK;
  assert(scanf("%d", &MARK) >= 1);

  int START = 1, TC = MARK;
  if (MARK < 0) {
    START = TC = -MARK;
  }

  precalc();
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
