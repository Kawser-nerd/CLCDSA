#include <stdio.h>
typedef long long unsigned int u64;

// Minimize 6x + 5y >= n. x == y, so 11x >= n, or x == y + 1, 11x - 5 >= n.

u64 min(const u64 a, const u64 b) {
  return a < b ? a : b;
}

u64 solve(u64 n) {
  u64 bestresult = 1e15;
  // Case 1:
  u64 x = (n + 10) / 11;
  bestresult = min(bestresult, 2 * x);
  // Case 2:
  x = (n + 15) / 11;
  bestresult = min(bestresult, 2 * x - 1);
  return bestresult;
}

int main(void) {
  u64 x;
  scanf("%llu", &x);
  printf("%llu", solve(x));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &x);
   ^