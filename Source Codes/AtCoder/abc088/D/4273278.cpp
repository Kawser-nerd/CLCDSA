#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;

int H, W;
int sh{-1}, sw{-1}, gh{-1}, gw{-1};
char grid[MAX_H][MAX_W + 1];
int count[MAX_H][MAX_W];

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

int bfs(int y, int x) {
  queue<P> que;
  ::count[y][x] = 0;
  que.push(P(y, x));

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int cnt = ::count[p.first][p.second];
    if (p.first == gh && p.second == gw) {
      return cnt;
    }
    ++cnt;
    for (int i{}; i < sizeof(dh) / sizeof(int); ++i) {
      int nh = p.first + dh[i];
      int nw = p.second + dw[i];
      if (nh < 0 || nh >= H ||
          nw < 0 || nw >= W ||
          ::count[nh][nw] >= 0 ||
          grid[nh][nw] == '#')
        continue;
      ::count[nh][nw] = cnt;
      que.push(P(nh, nw));
    }
  }

  return -1;
}

int main() {
  init_count();

  scanf("%d%d", &H, &W);
  int white_num{};
  for (int h{}; h < H; ++h) {
    scanf("%s", &grid[h][0]);
    for (int w{}; w < W; ++w) {
      if (grid[h][w] == '.')
        ++white_num;
    }
  }
  sh = sw = 0;
  gh = H - 1;
  gw = W - 1;
  int ret = bfs(sh, sw);

  printf("%d\n", ret < 0 ? ret : white_num - ret - 1);
  return 0;
}