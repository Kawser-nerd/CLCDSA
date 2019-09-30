#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int power(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}


int n;

int cnt[6];

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < 6; ++i) {
    assert(scanf("%d", cnt + i) == 1);
  }
  return 1;
}

char chs[] = "ROYGBV";

void solve() {
  int ks[3] = {cnt[0] - cnt[3], cnt[2] - cnt[5], cnt[4] - cnt[1]};
  for (int i = 0; i < 3; ++i) {
    if (ks[i] < 0) {
      printf("IMPOSSIBLE\n");
      return;
    }
  }
  int sum = ks[0] + ks[1] + ks[2];
  for (int i = 0; i < 3; ++i) {
    eprintf("%d %d\n", ks[i], cnt[i * 2]);
    if (ks[i] == 0 && cnt[i * 2] > 0) {
      if (cnt[(i * 2 + 2) % 6] || cnt[(i * 2 + 4) % 6]) {
        printf("IMPOSSIBLE\n");
        return;
      }
      string ans = "";
      for (int j = 0; j < cnt[i * 2]; ++j) {
        ans += chs[i * 2];
        ans += chs[(i * 2 + 3) % 6];
      }
      printf("%s\n", ans.c_str());
      return;
    }
  }

  int pos0 = max_element(ks, ks + 3) - ks;
  if (ks[pos0] * 2 > sum) {
    printf("IMPOSSIBLE\n");
    return;
  }

  string ans = "";

  int last = -1;
  for (; sum > 0; --sum) {
    int pos = -1;
    for (int i = 0; i < 3; ++i) {
      if (i == last) {
        continue;
      }
      if (pos == -1 || ks[pos] < ks[i]) {
        pos = i;
        continue;
      }
      if (ks[pos] == ks[i] && i == pos0) {
        pos = i;
      }
    }
    assert(ks[pos] > 0);
    //eprintf("pos = %d, pos0 = %d\n", pos, pos0);

    ks[pos] -= 1;
    ans += chs[pos * 2];
    auto &hard = cnt[(pos * 2 + 3) % 6];
    while (hard) {
      --hard;
      ans += chs[(pos * 2 + 3) % 6];
      ans += chs[pos * 2];
    }
    last = pos;
  }
  assert(!ks[0] && !ks[1] && !ks[2]);
  for (int i = 1; i < 6; i += 2) {
    assert(!cnt[i]);
  }
  printf("%s\n", ans.c_str());
  assert(ans[0] != ans.back());
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  int t;
  scanf("%d", &t);
  t = 0;
  while (1) {
    if (!read()) {
      break;
    }
    printf("Case #%d: ", ++t);
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
