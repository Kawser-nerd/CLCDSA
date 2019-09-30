#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  int N; scanf("%d", &N);
  int t[N];
  for (int i{}; i < N; ++i) scanf("%d", &t[i]);

  int time{50 * N};
  for (int i{}; i < (1 << N); ++i) {
    int sum1{}, sum2{};
    for (int j{}; j < N; ++j) {
      if (i & (1 << j))
        sum1 += t[j];
      else
        sum2 += t[j];
    }
    time = MIN(time, MAX(sum1, sum2));
  }

  printf("%d\n", time);
  return 0;
}