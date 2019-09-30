#include <cassert>
#include <cstddef>
#include <cstdio>
#include <limits>
#include <queue>

using namespace std;

int const kHeight = 800;
int const kWidth = 800;

int const kDRow[] = {-1, 1, 0, 0};
int const kDCol[] = {0, 0, -1, 1};

struct State {
  State() = default;
  State(int row, int col, int steps) : m_row(row), m_col(col), m_steps(steps) {}

  int m_row = 0;
  int m_col = 0;
  int m_steps = 0;
};

char g_maze[kHeight][kWidth + 1];
bool g_used[kHeight][kWidth];

int Evaluate(int h, int w, int k, int row, int col) {
  int const toLeft = (col + k - 1) / k;
  int const toRight = (w - col - 1 + k - 1) / k;
  int const toUp = (row + k - 1) / k;
  int const toDown = (h - row - 1 + k - 1) / k;
  return 1 + min(min(toLeft, toRight), min(toUp, toDown));
}

int main() {
  int h, w, k;

  scanf("%d%d%d", &h, &w, &k);
  for (int i = 0; i < h; ++i)
    scanf("%s", g_maze[i]);

  int srow = -1, scol = -1;
  for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      if (g_maze[row][col] == 'S') {
        srow = row;
        scol = col;
        g_maze[row][col] = '.';
      }
    }
  }

  int best = numeric_limits<int>::max();

  queue<State> states;
  states.emplace(srow, scol, 0);
  g_used[srow][scol] = true;

  while (!states.empty()) {
    State const s = states.front();
    states.pop();

    assert(g_maze[s.m_row][s.m_col] == '.');

    best = min(best, Evaluate(h, w, k, s.m_row, s.m_col));
    if (s.m_steps == k)
      continue;
    for (int k = 0; k < 4; ++k) {
      int const row = s.m_row + kDRow[k];
      int const col = s.m_col + kDCol[k];
      if (row < 0 || row >= h || col < 0 || col >= w)
        continue;
      if (g_maze[row][col] == '.' && !g_used[row][col]) {
        g_used[row][col] = true;
        states.emplace(row, col, s.m_steps + 1);
      }
    }
  }

  printf("%d\n", best);
  return 0;
}