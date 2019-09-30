#include <cstdio>
#include <algorithm>

int main() {
  int N, M, X;
  scanf("%d %d %d", &N, &M, &X);

  int f0 = 0;
  int f1 = 0;
  for (int i = 0; i < M; ++i) {
    int A;
    scanf("%d", &A);
    ++((A < X)? f0:f1);
  }
  printf("%d\n", std::min(f0, f1));
}