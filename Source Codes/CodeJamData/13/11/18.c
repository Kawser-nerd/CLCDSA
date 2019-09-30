#include <stdio.h>

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int r, t;
    scanf("%d%d", &r, &t);
    int ans = 0;
    while (1) {
      int need = ((r + 1) * (r + 1) - r * r);
      if (t >= need) {
        t -= need;
        ans++;
        r += 2;
      } else break;
    }
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
