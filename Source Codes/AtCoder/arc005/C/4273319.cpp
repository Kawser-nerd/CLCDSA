#include <iostream>
#include <queue>
using namespace std;

struct P {
  int first;
  int second;
  int third;
};

constexpr int MAX_H = 500;
constexpr int MAX_W = 500;
constexpr int MAX_B = 2;

int H, W;
int sh{-1}, sw{-1}, gh{-1}, gw{-1};
char grid[MAX_H][MAX_W + 1];
int count[MAX_B + 1][MAX_H][MAX_W];

//#define OCTAS
#ifdef OCTAS
constexpr int dh[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dw[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dh[]{-1, 0, 0, +1};
constexpr int dw[]{0, -1, +1, 0};
#endif

// CAUTION!!!
// Call init_count() first!!!
//
void init_count() {
  // ?????????????-1???
  memset(::count, -1, sizeof(::count));
}

int bfs(int y, int x, int b) {
  queue<P> que;
  ::count[b][y][x] = 0;
  que.push(P{y, x, b});

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int cnt = ::count[p.third][p.first][p.second];
    if (p.first == gh && p.second == gw) {
      return cnt;
    }
    ++cnt;
    for (int i{}; i < sizeof(dh) / sizeof(int); ++i) {
      int nh = p.first + dh[i];
      int nw = p.second + dw[i];
      int nb = p.third;
      if (grid[nh][nw] == '#' && ++nb > MAX_B) {
        continue;
      }
      if (nh < 0 || nh >= H ||
          nw < 0 || nw >= W ||
          ::count[nb][nh][nw] >= 0)
        continue;
      ::count[nb][nh][nw] = cnt;
      que.push(P{nh, nw, nb});
    }
  }

  return -1;
}

int main() {
  init_count();
  scanf("%d%d", &H, &W);
  for (int h{}; h < H; ++h) {
    scanf("%s", &grid[h][0]);
    if (sh < 0 || gh < 0) {
      for (int w{}; w < W; ++w) {
        if (grid[h][w] == 's') {
          sh = h;
          sw = w;
        } else if (grid[h][w] == 'g') {
          gh = h;
          gw = w;
        }
      }
    }
  }

  printf("%s\n", bfs(sh, sw, 0) >= 0 ? "YES" : "NO");

  return 0;
}