#include <stdio.h>

int cnt[100];
char ans[10005];

int main() {
  int t, ti, n, ni, total, ptr, max, check;
  scanf("%d", &t);
  for (ti = 1; ti <= t; ti++) {
    total = 0;
    scanf("%d", &n);
    for (ni = 0; ni < n; ni++) {
      scanf("%d", &cnt[ni]);
      total += cnt[ni];
    }
    ptr = 0;
    while (total > 0) {
      max = 0;
      for (ni = 1; ni < n; ni++) {
        if (cnt[ni] > cnt[max])
          max = ni;
      }
      cnt[max]--;
      total--;
      ans[ptr++] = max + 'A';
      check = 1;
      for (ni = 0; ni < n; ni++)
        if (cnt[ni] * 2 > total)
          check = 0;
      if (check)
        ans[ptr++] = ' ';
    }
    if (ans[ptr - 1] == ' ')
      ans[ptr - 1] = '\0';
    else
      ans[ptr] = '\0';
    printf("Case #%d: %s\n", ti, ans);
  }
  return 0;
}
