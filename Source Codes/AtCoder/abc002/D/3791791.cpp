#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_N 12
#define MAX_M (MAX_N * (MAX_N - 1) / 2)

bool rel[MAX_M][MAX_M];

int main() {
  int N, M; scanf("%d%d", &N, &M);
  int x, y;
  for (int i{}; i < M; ++i) {
    scanf("%d%d", &x, &y);
    --x; --y;
    rel[x][y] = true;
    rel[y][x] = true;
  }

  int larger{1};
  for (int i{}; i < (1 << N); ++i) {
    int num{};
    for (int j{}; j < N; ++j) {
      if (i & (1 << j)) {
        ++num;
        for (int k{j+1}; k < N; ++k) {
          if (i & (1 << k)) {
            if (!rel[j][k] || !rel[k][j]) {
              goto CONT;
            }
          }
        }
      }
    }
    if (larger < num) larger = num;
    CONT:
    ;
  }

  printf("%d\n", larger);
  return 0;
}