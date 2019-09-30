#include <bits/stdc++.h>

using namespace std;

int a[1234567];

inline bool check(int n) {
  int total = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    total += a[i];
    mx = max(mx, a[i]);
  }
  return (2 * mx <= total);
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d:", qq);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    while (true) {
      start: ;
      bool done = true;
      for (int i = 0; i < n; i++) {
        done &= (a[i] == 0);
      }
      if (done) {
        break;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
          a[i]--;
          if (check(n)) {
            printf(" %c", 'A' + i);
            goto start;
          }
          a[i]++;
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
          a[i]--;
          for (int j = i; j < n; j++) {
            if (a[j] > 0) {
              a[j]--;
              if (check(n)) {
                printf(" %c%c", 'A' + i, 'A' + j);
                goto start;
              }
              a[j]++;
            }
          }
          a[i]++;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
