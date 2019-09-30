#include <cstdio>
#include <cstdint>
#include <cassert>

intmax_t f(intmax_t n) {
  // 1 ^ 2 ^ ... ^ n
  switch (n & 3) {
  case 0: return n;
  case 1: return 1;
  case 2: return n+1;
  case 3: return 0;
  }
  assert(false);
}

int main() {
  intmax_t A, B;
  scanf("%jd %jd", &A, &B);

  printf("%jd\n", f(A)^f(B)^A);
}