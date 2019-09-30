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

const int MAXN = 100;
char buf[MAXN][MAXN + 1];
void solve() {
  int n;
  scanf("%d", &n);
  for (int a = 0; a < n; a++)
    scanf("%s", buf[a]);

  vector<double> wp(n), owp(n), oowp(n);
  for (int a = 0; a < n; a++) {
    int c1 = 0, c2 = 0;
    for (int b = 0; b < n; b++)
      if (buf[a][b] == '0') c2++;
      else if (buf[a][b] == '1') c1++, c2++;
    if (!c2) throw 0;
    wp[a] = (double)c1 / c2;
  }
  for (int a = 0; a < n; a++) {
    double sum = 0; int cnt = 0;
    for (int b = 0; b < n; b++)
      if (buf[a][b] != '.') {
        int c1 = 0, c2 = 0;
        for (int c = 0; c < n; c++) if (c != a && buf[b][c] != '.') {
          c2++;
          if (buf[b][c] == '1') c1++;
        }
        if (!c2) throw 0;
        sum += (double)c1 / c2;
        cnt++;
      }
    if (!cnt) throw 0;
    owp[a] = sum / cnt;
  }
  for (int a = 0; a < n; a++) {
    double sum = 0; int cnt = 0;
    for (int b = 0; b < n; b++)
      if (buf[a][b] != '.') {
        sum += owp[b];
        cnt++;
      }
    oowp[a] = sum / cnt;
  }
  for (int a = 0; a < n; a++) {
    double rpi = 0.25 * wp[a] + 0.5 * owp[a] + 0.25 * oowp[a];
    printf("%.18lf\n", rpi);
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
    printf("Case #%d:\n", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
