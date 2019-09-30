#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;

constexpr int MAX_R = 50;
constexpr int MAX_C = 50;

int R, C;
int sy, sx, gy, gx;
char grid[MAX_R][MAX_C + 1];
int count[MAX_R][MAX_C];

//#define OCTAS
#ifdef OCTAS
constexpr int dh[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dw[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dy[]{-1, 0, 0, +1};
constexpr int dx[]{0, -1, +1, 0};
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
    if (p.first == gy && p.second == gx) {
      return cnt;
    }
    ++cnt;
    for (int i{}; i < sizeof(dy) / sizeof(int); ++i) {
      int nh = p.first + dy[i];
      int nw = p.second + dx[i];
      if (nh < 0 || nh >= R ||
          nw < 0 || nw >= C ||
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

  scanf("%d%d", &R, &C);
  scanf("%d%d", &sy, &sx);
  --sy;
  --sx;
  scanf("%d%d", &gy, &gx);
  --gy;
  --gx;

  for (int r{}; r < R; ++r) {
    scanf("%s", &grid[r][0]);
  }

  printf("%d\n", bfs(sy, sx));
  return 0;
}