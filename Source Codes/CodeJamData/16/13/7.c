#include <stdio.h>

int a[11];
int dp[10][10][1<<10];
int ans;

void solve(int n) {
  ans = 0;
  int head, p, h, l;
  int nl, nh, np;
  int ok, sa;

  for (head = 0 ; head < n ; head++) {
    memset(dp, 0, sizeof(dp[0][0][0]) * 100 * (1<<10));
    dp[head][head][1<<head] = 1;
    for (p = 0 ; p < (1<<n) ; p++) {
      for (h = 0 ; h < n ; h++) {
        for (l = 0 ; l < n ; l++) {
          if (!dp[h][l][p]) {
            continue;
          }
          for (nh = 0 ; nh < n ; nh++) {
            if ((p & (1<<nh)) == 0 && (a[h] == nh || a[h] == l)) {
              np = p | (1<<nh);
              nl = h;
              dp[nh][nl][np] = 1;
            }
          }
        }
      }
    }
    for (p = 0 ; p < (1<<n) ; p++) {
      ok = 0;
      for (h = 0 ; h < n ; h++) {
        for (l = 0 ; l < n ; l++) {
          if (dp[h][l][p] && (a[h] == head || a[h] == l)) {
            ok = 1;
          }
        }
      }
      if (ok) {
        sa = 0;
        for (l = 0 ; l < n ; l++) {
          if (p & (1<<l)) {
            sa++;
          }
        }
        if (sa > ans) {
          ans = sa;
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  int T = 0;
  int n = 0;
  int t, i;
  scanf("%d", &T);
  for (t = 1 ; t <= T ; t++) {
    scanf("%d", &n);
    for (i = 0 ; i < n ; i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    solve(n);
    printf("Case #%d: %d\n", t, ans);
  }
}
