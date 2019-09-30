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
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;
typedef set<string> ss;
typedef set<pii> spii;

const double pi = 2.0*acos(0.0);

int CASES;

const int MAXP = 1100000;
int ispr[2000000];
vi pr;

void init() {
  assert(scanf("%d", &CASES) == 1);
  memset(ispr, 1, sizeof(ispr));
  ispr[1] = 0;
  for (int p = 2; p <= MAXP; ++p) {
    if (ispr[p]) {
      pr.push_back(p);
      for (int q = p+p; q <= MAXP; q += p)
	ispr[q] = false;
    }
  }
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
  ll N;
  scanf("%lld", &N);
  int ans = (N > 1);
  for (vi::iterator it = pr.begin(); *it**it <= N; ++it) {
    ll p = *it, q = *it;
    int e = 1;
    while (q <= N/p) ++e, q *= p;
    ans += e-1;
  }
  print("Case #%d: %d\n", P, ans);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
