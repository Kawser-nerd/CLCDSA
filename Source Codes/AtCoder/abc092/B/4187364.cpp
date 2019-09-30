#include <cstdio>

int main() {
  int N;
  int D, X;
  scanf("%d %d %d", &N, &D, &X);

  for (int i = 0; i < N; ++i) {
    int A;
    scanf("%d", &A);
    for (int j = 1; j <= D; j += A)
      ++X;
  }
  printf("%d\n", X);
}