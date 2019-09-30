#include <cstdio>

int main() {
  int A, B;
  scanf("%d %d", &A, &B);

  int res = 0;
  for (int i = A; i <= B; ++i) {
    if (i % 10 != i / 10000) continue;
    if ((i % 100) / 10 != (i / 1000) % 10) continue;
    ++res;
  }
  printf("%d\n", res);
}