#include <iostream>
#include <queue>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_R 50
#define MAX_C 50

using P = pair<int, int>;

char maze[MAX_R][MAX_C+1];
int cnt[MAX_R][MAX_C];
int R, C, sy, sx, gy, gx;

int dy[]{-1,  0,  1,  0};
int dx[]{ 0, -1,  0,  1};

int bfs(int r, int c) {
  queue<P> que;
  cnt[r][c] = 0;
  que.push(make_pair(r, c));

  while (que.size()) {
    P p = que.front(); que.pop();
    int count = cnt[p.first][p.second];
    if (p.first == gy && p.second == gx) return count;
    ++count;
    for (int i{}; i < 4; ++i) {
      int nr = p.first + dy[i];
      int nc = p.second + dx[i];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
          cnt[nr][nc] >= 0 || maze[nr][nc] == '#')
        continue;
      cnt[nr][nc] = count;
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
    for (int c{}; c < C; ++c) {
      cnt[r][c] = -1;
    }
    scanf("%s", maze[r]);
  }

  printf("%d\n", bfs(sy, sx));
  return 0;
}