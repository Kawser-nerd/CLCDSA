#include <iostream>
using namespace std;

constexpr int MAX_H = 10;
constexpr int MAX_W = 10;

int H, W;
int sh{-1}, sw{-1}, gh{-1}, gw{-1};
char grid[MAX_H][MAX_W + 1];
bool reached[MAX_H][MAX_W];
int land_num;
int landed;

//#define OCTAS
#ifdef OCTAS
constexpr int dh[]{-1, -1, -1, 0, 0, +1, +1, +1};
constexpr int dw[]{-1, 0, +1, -1, +1, -1, 0, +1};
#else
constexpr int dh[]{-1, 0, 0, +1};
constexpr int dw[]{0, -1, +1, 0};
#endif

bool dfs(int h, int w) {
  reached[h][w] = true;
  if (++landed > land_num) {
    return true;
  }

  for (int i{}; i < sizeof(dh) / sizeof(int); ++i) {
    int nh = h + dh[i];
    if (nh < 0 || nh >= H)
      continue;
    int nw = w + dw[i];
    if (nw < 0 || nw >= W)
      continue;
    if (grid[nh][nw] == 'x' || reached[nh][nw])
      continue;
    if (dfs(nh, nw))
      return true;
  }

  return false;
}

int main() {
  H = MAX_H;
  W = MAX_W;
  for (int i{}; i < H; ++i) {
    scanf("%s", grid[i]);
    for (int j{}; j < W; ++j) {
      if (grid[i][j] == 'o')
        ++land_num;
    }
  }

  bool ans{};
  for (int i{}; i < H; ++i) {
    for (int j{}; j < W; ++j) {
      if (grid[i][j] != 'x')
        continue;
      fill(reached[0], reached[0] + MAX_H * MAX_W, false);
      landed = 0;
      if (ans = dfs(i, j))
        goto END;
    }
  }
  END:
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
} ./Main.cpp:63:15: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
      if (ans = dfs(i, j))
          ~~~~^~~~~~~~~~~
./Main.cpp:63:15: note: place parentheses around the assignment to silence this warning
      if (ans = dfs(i, j))
              ^
          (              )
./Main.cpp:63:15: note: use '==' to turn this assignment into an equality comparison
      if (ans = dfs(i, j))
              ^
              ==
1 warning generated.