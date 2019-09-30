#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int T[100000];
int main() {
  int N, C, K; scanf("%d%d%d", &N, &C, &K);
  for (int i{0}; i < N; ++i) scanf("%d", &T[i]);
  sort(T, T + N);

  int total{0};
  int i{0};
  while (i < N) {
    int count{1};
    int t = T[i];
    for (++i; i < N && T[i] == t; ++i) ++count;
    for (; REMAINDER(count, C) != 0 && i < N && T[i] <= t + K; ++i) ++count;
    total += DIVUP(count, C);
  }

  printf("%d\n", total);
  return 0;
}