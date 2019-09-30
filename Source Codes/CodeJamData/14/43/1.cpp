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

struct pt {
  int x, y;
  pt() : x(0), y(0) {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  int dist() const { return max(abs(x), abs(y)); }
};
struct Rect {
  int x1, y1, x2, y2;
  void norm() {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
  }
  void flip() {
    swap(x1, y1);
    swap(x2, y2);
  }
  void print() {
    eprintf("[%d..%d]x[%d..%d]\n", x1, x2, y1, y2);
  }
};

int getd(Rect a, Rect b) {
  pt as[] = { pt(a.x1, a.y1), pt(a.x1, a.y2), pt(a.x2, a.y1), pt(a.x2, a.y2) };
  pt bs[] = { pt(b.x1, b.y1), pt(b.x1, b.y2), pt(b.x2, b.y1), pt(b.x2, b.y2) };
  int ans = inf;
  for (int i = 0; i < 4; i++)
  for (int j = 0; j < 4; j++)
    ans = min(ans, (bs[j] - as[i]).dist() - 1);

  for (int s = 0; s < 2; s++, a.flip(), b.flip()) {
    if (a.x2 < b.x1) continue;
    if (b.x2 < a.x1) continue;

    if (a.y2 < b.y1) {
      ans = min(ans, b.y1 - a.y2 - 1);
    } else if (b.y2 < a.y1) {
      ans = min(ans, a.y1 - b.y2 - 1);
    } else {
      assert(false);
    }
  }
  assert(ans >= 0);
  return ans;
}

void solve() {
  int w, h, n;
  scanf("%d%d%d", &w, &h, &n);
  vector<Rect> rs(n);
  for (Rect &r : rs) {
    scanf("%d%d%d%d", &r.x1, &r.y1, &r.x2, &r.y2);
    r.norm();
  }

  {
    Rect r;
    r.x1 = r.x2 = -1;
    r.y1 = 0; r.y2 = h - 1;
    rs.pb(r);
  }
  {
    Rect r;
    r.x1 = r.x2 = w;
    r.y1 = 0; r.y2 = h - 1;
    rs.pb(r);
  }
  n = sz(rs);
  vi d(n, inf);
  priority_queue<pii> q;
  d[n - 2] = 0;
  q.push(mp(-d[n - 2], n - 2));

  while (!q.empty()) {
  	int cd = -q.top().first;
  	int a = q.top().second;
  	q.pop();
  	if (cd != d[a]) continue;

//  	eprintf("dist=%d, rect=", cd);
//  	rs[a].print();
    for (int b = 0; b < n; b++) if (a != b) {
      int nd = d[a] + getd(rs[a], rs[b]);
      if (nd < d[b]) {
        d[b] = nd;
        q.push(mp(-nd, b));
      }
    }
  }
  printf("%d\n", d[n - 1]);
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
