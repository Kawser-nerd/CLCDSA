#include <cstdio>
#include <algorithm>

int main() {
  int A, B, C, X, Y;
  scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

  int res = A*X + B*Y;
  if (X < Y) {
    res = std::min({res, 2*C*X+B*(Y-X), 2*C*Y});
  } else {
    res = std::min({res, A*(X-Y)+2*C*Y, 2*C*X});
  }
  printf("%d\n", res);
}