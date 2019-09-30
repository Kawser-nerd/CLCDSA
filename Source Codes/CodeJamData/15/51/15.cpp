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

class Generator {
  int cur, a, c, r;
public:
  Generator() {
    scanf("%d%d%d%d", &cur, &a, &c, &r);
  }
  int operator()() {
    int res = cur;
    cur = (ll(cur) * a + c) % r;
    return res;
  }
};

#define DEBUG_TREE
#ifndef DEBUG
#undef DEBUG_TREE
#endif

class segm_tree {
  struct node {
    int mi, micnt, added;

    node() : mi(inf), micnt(0), added(0) {}
    void add(int v) {
      mi += v;
      added += v;
    }

    friend node operator+(const node &a, const node &b) {
      node res;
      res.mi = min(a.mi, b.mi);
      if (res.mi == a.mi) res.micnt += a.micnt;
      if (res.mi == b.mi) res.micnt += b.micnt;
      return res;
    }
  };
  vector<node> tr;
  int off;

  void push(int v) {
    tr[2 * v].add(tr[v].added);
    tr[2 * v + 1].add(tr[v].added);
    tr[v].added = 0;
  }

  int L, R, K;

  void _add(int v, int l, int r) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      tr[v].add(K);
      return;
    }
    assert(v < off);
    push(v);
    int m = (l + r) / 2;
    _add(2 * v, l, m);
    _add(2 * v + 1, m + 1, r);
    tr[v] = tr[2 * v] + tr[2 * v + 1];
  }

#ifdef DEBUG_TREE
#warning Debug tree
  vi vals;
#endif

public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    tr = vector<node>(2 * off);
    forn (i, n) {
      tr[off + i].mi = 0;
      tr[off + i].micnt = 1;
    }
    for (int i = off - 1; i >= 1; i--)
      tr[i] = tr[2 * i] + tr[2 * i + 1];
    #ifdef DEBUG_TREE
    vals = vi(n, 0);
    #endif
  }
  void add(int l, int r, int k) {
    L = l; R = r; K = k;
    _add(1, 0, off - 1);
    #ifdef DEBUG_TREE
    for (int i = l; i <= r; i++)
      vals[i] += k;
    get();
    #endif
  }
  int get() const {
    int res = tr[1].mi == 0 ? tr[1].micnt : 0;
    #ifdef DEBUG_TREE
    int mi = *min_element(vals.begin(), vals.end());
    int res2 = count(vals.begin(), vals.end(), mi);
    assert(mi == tr[1].mi);
    if (mi) res2 = 0;
    assert(res == res2);
    #endif
    return res;
  }
};

vi ss;
vvi chi;
int ctim;
vi stim, etim;

void dfs(int v) {
  stim[v] = ctim++;
  for (int b : chi[v]) {
    dfs(b);
  }
  etim[v] = ctim - 1;
}

struct Ev {
  int tim;
  int k, id;
  bool operator<(const Ev &e2) const {
    return tim < e2.tim;
  }
};

void solve() {
  int n, d;
  scanf("%d%d", &n, &d);
  Generator genS;
  Generator genP;

  ss = vi(n);
  forn (i, n)
    ss[i] = genS();

  chi = vvi(n);
  genP();
  for (int i = 1; i < n; i++) {
    int par = genP() % i;
    chi[par].pb(i);
  }
  ctim = 0;
  stim = vi(n);
  etim = vi(n);
  dfs(0);
  assert(ctim == n);

  vector<Ev> evs;
  forn (i, n) {
    evs.pb({ ss[i] - d, -1, i });
    evs.pb({ ss[i] + 1, +1, i });
  }
  sort(evs.begin(), evs.end());

  segm_tree tr(n);
  forn (i, n) tr.add(stim[i], etim[i], 1);

  int ans = 0;
  for (int st = 0; st < sz(evs);) {
    int current = evs[st].tim;
    while (st < sz(evs) && evs[st].tim == current) {
      int l = stim[evs[st].id];
      int r = etim[evs[st].id];
      tr.add(l, r, evs[st].k);
//      eprintf("add %d..%d; %d (%d)\n", l, r, evs[st].k, current);
      st++;
    }
    if (current <= ss[0] && ss[0] <= current + d) {
      int cnt = tr.get();
//      eprintf("   cans = %d\n", tr.get());
      ans = max(ans, cnt);
    }
  }
  assert(ans > 0);
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
  }
  return 0;
}
