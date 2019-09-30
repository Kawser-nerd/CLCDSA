#include <cstdio>
#include <cstdint>

int main() {
  intmax_t N;
  scanf("%jd", &N);

  int fN = 0;
  for (intmax_t M = N; M; M /= 10)
    fN += M % 10;

  puts((N % fN > 0)? "No":"Yes");
}