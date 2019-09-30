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

int R, C, sy, sx, gy, gx;
char maze[MAX_R][MAX_C+1];
int count[MAX_R][MAX_C];

int dr[]{-1,  0,  1,  0};
int dc[]{ 0, -1,  0,  1};

int bfs(int r, int c) {
  queue<P> que;
  ::count[r][c] = 0;
  que.push(make_pair(r, c));
  while (que.size()) {
    P p = que.front(); que.pop();
    int cnt = ::count[p.first][p.second];
    if (p.first == gy && p.second == gx) return cnt;
    ++cnt;
    for (int i{}; i < 4; ++i) {
      int nr = p.first + dr[i];
      int nc = p.second + dc[i];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
          ::count[nr][nc] >= 0 || maze[nr][nc] == '#')
        continue;
      ::count[nr][nc] = cnt;
      que.push(make_pair(nr, nc));
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &R, &C);
  scanf("%d%d", &sy, &sx);
  scanf("%d%d", &gy, &gx);
  --sy; --sx; --gy; --gx;
  for (int r{}; r < R; ++r) {
    scanf("%s", maze[r]);
    for (int c{}; c < C; ++c) {
      ::count[r][c] = -1;
    }
  }

  printf("%d\n", bfs(sy, sx));
  return 0;
}