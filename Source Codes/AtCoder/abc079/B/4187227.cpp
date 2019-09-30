#include <cstdio>
#include <cstdint>

int main() {
  int N;
  scanf("%d", &N);

  intmax_t a = 2;
  intmax_t b = 1;
  for (int i = 0; i < N; ++i) {
    intmax_t c = a+b;
    a = b;
    b = c;
  }
  printf("%jd\n", a);
}