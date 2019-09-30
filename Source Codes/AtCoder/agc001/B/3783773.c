#include <stdio.h>
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

int main() {
  long long N, X;
  scanf("%lld %lld", &N, &X);
  long long n, x;
  n = MAX(X, N-X);
  x = MIN(X, N-X);
  long long c=0;
  long long d;
  while (n && x) {
    if (n < x) {
      d = x / n;
      c += 3 * n * d;
      x %= n;
    }
    else {
      d = n / x;
      c += 3 * x * d;
      n %= x;
    }
  }
  printf("%lld\n", c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld", &N, &X);
   ^