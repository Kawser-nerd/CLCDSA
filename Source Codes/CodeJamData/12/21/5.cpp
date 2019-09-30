#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

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

#define EPS 1e-9
int n;
vector<double> js;
double sum;

bool check(int id, double perc) {
  double rest = 1 - perc;
  double minsc = js[id] + sum * perc;

  for (int i = 0; i < n; i++) if (i != id) {
    double minx = (minsc - js[i]) / sum;
    minx = max(minx, 0.0);
    if (rest > minx + EPS) {
      rest -= minx;
    } else
      return true;
  }
  return false;
}

void solve() {
  scanf("%d", &n);

  js = vector<double>(n);
  sum = 0;
  for (int i = 0; i < n; i++)
    scanf("%lf", &js[i]), sum += js[i];

  for (int i = 0; i < n; i++) {
    assert(check(i, 1));

    double L = 0, R = 1;
    if (check(i, L)) R = L;
    for (int step = 0; step < 500; step++) {
      double M = (L + R) / 2;
      if (check(i, M)) R = M;
      else L = M;
    }
    printf("%.18lf%c", 100.0 * (L + R) / 2, "\n "[i + 1 < n]);
  }
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
