#include <iostream>
#include <queue>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_H 50
#define MAX_W 50
using P = pair<int, int>;

int H, W;
char maze[MAX_H][MAX_W+1];
int cnt[MAX_H][MAX_W];
int white_num;

int dh[]{-1,  0,  1,  0};
int dw[]{ 0, -1,  0,  1};

int bfs(int h, int w) {
  queue<P> que;
  cnt[h][w] = 0;
  que.push(make_pair(h, w));

  while (que.size()) {
    P p = que.front(); que.pop();
    int count = cnt[p.first][p.second];
    if (p.first == H - 1 && p.second == W - 1) {
      return white_num - count;
    }
    ++count;
    for (int i{}; i < 4; ++i) {
      int nh = p.first + dh[i];
      int nw = p.second + dw[i];
      if (nh < 0 || nh >= H || nw < 0 || nw >= W ||
          cnt[nh][nw] >= 0 || maze[nh][nw] == '#')
        continue;
      cnt[nh][nw] = count;
      que.push(make_pair(nh, nw));
    }

  }
  return -1;
}

int main() {
  scanf("%d%d", &H, &W);
  for (int h{}; h < H; ++h) {
    scanf("%s", maze[h]);
    for (int w{}; w < W; ++w) {
      cnt[h][w] = -1;
      if (maze[h][w] == '.') ++white_num;
    }
  }
  white_num -= 1;

  printf("%d\n", bfs(0, 0));
  return 0;
}