#include <cstdio>
#include <vector>

constexpr int MOD = 1e9+7;

int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    int A;
    scanf("%d", &A);
    if ((A % 2) == (N % 2))
      return puts("0"), 0;

    ++B[A];
    if (B[A] > 2)
      return puts("0"), 0;

    if (A == 0 && B[A] > 1)
      return puts("0"), 0;
  }

  int res = 1;
  for (int i = 1; i < N; i += 2)
    (res *= 2) %= MOD;

  printf("%d\n", res);
}