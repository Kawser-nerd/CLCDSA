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

constexpr int MAX_R = 50;
constexpr int MAX_C = 50;

int R, C;
int sy, sx, gy, gx;
char grid[MAX_R][MAX_C+1];
int count[MAX_R][MAX_C];

constexpr int dy[]{-1, 0, 1, 0};
constexpr int dx[]{0, -1, 0, 1};

using P = pair<int, int>;

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
      if (ny < 0 || ny >= R ||
          nx < 0 || nx >= C ||
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

  memset(::count, -1, sizeof(::count));
  printf("%d\n", bfs(sy, sx));
  return 0;
}