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

const char* str[10] = 
{
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

const int maxc = 26;
int cnt[maxc], which[maxc];

int m;
pair<int, int> perm[10];
int used[10];

void precalc() {
  memset(used, 0, sizeof(used));
  m = 0;
  while (1) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 10; ++i) {
      if (used[i]) {
        continue;
      }
      int len = (int) strlen(str[i]);
      for (int j = 0; j < len; ++j) {
        cnt[str[i][j] - 'A'] += 1;
        which[str[i][j] - 'A'] = i;
      }
    }
    bool found = 0;
    for (int c = 0; c < maxc; ++c) {
      if (cnt[c] == 1 && !used[which[c]]) {
        found = 1;
        //eprintf("(%d,%d)\n", which[c], c);
        perm[m++] = mp(which[c], c);
        used[which[c]] = 1;
      }
    }
    if (!found) {
      break;
    }
  }
  assert(m == 10);
}

const int maxn = (int) 2e3 + 10;
char s[maxn];

bool read() {
  if (scanf("%s", s) < 1) {
    return 0;
  }
  assert((int) strlen(s) < maxn);
  return 1;
}

int scnt[maxc];

int ans[10];

void solve() {
  memset(scnt, 0, sizeof(scnt));
  for (int i = 0; s[i]; ++i) {
    scnt[s[i] - 'A'] += 1;
  }
  for (int i = 0; i < 10; ++i) {
    int id = perm[i].first;
    int c = perm[i].second;

    int times = scnt[c];
    //eprintf("id = %d, c = %d, times = %d\n", id, c, times);
    ans[id] = times;
    for (int j = 0; str[id][j]; ++j) {
      int x = str[id][j] - 'A';
      assert(scnt[x] >= times);
      scnt[x] -= times;
    }
  }
  assert(count(scnt, scnt + maxc, 0) == maxc);
  string res = "";
  for (int i = 0; i < 10; ++i) {
    res += string(ans[i], i + '0');
  }
  printf("%s\n", res.c_str());
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
