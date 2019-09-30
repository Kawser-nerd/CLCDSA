#include <iostream>
using namespace std;

constexpr int MAX_H = 10;
constexpr int MAX_W = 10;

int H, W;
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

void dfs(int &count, int h, int w) {
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
    dfs(++count, nh, nw);
  }
}

int main() {
  H = MAX_H;
  W = MAX_W;
  int land{};
  for (int h{}; h < H; ++h) {
    scanf("%s", &grid[h][0]);
    for (int w{}; w < W; ++w) {
      if (grid[h][w] == 'o') {
        ++land;
      }
    }
  }

  bool yes{};
  if (land == H * W) {
    yes = true;
  } else {
    for (int h{}; h < H; ++h) {
      for (int w{}; w < W; ++w) {
        if (grid[h][w] == 'x') {
          int count{};
          memset(&reached[0][0], 0, sizeof(bool) * H * W);
          dfs(count, h, w);
          if (count == land) {
            yes = true;
            break;
          }
        }
      }
    }
  }

  cout << (yes ? "YES" : "NO") << endl;
  return 0;
}