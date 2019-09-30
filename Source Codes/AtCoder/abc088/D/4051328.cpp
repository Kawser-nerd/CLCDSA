/**
 * @brief AtCoder Beginner Contest 088<br>
 * D - Grid Repainting
 *
 * BFS????
 * @see https://atcoder.jp/contests/abc088/tasks/abc088_d
 */
#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;
constexpr int MAX_H = 50;
constexpr int MAX_W = 50;

int H, W;
string maze[MAX_H];
int cnt[MAX_H][MAX_W];
int white_num;

int dh[]{-1, 0, 1, 0};
int dw[]{0, -1, 0, 1};

int bfs(int h, int w) {
  queue<P> que;
  cnt[h][w] = 1;
  que.push(P(h, w));

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int count = cnt[p.first][p.second];
    if (p.first == H - 1 && p.second == W - 1)
      return white_num - count;

    ++count;
    for (int i{}; i < 4; ++i) {
      int nh = p.first + dh[i];
      int nw = p.second + dw[i];
      if (nh < 0 || nh >= H ||
          nw < 0 || nw >= W ||
          cnt[nh][nw] >= 0 ||
          maze[nh][nw] == '#')
        continue;
      cnt[nh][nw] = count;
      que.push(P(nh, nw));
    }
  }

  return -1;
}

int main() {
  cin >> H >> W;
  for (int h{}; h < H; ++h) {
    cin >> maze[h];
    for (int w{}; w < W; ++w) {
      cnt[h][w] = -1;
      if (maze[h][w] == '.')
        ++white_num;
    }
  }

  cout << bfs(0, 0) << endl;
  return 0;
}