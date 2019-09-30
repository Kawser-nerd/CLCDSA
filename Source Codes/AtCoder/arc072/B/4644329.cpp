#include <cstdio>
#include <cstdint>
#include <cstdlib>

int main() {
  intmax_t X, Y;
  scanf("%jd %jd", &X, &Y);

  puts((std::abs(X-Y) > 1)? "Alice":"Brown");
}