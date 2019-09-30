#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <assert.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x, ...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef long double ld;

void PreCalc() {
}

void solve() {
  int n, c, m;
  assert(scanf("%d%d%d", &n, &c, &m) == 3);
  eprintf("%d %d %d\n", n, m, c);
  vector<int> dp(n);
  vector<int> du(c);

  for (int i = 0; i < m; i++) {
    int a, b;
    assert(scanf("%d%d", &a, &b) == 2);
//    eprintf("%d %d\n", a, b);
    --a, --b;
    assert(a >= 0 && a < n);
    assert(b >= 0 && b < c);
    dp[a]++;
    du[b]++;
  }

  int ans = *max_element(du.begin(), du.end());
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += dp[i];
    ans = max(ans, (sum + i) / (i + 1));
  }
  int ans2 = 0;
  for (int i = 0; i < n; i++) {
    ans2 += max(0, dp[i] - ans);
  }
  printf("%d %d\n", ans, ans2);
}


int main() {
#ifdef LOCAL
//  freopen("b.in", "r", stdin);
//  freopen("b.out", "w", stdout);
#endif

  PreCalc();
  TIMESTAMP(PreCalc);

  char buf[1000];
  int testNum;
  fgets(buf, sizeof buf, stdin);
  sscanf(buf, "%d", &testNum);

  for (int testId = 1; testId <= testNum; testId++) {
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
      TIMESTAMPf("Test %d", testId);
    printf("Case #%d: ", testId);
    solve();
  }

  TIMESTAMP(end);
  return 0;
}