#include <iostream>
#include <fstream>
#include <cstring>

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

int dp[3][4][101][101][101];

void PreCalc() {
  memset(dp, -1, sizeof(dp));
}

int calc(int p, int d, int c1, int c2, int c3) {
  int& ans = dp[p - 2][d][c1][c2][c3];
  if (ans != -1) return ans;
  ans = 0;
  if (c1) ans = max(ans, calc(p, (d + 1) % p, c1 - 1, c2, c3) + (d == 0));
  if (c2) ans = max(ans, calc(p, (d + 2) % p, c1, c2 - 1, c3) + (d == 0));
  if (c3) ans = max(ans, calc(p, (d + 3) % p, c1, c2, c3 - 1) + (d == 0));
  return ans;
}

void solve() {
  int n, p;
  scanf("%d%d", &n, &p);
  int ans = 0;
  int cnt[4];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a % p]++;
  }

  ans = cnt[0];
  ans += calc(p, 0, cnt[1], cnt[2], cnt[3]);
  printf("%d\n", ans);
}


int main() {
#ifdef LOCAL
  //freopen("a.in", "r", stdin);
  //freopen("a.out", "w", stdout);
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
