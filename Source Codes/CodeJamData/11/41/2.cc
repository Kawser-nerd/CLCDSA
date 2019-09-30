#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

bool debug = false;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;
typedef set<string> ss;
typedef set<pii> spii;

const double pi = 2.0*acos(0.0);

int CASES;

void init() {
  assert(scanf("%d", &CASES) == 1);
}

int print(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  vfprintf(stderr, err, pvar);
  return vfprintf(stdout, err, pvar);
}

int dprint(const char *err, ...) { 
  if (debug) {
    va_list pvar;
    va_start(pvar, err);
    return vfprintf(stderr, err, pvar);
  }
  return 0;
}


void solve(int P) {
  int X, S, R, t, N;
  assert(scanf("%d%d%d%d%d", &X, &S, &R, &t, &N) == 5);
  int at = 0;
  vpii ivals;
  for (int i = 0; i < N; ++i) {
    int B, E, w;
    assert(scanf("%d%d%d", &B, &E, &w) == 3);
    w += S;
    if (B > at) ivals.push_back(pii(S, B-at));
    ivals.push_back(pii(w, E-B));
    at = E;
  }
  if (at < X) ivals.push_back(pii(S, X-at));
  sort(ivals.begin(), ivals.end());
  double tleft = t;
  R -= S;
  double ans = 0;
  for (vpii::iterator it = ivals.begin(); it != ivals.end(); ++it) {
    double fastt = 1.0*it->second/(it->first + R);
    if (fastt < tleft) {
      ans += fastt;
      tleft -= fastt;
    } else {
      double len = tleft*(it->first+R);
      ans += tleft + 1.0*(it->second-len)/(it->first);
      tleft = 0;
    }
  }
  print("Case #%d: %.10lf\n", P, ans);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
