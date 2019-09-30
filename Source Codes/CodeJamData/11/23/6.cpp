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

int n;
int ne(int x) { return x + 1 >= n ? 0 : x + 1; }
int fir(int i, int pr, const vi &ws) {
  assert(sz(ws));
  int id = lower_bound(ws.begin(), ws.end(), pr) - ws.begin() - 1;
  if (id >= 0) return ws[id];
  return ws[sz(ws) - 1];
}

void solve() {
  int k;
  scanf("%d%d", &n, &k);

  vvi ws(n);
  for (int i = 0; i < n; i++) {
//    ws[ne(i)].pb(i);
    ws[i].pb(ne(i));
  }
  {
    vi a(k), b(k);
    for (int i = 0; i < k; i++) scanf("%d", &a[i]), a[i]--;
    for (int i = 0; i < k; i++) scanf("%d", &b[i]), b[i]--;
    for (int i = 0; i < k; i++) {
      ws[a[i]].pb(b[i]);
      ws[b[i]].pb(a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(ws[i].begin(), ws[i].end());
    ws[i].resize(unique(ws[i].begin(), ws[i].end()) - ws[i].begin());
  }

  vvi ords;
  vi was(n, 0);
  int ans = n;

  map<pii, vi> walls;
  for (int a = 0; a < n; a++)
    for (int bi = 0; bi < sz(ws[a]); bi++) {
      int miid = a;
      vi cur;
      cur.pb(a);

      int pr = a, b = ws[a][bi];
      while (b != a) {
        cur.pb(b); miid = min(miid, b);
        int old = b;
        b = fir(b, pr, ws[b]);
        pr = old;
      }

      if (a == miid) {
//        for (int i = 0; i < sz(cur); i++)
//          eprintf("%d%c", cur[i], "\n "[i + 1 < sz(cur)]);

        for (int i = 0; i < sz(cur); i++) {
          int i2 = i + 1; if (i2 >= sz(cur)) i2 = 0;
          walls[mp(cur[i], cur[i2])].pb(sz(ords));
          walls[mp(cur[i2], cur[i])].pb(sz(ords));
        }
        ords.pb(cur);
      }
      ans = min(ans, sz(cur));
    }

  vi color(n, -1);
    eprintf("ans=%d\n", ans);

  deque<int> q;
  q.pb(0);
  while (!q.empty()) {
    int id = q.front();
    q.pop_front();

    const vi &cur = ords[id];
    vb wasc(ans, false);
    bool word = true;

    for (int i = 0; i < sz(cur); i++)
      if (color[cur[i]] >= 0) {
        wasc[color[cur[i]]] = true;
      } else
        word = false;
    if (word) continue;

    int rem = 0;
    for (int i = 0; i < ans; i++)
      rem += !wasc[i];

    int p = 0;
    for (int i = 0; i < sz(cur); i++) {
      int x = cur[i];
      if (color[x] >= 0) continue;

      if (rem) {
        while (wasc[p]) p++;
      } else {
        do {
          if (++p >= ans) p = 0;
        } while (color[cur[(i + 1) % sz(cur)]] == p);
      }
      color[x] = p;
      if (!wasc[p]) rem--;
      wasc[p] = true;
    }
    assert(!rem);

    int l = sz(cur);
    for (int i = 0; i < sz(cur); i++)
      if (ne(cur[i]) != cur[(i + 1) % l]) {
        const vi &topb = walls[mp(cur[i], cur[(i + 1) % l])];
        for (int i2 = 0; i2 < sz(topb); i2++)
          q.pb(topb[i2]);
      }
  }

  printf("%d\n", ans);
  for (int i = 0; i < n; i++)
    printf("%d%c", color[i] + 1, "\n "[i + 1 < n]);
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
