#include <cstdio>
#include <algorithm>

int main() {
  int A, B, C;
  int K;
  scanf("%d %d %d %d", &A, &B, &C, &K);

  int res = A + B + C - std::max({A, B, C});
  res += std::max({A, B, C}) << K;
  printf("%d\n", res);
}