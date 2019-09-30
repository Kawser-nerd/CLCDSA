#include <cstdio>
#include <cstdint>

int main() {
  intmax_t x;
  scanf("%jd", &x);

  intmax_t res = x / 11 * 2;
  x %= 11;
  if (x > 6) {
    res += 2;
  } else if (x > 0) {
    ++res;
  }
  printf("%jd\n", res);
}