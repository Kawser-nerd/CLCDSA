#include <cstdio>
#include <algorithm>

int main() {
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);

  printf("%d\n", std::min(B/A, C));
}