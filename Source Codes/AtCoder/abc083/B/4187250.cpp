#include <cstdio>

int digsum(int n) {
  int res = 0;
  for (; n; n /= 10) res += n % 10;
  return res;
}

int main() {
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B);

  int res = 0;
  for (int i = 1; i <= N; ++i) {
    int ds = digsum(i);
    if (A <= ds && ds <= B) res += i;
  }

  printf("%d\n", res);
}