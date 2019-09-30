#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;

int H, W;
char grid[MAX_H][MAX_W + 1];

#define OCTAS
#ifdef OCTAS
constexpr int dh[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dw[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dh[]{-1, 0, 0, +1};
constexpr int dw[]{0, -1, +1, 0};
#endif

int main() {
  scanf("%d%d", &H, &W);
  for (int h{}; h < H; ++h) {
    scanf("%s", &grid[h][0]);
  }

  for (int h{}; h < H; ++h) {
    for (int w{}; w < W; ++w) {
      if (grid[h][w] == '#')
        continue;
      char count{};
      for (int i{}; i < sizeof(dh) / sizeof(int); ++i) {
        int nh = h + dh[i];
        if (nh < 0 || nh >= H)
          continue;
        int nw = w + dw[i];
        if (nw < 0 || nw >= W)
          continue;
        if (grid[nh][nw] == '#')
          ++count;
      }
      grid[h][w] = '0' + count;
    }
  }

  for (int h{}; h < H; ++h) {
    printf("%s\n", &grid[h][0]);
  }

  return 0;
}