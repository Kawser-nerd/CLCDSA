#include <cstdio>
#include <cstdint>

int main() {
  intmax_t X, Y;
  scanf("%jd %jd", &X, &Y);

  int res = 0;
  while (X <= Y) {
    ++res;
    X *= 2;
  }
  printf("%d\n", res);
}