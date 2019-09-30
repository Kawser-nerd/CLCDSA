#include <cstdio>

int main() {
  int A, B, C, X;
  scanf("%d %d %d %d", &A, &B, &C, &X);

  int res = 0;
  for (int i = 0; i <= A; ++i)
    for (int j = 0; j <= B; ++j)
      for (int k = 0; k <= C; ++k)
        if (500*i + 100*j + 50*k == X)
          ++res;

  printf("%d\n", res);
}