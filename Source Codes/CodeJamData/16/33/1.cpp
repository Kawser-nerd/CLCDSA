#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int j, p, s, k;
    scanf("%d %d %d %d", &j, &p, &s, &k);
    k = min(k, s);
    printf("%d\n", j * p * k);
    for (int a = 1; a <= j; a++) {
      for (int b = 1; b <= p; b++) {
        int c = (a + b - 1) % s + 1;
        for (int it = 0; it < k; it++) {
          printf("%d %d %d\n", a, b, c);
          c = c % s + 1;
        }
      }
    }
  }
  return 0;
}
