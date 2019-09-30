#include <iostream>
#include <queue>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

using P = pair<int, int>;

#define MAX_R 50
#define MAX_C 50
#define INF (MAX_R*MAX_C)

int R, C;
int sy, sx, gy, gx;

char maze[MAX_R][MAX_C+1];
int d[MAX_R][MAX_C];

int dr[]{-1,  0,  1,  0};
int dc[]{ 0, -1,  0,  1};

int bfs() {
  queue<P> que;
  que.push(P(sy, sx));
  d[sy][sx] = 0;

  while (que.size()) {
    P p = que.front(); que.pop();
    if (p.first == gy && p.second == gx) break;
    for (int i{}; i < 4; ++i) {
      int ny = p.first + dr[i];
      int nx = p.second + dc[i];
      if (ny < 0 || ny >= R ||
          nx < 0 || nx >= C ||
          d[ny][nx] != INF || maze[ny][nx] == '#')
        continue;
      que.push(P(ny, nx));
      d[ny][nx] = d[p.first][p.second] + 1;
    }
  }

  return d[gy][gx];
}

int main() {
  scanf("%d%d", &R, &C);
  scanf("%d%d", &sy, &sx); --sy; --sx;
  scanf("%d%d", &gy, &gx); --gy; --gx;
  for (int i{}; i < R; ++i) {
    for (int j{}; j < C; ++j) {
      d[i][j] = INF;
    }
    scanf("%s", &maze[i][0]);
  }

  printf("%d\n", bfs());
  return 0;
}