#include <stdio.h>

typedef long long int ll;

ll func(const ll n) {
  // f(0, a-1) = 1 xor 1 xor ... xor 1   (mod 2 == 0)
  // f(0, a-1) = 1 xor 1 xor ... xor a-1 (mod 2 == 1)
  // f(0, 1) = 1, f(0, 2) = 1 xor 2, f(0, 3) = 1 xor 1
  if (n % 2 == 0) {
    return ((n / 2) % 2 == 1 ? (1 ^ n) : (0 ^ n));
  }

  const ll m = n - 1;
  return ((m / 2) % 2 == 0 ? 1 : 0);
}

int main() {
  ll A, B;
  scanf("%lld %lld", &A, &B);

  if (A == B) {
    printf("%lld\n", A);
    return 0;
  }
  // f(a, b) = f(0, a-1) xor f(0, b)
  printf("%lld\n", func(A - 1) ^ func(B));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld", &A, &B);
   ^