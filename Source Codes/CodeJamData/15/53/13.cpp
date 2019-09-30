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

int spd, n;
vector<pii> poses;

double ans;
void go(double pos, double tim, int got) {
  if (tim > ans) return;
  if (got == (1 << n) - 1) {
    ans = min(ans, tim);
    return;
  }
  for (int dir = -1; dir <= 1; dir += 2) {
    double ne = 1e100;
    int neid = -1;
//    eprintf("dir=%d\n", dir);
    forn (i, n) if (!(got & (1 << i))) {
      if (ll(spd) * dir * poses[i].second < 0) continue;
      double diff1 = poses[i].first + tim * poses[i].second - pos;
      double diff2 = spd * dir - poses[i].second;
//      eprintf("diff1=%.2lf diff2=%.2lf\n", diff1, diff2);
      double tmp = diff1 / diff2;
      assert(tmp >= -eps);
      if (fabs(tmp) < ne) {
        ne = fabs(tmp);
        neid = i;
      }
    }
    if (neid < 0) continue;
    go(pos + dir * spd * ne, tim + ne, got | (1 << neid));
  }
}

void solve() {
  scanf("%d%d", &spd, &n);
  poses.resize(n);
  for (pii &x : poses) scanf("%d", &x.first);
  for (pii &x : poses) {
    scanf("%d", &x.second);
    if (x.first < 0) x.second = -x.second;
  }
  ans = 1e100;
  go(0, 0, 0);
  printf("%.18e\n", ans);
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
