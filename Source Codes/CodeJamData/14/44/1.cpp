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

const int MOD = int(1e9 + 7);
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

struct Node {
  int ne[26];
  int fin, me;

  Node() : fin(0), me(0) {
    memset(ne, -1, sizeof ne);
  }
  int& operator[](int x) { return ne[x]; }
  int  operator[](int x) const { return ne[x]; }
};
vector<Node> ns;

void add(const char *buf) {
  int v = 0;
  ns[v].fin++;
  for (int i = 0; buf[i]; i++) {
    int c = buf[i] - 'A';
    assert(0 <= c && c < 26);
    if (ns[v][c] < 0) {
      ns[v][c] = sz(ns);
      ns.pb(Node());
    }
    v = ns[v][c];
    ns[v].fin++;
  }
  ns[v].me++;
}

const int MAXN = 110;
int C[MAXN + 1][MAXN + 1];

int calc(int v, int cnt) {
//  eprintf("calc(%d, %d)\n", v, cnt);
  assert(ns[v].fin >= cnt);
  int tot = 1;
  vi ws;
  for (int i = 0; i < 26; i++) if (ns[v][i] >= 0) {
    int b = ns[v][i];
    int cw = min(ns[b].fin, cnt);
    int cans = calc(b, cw);
    tot = mmul(tot, cans);
    ws.pb(cw);
  }
  for (int i = 0; i < ns[v].me; i++) ws.pb(1);
  sort(ws.begin(), ws.end());
//  if (v) return 1;

//  for (int i = 0; i < sz(ws); i++) eprintf("w=%d\n", ws[i]);
//  eprintf("cnt=%d\n", cnt);

  assert(!ws.empty());
  int ans = 0;
  int sgn = 1;
  for (int k = cnt; k >= ws.back(); k--, sgn = -sgn) {
    int cans = C[cnt][k];
    for (int i = 0; i < sz(ws); i++)
      cans = mmul(cans, C[k][ws[i]]);
    if (sgn < 0) cans = MOD - cans;
    madd(ans, cans);
  }
  return mmul(ans, tot);
}

void solve() {
  int m, k;
  scanf("%d%d", &m, &k);
  ns = vector<Node>(1);
  for (int i = 0; i < m; i++) {
    static char buf[110];
    scanf("%s", buf);
    add(buf);
  }

  int ans = 0;
  assert(ns[0].fin >= k);
  for (int i = 0; i < sz(ns); i++)
    ans += min(ns[i].fin, k);

  int acnt = calc(0, k);
  printf("%d %d\n", ans, acnt);
}

void precalc() {
  for (int i = 0; i <= MAXN; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      madd(C[i][j] = C[i - 1][j - 1], C[i - 1][j]);
    }
  }
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

  precalc();

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
