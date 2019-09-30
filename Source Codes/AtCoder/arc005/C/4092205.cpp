/**
 * @brief AtCoder Regular Contest 005<br>
 * C - ????????
 *
 * bfs????
 * @see https://arc005.contest.atcoder.jp/tasks/arc005_3
 */
#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_H = 500;
constexpr int MAX_W = 500;

int H, W;
int sh{-1}, sw{-1}, gh{-1}, gw{-1};
char grid[MAX_H][MAX_W + 1];
bool reached[3][MAX_H][MAX_W];

constexpr int dh[4]{-1, 0, 1, 0};
constexpr int dw[4]{0, -1, 0, 1};

struct P {
  int b, h, w;
};

bool bfs(int h, int w) {
  queue<P> que;
  reached[0][h][w] = true;
  que.push(P{0, h, w});

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    if (p.h == gh && p.w == gw)
      return true;
    for (int i{}; i < 4; ++i) {
      int nh = p.h + dh[i];
      if (nh < 0 || nh >= H)
        continue;
      int nw = p.w + dw[i];
      if (nw < 0 || nw >= W)
        continue;
      int nb = p.b + (grid[nh][nw] == '#' ? 1 : 0);
      if (nb > 2 || reached[nb][nh][nw])
        continue;
      reached[nb][nh][nw] = true;
      que.push(P{nb, nh, nw});
    }
  }

  return false;
}

int main() {
  scanf("%d%d", &H, &W);
  for (int h{0}; h < H; ++h) {
    scanf("%s", &grid[h][0]);
    for (int w{0}; w < W; ++w) {
      if (grid[h][w] == 's') {
        sh = h;
        sw = w;
      }
      if (grid[h][w] == 'g') {
        gh = h;
        gw = w;
      }
    }
  }

  printf("%s\n", bfs(sh, sw) ? "YES" : "NO");
  return 0;
}