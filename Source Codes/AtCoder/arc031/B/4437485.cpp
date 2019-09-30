#include <iostream>
using namespace std;

constexpr int MAX_H = 10;
constexpr int MAX_W = 10;

int H, W;
int sh{-1}, sw{-1}, gh{-1}, gw{-1};
char grid[MAX_H][MAX_W + 1];
bool reached[MAX_H][MAX_W];

//#define OCTAS
#ifdef OCTAS
constexpr int dh[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dw[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dh[]{-1, 0, 0, +1};
constexpr int dw[]{0, -1, +1, 0};
#endif

void dfs(int h, int w) {
  reached[h][w] = true;

  for (int i{}; i < sizeof(dh) / sizeof(int); ++i) {
    int nh = h + dh[i];
    if (nh < 0 || nh >= H)
      continue;
    int nw = w + dw[i];
    if (nw < 0 || nw >= W)
      continue;
    if (grid[nh][nw] == 'x' || reached[nh][nw])
      continue;
    dfs(nh, nw);
  }
}

int main() {
  H = MAX_H;
  W = MAX_W;
  int land_num{};
  for (int i{}; i < H; ++i) {
    scanf("%s", grid[i]);
    for (int j{}; j < W; ++j) {
      if (grid[i][j] == 'o')
        ++land_num;
    }
  }

  bool ans{false};
  for (int i{}; i < H; ++i) {
    for (int j{}; j < W; ++j) {
      fill(reached[0], reached[0] + MAX_H * MAX_W, false);
      dfs(i, j);
      int visited{};
      for (int m{}; m < H; ++m) {
        for (int n{}; n < W; ++n) {
          if (reached[m][n])
            ++visited;
        }
      }
      if (visited == land_num + 1) {
        ans = true;
        break;
      }
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}