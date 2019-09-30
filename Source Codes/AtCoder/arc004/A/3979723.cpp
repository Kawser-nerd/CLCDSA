#include <iostream>
#include <cmath>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x, y) ((x) > (y) ? ((x) - (y)) : ((y) - (x)))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  int N; scanf("%d", &N);
  int xy[N][2];
  for (int i{}; i < N; ++i) {
    scanf("%d%d", &xy[i][0], &xy[i][1]);
  }

  double longest{};
  for (int i{}; i < N - 1; ++i) {
    for (int j{i + 1}; j < N; ++j) {
      double x = xy[i][0] - xy[j][0];
      double y = xy[i][1] - xy[j][1];
      double len = x * x + y * y;
      if (longest < len) longest = len;
    }
  }

  printf("%f", sqrt(longest));
  return 0;
}