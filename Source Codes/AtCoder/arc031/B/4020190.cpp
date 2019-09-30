/**
 * AtCoder Regular Contest 031
 * B - ????
 *
 * DFS????
 */
#include <iostream>

#define H 10
#define W 10

int land_num;
char grid[H][W+1];
bool reached[H][W];

int dh[]{1,  0, -1,  0};
int dw[]{0,  1,  0, -1};

void dfs(int& count, int h, int w) {
  reached[h][w] = true;
  for (int i{}; i < 4; ++i) {
    int nh = h + dh[i];
    int nw = w + dw[i];
    if (nh < 0 || nh >= H ||
        nw < 0 || nw >= W ||
        grid[nh][nw] == 'x' ||
        reached[nh][nw])
      continue;
    dfs(++count, nh, nw);
  }
}

int main() {
  for (int h{}; h < H; ++h) {
    scanf("%s", &grid[h][0]);
    for (int w{}; w < W; ++w) {
      if (grid[h][w] == 'o') ++land_num;
    }
  }

  bool judge{};
  if (land_num == H * W) {
    judge = true;
  } else {
    for (int h{}; h < H; ++h) {
      for (int w{}; w < W; ++w) {
        if (grid[h][w] == 'o') continue;
        memset(&reached[0][0], 0, sizeof(bool) * H * W);
        int count{};
        dfs(count, h, w);
        if (count == land_num) {
          judge = true;
          goto END;
        }
      }
    }
  }

END:
  printf(judge ? "YES\n" : "NO\n");
  return 0;
}