#include <cstdio>
#include <vector>
#include <algorithm>

int gcd(int m, int n) {
  while (n) std::swap(m %= n, n);
  return m;
}

int main() {
  int N;
  scanf("%d", &N);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    res = gcd(res, a);
  }
  printf("%d\n", res);
}