#include <cstdio>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int left = 0;
  for (int i = 1; i < b-a; ++i)
    left += i;

  printf("%d\n", left-a);
}