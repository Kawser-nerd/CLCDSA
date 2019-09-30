#include <cstdio>
#include <cstdint>
#include <cstdlib>

int main() {
  intmax_t N, M;
  scanf("%jd %jd", &N, &M);

  printf("%jd\n", std::abs(N-2)*std::abs(M-2));
}