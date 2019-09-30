#include <cstdio>

int main() {
  int x;
  scanf("%d", &x);
  for (int i = 111; i <= 999; i += 111)
    if (x <= i)
      return !printf("%d\n", i);
}