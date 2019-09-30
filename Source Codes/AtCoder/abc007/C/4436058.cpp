#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;

constexpr int MAX_R = 50;
constexpr int MAX_C = 50;

int R, C;
int sr{-1}, sc{-1}, gr{-1}, gc{-1};
char grid[MAX_R][MAX_C + 1];
int count[MAX_R][MAX_C];

//#define OCTAS
#ifdef OCTAS
constexpr int dr[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dc[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dr[]{-1, 0, 0, +1};
constexpr int dc[]{0, -1, +1, 0};
#endif

// CAUTION!!!
// Call init_count() first!!!
//
void init_count() {
  fill(::count[0], ::count[0]+MAX_R*MAX_C, -1);
}

int bfs(int r, int c) {
  queue<P> que;
  ::count[r][c] = 0;
  que.push(P(r, c));

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int cnt = ::count[p.first][p.second];
    if (p.first == gr && p.second == gc) {
      return cnt;
    }
    ++cnt;
    for (int i{}; i < sizeof(dr) / sizeof(int); ++i) {
      int nh = p.first + dr[i];
      int nw = p.second + dc[i];
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
  scanf("%d%d", &sr, &sc);
  --sr;
  --sc;
  scanf("%d%d", &gr, &gc);
  --gr;
  --gc;
  for (int h{}; h < R; ++h) {
    scanf("%s", &grid[h][0]);
  }

  printf("%d\n", bfs(sr, sc));
  return 0;
}