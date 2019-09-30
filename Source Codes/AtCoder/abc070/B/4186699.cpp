#include <cstdio>
#include <algorithm>

int main() {
  int A, B, C, D;
  scanf("%d %d %d %d", &A, &B, &C, &D);

  int res = 0;
  for (int i = 0; i <= 200; ++i)
    if (A <= i && i < B && C <= i && i < D) ++res;

  printf("%d\n", res);
}