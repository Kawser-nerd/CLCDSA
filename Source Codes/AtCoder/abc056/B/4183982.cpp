#include <cstdio>
#include <algorithm>

int main() {
  int W, a, b;
  scanf("%d %d %d", &W, &a, &b);

  if (a > b) std::swap(a, b);

  if (a+W >= b) return puts("0"), 0;
  printf("%d\n", b-(a+W));
}