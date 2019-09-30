#include <cstdio>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  printf("%d00\n", (N-M+19*M)<<M);
}