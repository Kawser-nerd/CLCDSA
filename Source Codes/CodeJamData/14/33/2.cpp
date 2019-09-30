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

//const int inf = 1e9;
const double eps = 1e-7;
//const int INF = inf;
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

void relax(int &a, int b) { a = min(a, b); }

const int MAXH = 31;
const int MAXK = 1010;
const int inf = 1e9;

int dyn[2][MAXH][MAXH][MAXK + 1];

void solve() {
  int h, w, k;
  scanf("%d%d%d", &h, &w, &k);
  if (h > w) swap(h, w);
  assert(h <= MAXH);
  assert(k <= MAXK);
  assert(h && w && k);

  memset(dyn, 0x3f, sizeof dyn);
  int ans = 1e9;
  for (int l = 0; l < h; l++)
  for (int r = l; r < h; r++) {
    int cnt = r - l + 1;
    dyn[0][l][r][cnt] = cnt;
    if (cnt >= k) ans = min(ans, cnt);
  }

  int cd = 1;
  int ops = 0;
  for (int x = 1; x < w; x++, cd = !cd) {
    memset(dyn[cd], 0x3f, sizeof dyn[cd]);
    for (int l1 = 0; l1 < h; l1++)
    for (int r1 = l1; r1 < h; r1++)
      for (int ocnt = 0; ocnt <= k; ocnt++) {
        int oval = dyn[!cd][l1][r1][ocnt];
        ops++;
        if (oval >= inf) continue;

//        eprintf("x=%d, %d..%d, %d: %d\n", x - 1, l1, r1, ocnt, oval);
        for (int l2 = l1 - 1; l2 <= l1 + 1; l2++)
        for (int r2 = r1 - 1; r2 <= r1 + 1; r2++)
          if (0 <= l2 && l2 <= r2 && r2 < h) {
            int ncnt = min(k, ocnt + r2 - l2 + 1);
            if (ncnt >= k) ans = min(ans, oval + r2 - l2 + 1);
            relax(dyn[cd][l2][r2][ncnt], oval + 1 + (l2 != r2));
          }
      }
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
