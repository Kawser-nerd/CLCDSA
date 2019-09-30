#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;

int H, W;
int sy, sx, gy, gx;
char grid[MAX_H][MAX_W+1];
int count[MAX_H][MAX_W];

constexpr int dy[]{-1, 0, 1, 0};
constexpr int dx[]{0, -1, 0, 1};

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
    for (int i{}; i < 4; ++i) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];
      if (ny < 0 || ny >= H ||
          nx < 0 || nx >= W ||
          ::count[ny][nx] >= 0 ||
          grid[ny][nx] == '#')
        continue;
      ::count[ny][nx] = cnt;
      que.push(P(ny, nx));
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &H, &W);
  scanf("%d%d", &sy, &sx);
  --sy;
  --sx;
  scanf("%d%d", &gy, &gx);
  --gy;
  --gx;
  for (int r{}; r < H; ++r) {
    scanf("%s", &grid[r][0]);
  }

  memset(::count, -1, sizeof(::count));
  printf("%d\n", bfs(sy, sx));
  return 0;
}