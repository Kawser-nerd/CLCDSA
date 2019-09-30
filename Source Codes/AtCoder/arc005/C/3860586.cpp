#include <iostream>
#include <queue>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_H 500
#define MAX_W 500

int H, W, sh{-1}, sw, gh{-1}, gw;
char maze[MAX_H][MAX_W+1];
bool reached[MAX_H][MAX_W][3];
int dh[4]{-1,  0,  1,  0};
int dw[4]{ 0, -1,  0,  1};

struct P {
  int h, w, b;
};

bool bfs(int h, int w, int b) {
  queue<P> que;
  reached[h][w][b] = true;
  que.push(P{h, w, b});

  while (que.size()) {
    P p = que.front(); que.pop();
    if (p.h == gh && p.w == gw) return true;
    for (int i{}; i < 4; ++i) {
      int nh = p.h + dh[i];
      int nw = p.w + dw[i];
      int nb = p.b;
      if (nh < 0 || nh >= H || nw < 0 || nw >= W ||
          reached[nh][nw][nb] || maze[nh][nw] == 's') {
        continue;
      }
      if (maze[nh][nw] == '#') {
        if (--nb < 0) continue;
      }
      reached[nh][nw][nb] = true;
      que.push(P{nh, nw, nb});
    }
  }

  return false;
}

int main() {
  scanf("%d%d", &H, &W);
  for (int i{}; i < H; ++i) {
    scanf("%s", maze[i]);
    if (sh < 0 || gh < 0) {
      for (int j{}; j < W; ++j) {
        if (sh < 0 && maze[i][j] == 's') {
          sh = i;
          sw = j;
        } else if (gh < 0 && maze[i][j] == 'g') {
          gh = i;
          gw = j;
        }
      }
    }
  }

  printf("%s\n", bfs(sh, sw, 2) ? "YES" : "NO");
  return 0;
}