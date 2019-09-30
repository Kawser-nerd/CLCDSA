#include <cstdio>

int main() {
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);

  for (int X = 0; X <= 100*A; X += A)
    if (X % B == C)
      return puts("YES"), 0;

  puts("NO");
}