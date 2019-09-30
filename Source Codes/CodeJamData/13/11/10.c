#include <stdio.h>


int main() {
  long long c, ncases, r, t, n, cur;

  scanf("%lld", &ncases);
  for (c=1; c<=ncases; c++) {
    scanf("%lld %lld", &r, &t);
    n = 0; cur=r;
    while (t >= (cur*2+1)) {
      n++;
      t -= cur*2+1;
      cur+=2;
    }
    printf("Case #%lld: %lld\n", c, n);
  }

  return 0;
}
