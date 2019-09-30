#include <cstdio>

int main() {
  int A, B, K;
  scanf("%d %d %d", &A, &B, &K);

  for (int i = 100; i > 0; --i)
    if (A % i == 0 && B % i == 0)
      if (--K == 0) return !printf("%d\n", i);
}