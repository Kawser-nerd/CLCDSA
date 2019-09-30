#include <iostream>
#include <map>
using namespace std;
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int T[100000];
int main() {
  int N, C, K; scanf("%d%d%d", &N, &C, &K);
  for (int i{0}; i < N; ++i) {
    scanf("%d", &T[i]);
  }
  sort(T, T + N);

  int total{0};
  int i{0};
  while (i < N) {
    int count{1};
    int t = T[i];
    for (++i; i < N && T[i] == t; ++i) ++count;
    for (; count % C != 0 && i < N && T[i] <= t + K; ++i) ++count;
    total += (count + (C - 1)) / C;
  }

  printf("%d\n", total);
  return 0;
}