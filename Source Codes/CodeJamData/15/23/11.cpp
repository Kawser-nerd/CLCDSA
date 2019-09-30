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

struct Ev {
  ll tim, step;
  bool operator<(const Ev &e) const {
    return tim > e.tim;
  }
};

void solve() {
  int n;
  scanf("%d", &n);
  vector<pii> hs;
  forn (i, n) {
    int d, h, m;
    scanf("%d%d%d", &d, &h, &m);
    forn (i2, h)
      hs.pb(mp(d, m + i2));
  }
  n = sz(hs);

  vector<ll> todel;
  priority_queue<Ev> evs;
  for (auto h : hs) {
    ll st = ll(360 - h.first) * h.second;
    todel.pb(st);

    ll step = 360LL * h.second;
    evs.push(Ev({ st + step, step }));
  }
  sort(todel.begin(), todel.end());

  int cur = n;
  int ans = n;
  for (ll tim : todel) {
    cur--;
    for (;;) {
      if (cur >= 2 * n) break;
      if (evs.top().tim > tim) break;
      Ev e = evs.top(); evs.pop();
      cur++;
      e.tim += e.step;
      evs.push(e);
    }
    if (cur >= 2 * n) break;
    ans = min(ans, cur);
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
  }
  return 0;
}
