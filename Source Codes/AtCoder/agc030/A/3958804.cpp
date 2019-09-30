#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x, y) ((x) > (y) ? ((x) - (y)) : ((y) - (x)))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  int A, B, C; scanf("%d%d%d", &A, &B, &C);
  int total = MIN(B, C) * 2;
  if (B > C) {
    total += B - C;
  } else if (C > B) {
    total += MIN(A + 1, C - B);
  }

  printf("%d\n", total);
  return 0;
}