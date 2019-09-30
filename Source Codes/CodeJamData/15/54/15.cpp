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

void solve() {
  int k;
  scanf("%d", &k);

  vector<pii> cnts(k);
  int cnt = 0;
  forn (i, k) scanf("%d", &cnts[i].first);
  forn (i, k) scanf("%d", &cnts[i].second), cnt += cnts[i].second;
  sort(cnts.begin(), cnts.end());

  vi ans;
  map<int, int> current;
  current[0] = 1;
  for (int ptr = 0; ptr < sz(cnts); ptr++) {
    for (;;) {
      {
        auto it = current.find(cnts[ptr].first);
        if (it != current.end() && cnts[ptr].second <= it->second) {
          assert(cnts[ptr].second == it->second);
          break;
        }
      }
      ans.pb(cnts[ptr].first);
      map<int, int> next = current;
      for (auto x : current)
        next[x.first + cnts[ptr].first] += x.second;
      current.swap(next);
    }
  }
  forn (i, sz(ans) - 1)
    assert(ans[i] <= ans[i + 1]);
  forn (i, sz(ans))
    printf("%d%c", ans[i], "\n "[i + 1 < sz(ans)]);
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
    fflush(stderr);
    fflush(stdout);
  }
  return 0;
}
