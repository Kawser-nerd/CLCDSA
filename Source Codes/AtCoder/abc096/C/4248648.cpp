#include <iostream>
using namespace std;

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;

int H, W;
char grid[MAX_H][MAX_W + 1];

//#define OCTAS
#ifdef OCTAS
constexpr int dh[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dw[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dh[]{-1, 0, 0, +1};
constexpr int dw[]{0, -1, +1, 0};
#endif

bool draw(int h, int w) {
  for (int i{}; i < sizeof(dh) / sizeof(int); ++i) {
    int nh = h + dh[i];
    if (nh < 0 || nh >= H)
      continue;
    int nw = w + dw[i];
    if (nw < 0 || nw >= W)
      continue;
    if (grid[nh][nw] == '#') {
      return true;
    }
  }

  return false;
}

int main() {
  scanf("%d%d", &H, &W);
  for (int h{}; h < H; ++h) {
    scanf("%50s", &grid[h]);
  }

  bool judge{true};
  for (int h{}; h < H; ++h) {
    for (int w{}; w < W; ++w) {
      if (grid[h][w] == '.') {
        continue;
      }
      if (!(judge = draw(h, w))) {
        judge = false;
        goto END;
      }
    }
  }
END:
  printf("%s\n", judge ? "Yes" : "No");
  return 0;
} ./Main.cpp:38:19: warning: format specifies type 'char *' but the argument has type 'char (*)[51]' [-Wformat]
    scanf("%50s", &grid[h]);
           ~~~~   ^~~~~~~~
1 warning generated.