#include <cstdio>
#include <cstdlib>
#include <algorithm>

int gcd(int m, int n) {
  while (n) std::swap(m %= n, n);
  return m;
}

int main() {
  int N, X;
  scanf("%d %d", &N, &X);

  int D = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    D = gcd(D, abs(X-x));
  }
  printf("%d\n", D);
}