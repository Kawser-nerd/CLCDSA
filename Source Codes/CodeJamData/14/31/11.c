#include <stdio.h>

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  long long p, q;
  int t, ti;
  scanf("%d", &t);
  for (ti = 1; ti <= t; ti++) {
    scanf("%lld/%lld", &p, &q);
    long long g = gcd(p, q);
    p /= g;
    q /= g;
    long long a = 1;
    while (a < q) {
      a *= 2;
      if (a > q) {
        a = -1;
        break;
      }
    }
    if (a == -1)
      printf("Case #%d: impossible\n", ti);
    else {
      int answer = 1;
      while (p * 2 < q) {
        answer += 1;
        p *= 2;
      }
      printf("Case #%d: %d\n", ti, answer);
    }
  }
}
