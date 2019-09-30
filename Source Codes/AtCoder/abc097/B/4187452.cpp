#include <cstdio>
#include <algorithm>

int main() {
  int X;
  scanf("%d", &X);

  int res = 1;
  for (int i = 2; i <= 32; ++i)
    for (int j = i*i; j <= X; j *= i)
      res = std::max(res, j);

  printf("%d\n", res);
}