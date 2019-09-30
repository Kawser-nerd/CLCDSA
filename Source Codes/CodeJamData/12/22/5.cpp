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

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

#define EPS 1e-8

double startd;
const double SPD = 10;

inline double getFloor(int dn, double t) {
  return max((double)dn, startd - SPD * t);
}

inline bool check(double f1, double c1, double f2, double c2) {
  if (f1 + 50 > c1 + EPS) return false;
  if (f1 + 50 > c2 + EPS) return false;
  if (f2 + 50 > c2 + EPS) return false;
  if (f2 + 50 > c1 + EPS) return false;
  return true;
}

const double INF = 1e100;
inline double getMint(int f1, int c1, int f2, int c2) {
  double L = 0, R = 10000;
  if (!check(getFloor(f1, R), c1, getFloor(f2, R), c2))
    return INF;

  if (check(getFloor(f1, L), c1, getFloor(f2, L), c2))
    return L;
  for (int step = 0; step < 100; step++) {
    double M = (L + R) / 2;
    if (check(getFloor(f1, M), c1, getFloor(f2, M), c2))
      R = M;
    else
      L = M;
  }
  return (R + L) / 2;
}

int h, w;

vvi up, dn;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };


const int MAXH = 1000;
const int MAXW = 1000;

double mints[MAXH][MAXW][4];

void solve() {
  scanf("%lf%d%d", &startd, &h, &w);
  up = vvi(h, vi(w));
  dn = vvi(h, vi(w));
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
    scanf("%d", &up[y][x]);
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
    scanf("%d", &dn[y][x]);

  vector<vector<double> > ans(h, vector<double>(w, INF));
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
  for (int i = 0; i < 4; i++)
    mints[y][x][i] = -1;

  deque<pii> q;
  vvb inq(h, vb(w, false));
  q.pb(mp(0, 0));
  inq[0][0] = true;
  ans[0][0] = 0;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop_front();
    inq[y][x] = false;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

      double nt = ans[y][x];
      double mint = mints[y][x][d];
      if (mint < -EPS)
        mint = mints[y][x][d] = getMint(dn[y][x], up[y][x], dn[ny][nx], up[ny][nx]);
      if (mint >= INF / 2) continue;
      nt = max(nt, mint);
      if (nt > EPS) {
        if (getFloor(dn[y][x], nt) - dn[y][x] >= 20 - EPS)
          nt += 1.0;
        else
          nt += 10.0;
      }
      if (ans[ny][nx] > nt + EPS) {
        ans[ny][nx] = nt;
        if (!inq[ny][nx]) {
          inq[ny][nx] = true;
          q.pb(mp(nx, ny));
        }
      }
    }
  }
  printf("%.18e\n", ans[h - 1][w - 1]);
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
