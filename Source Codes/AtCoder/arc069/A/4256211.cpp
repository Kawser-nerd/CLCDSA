#include <cstdio>
#include <cstdint>
#include <algorithm>

int main() {
  intmax_t S, C;
  scanf("%jd %jd", &S, &C);

  intmax_t res = 0;
  if (2*S <= C) {
    res += S;
    C -= 2*S;
    res += C/4;
  } else {
    res += C/2;
  }
  printf("%jd\n", res);
}