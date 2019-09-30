#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define H 10
#define W 10

int land_num{};
char map[H][W+1];
bool reached[H][W];

int dh[] = {1, -1,  0,  0};
int dw[] = {0,  0,  1, -1};

void dfs(int& count, int h, int w) {
  reached[h][w] = true;
  for (int i{}; i < 4; ++i) {
    int nh = h + dh[i];
    int nw = w + dw[i];
    if (nh < 0 || nh >= H || nw < 0 || nw >= W ||
      reached[nh][nw] || map[nh][nw] == 'x') continue;
    dfs(++count, nh, nw);
  }
}

int main() {
  for (int h{}; h < H; ++h) {
    scanf("%s", map[h]);
    for (int w{}; w < W; ++w) {
      if (map[h][w] == 'o') ++land_num;
    }
  }

  int count;
  if (land_num == H * W) {
    count = land_num;
  } else {
    for (int h{}; h < H; ++h) {
      for (int w{}; w < W; ++w) {
        if (map[h][w] == 'x') {
          memset(&reached[0][0], 0, sizeof(bool)*H*W);
          count = 0;
          dfs(count, h, w);
          if (count == land_num) {
            goto END;
          }
        }
      }
    }
  }

  END:
  printf("%s\n", count == land_num ? "YES" : "NO");
  return 0;
}