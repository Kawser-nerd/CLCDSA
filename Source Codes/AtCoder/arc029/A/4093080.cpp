#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x, y) ((x) > (y) ? ((x) - (y)) : ((y) - (x)))

#define MOD(x, y) ((x) % (y))
#define DIVCEIL(x, y) (((x) + ((y) - 1)) / (y))
#define DIVFLOOR(x, y) (((x) + ((y) / 2)) / (y))
#define DIVROUND(x, y) ((x) - MOD(x, y) >= MOD(x, y) ? DIVCEIL(x, y) : DIVFLOOR(x, y))

int main() {
  int N;
  scanf("%d", &N);
  int t[N];
  for (int i{}; i < N; ++i) {
    scanf("%d", &t[i]);
  }
  int shorter{numeric_limits<int>::max()};
  for (int i{}; i < (1 << N); ++i) {
    int yo{}, me{};
    for (int j{}; j < N; ++j) {
      if (i & (1 << j)) {
        yo += t[j];
      } else {
        me += t[j];
      }
    }
    shorter = min(shorter, max(yo, me));
  }

  printf("%d\n", shorter);
  return 0;
}