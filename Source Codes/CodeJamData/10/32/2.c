#include <stdio.h>

int main() {
  int i, t;
  long long l, p, c, nint, nl, r;

  scanf("%d", &t);
  for (i=1; i<=t; i++) {
    scanf("%lld %lld %lld", &l, &p, &c);
    for (nint=1, nl=l; nl<p; nint++, nl*=c);    
    for (r=0; nint>2; r++, nint = nint/2+1);
    printf("Case #%d: %lld\n", i, r);
  }

  return 0;
}
