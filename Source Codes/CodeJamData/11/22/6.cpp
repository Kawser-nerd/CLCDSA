#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int n, d;
vi ps;
#define EPS 1e-9

bool can(double ans) {
  vector<double> pos(n);
  pos[0] = ps[0] - ans;
  for (int i = 1; i < n; i++) {
    pos[i] = max(pos[i - 1] + d, ps[i] - ans);
    if (pos[i] > ps[i] + ans + EPS) return false;
  }
  return true;
}

void solve() {
  scanf("%d%d", &n, &d);
  ps.clear();
  for (int i = 0; i < n; i++) {
    int x, cnt;
    scanf("%d%d", &x, &cnt);
    for (int i = 0; i < cnt; i++)
      ps.pb(x);
  }
  sort(ps.begin(), ps.end());
  n = sz(ps);

  double L = 0, R = 1e12;
  assert(can(R));
  if (can(L)) {
    printf("0\n");
    return;
  }
  for (int step = 0; step < 200; step++) {
    double M = (L + R) / 2;
    if (can(M)) R = M;
    else L = M;
  }
  printf("%.18lf\n", R);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "std";
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
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
