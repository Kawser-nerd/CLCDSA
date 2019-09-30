#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos(-1.0L);

const int maxn = 18 + 5;
long long tens[maxn];

void precalc() {
  tens[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    tens[i] = tens[i - 1] * 10;
  }
}

char s[maxn], q[maxn];

int n;

bool read() {
  if (scanf("%s%s", s, q) < 2) {
    return 0;
  }
  return 1;
}

int sgn(long long x) {
  return x < 0 ? -1 : !!x;
}

int avail[30];
pair<int, int> which[30];

void solve() {
  int len = (int) strlen(s);

  vector<pair<long long, pair<string, string> > > ans(1, mp(0ll, mp("", "")));
  for (int i = 0; i < len; ++i) {
    memset(avail, 0, sizeof(avail));
    for (int c = 0; c < 10; ++c) {
      if (s[i] != '?' && s[i] != c + '0') {
        continue;
      }
      for (int d = 0; d < 10; ++d) {
        if (q[i] != '?' && q[i] != d + '0') {
          continue;
        }
        if (!avail[c - d + 10]) {
          avail[c - d + 10] = 1;
          which[c - d + 10] = mp(c, d);
        }
      }
    }
    auto prev = ans;
    ans.clear();
    for (int iter = 0; iter < sz(prev); ++iter) {
      for (int i = -9; i <= 9; ++i) {
        if (!avail[i + 10]) {
          continue;
        }
        long long nval = prev[iter].first * 10 + i;
        int pos = 0;
        while (pos < sz(ans) && sgn(ans[pos].first) != sgn(nval)) {
          ++pos;
        }
        auto toadd = mp(nval, mp(prev[iter].second.first + (char) (which[i + 10].first + '0'), prev[iter].second.second + (char) (which[i + 10].second + '0')));
        if (pos == sz(ans)) {
          ans.pb(toadd);
        } else{
          if (abs(nval) < abs(ans[pos].first) || (abs(nval) == abs(ans[pos].first) && toadd < ans[pos])) {
            ans[pos] = toadd;
          }
        }
      }
    }
  }
  assert(sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    ans[i].first = abs(ans[i].first);
  }
  auto x = *min_element(ans.begin(), ans.end());
  printf("%s %s\n", x.second.first.c_str(), x.second.second.c_str());
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  int maxt;
  while (scanf("%d", &maxt) == 1) {
    for (int t = 0; t < maxt; ++t) {
      assert(read());
      printf("Case #%d: ", t + 1);
      solve();
#ifdef DEBUG
      eprintf("Time: %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
