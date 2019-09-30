#include <stdint.h>
#include <stdio.h>

int main() {
  int tcc, tc;
  scanf("%d", &tcc);
  for (tc = 1; tc <= tcc; ++tc) {
    uintmax_t n, k;
    scanf("%jd %jd", &n, &k);
    while (k != 1) {
      int sub = (n & 1) == 1 || (k & 1) == 0;
      n = (n >> 1) - !sub;
      k >>= 1;
    }
    printf("Case #%d: %jd %jd\n", tc, n >> 1, (n - 1) >> 1);
  }
  return 0;
}
