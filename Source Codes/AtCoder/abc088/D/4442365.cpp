#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <tuple>

constexpr size_t di[] = {size_t(-1), 0, 1, 0};
constexpr size_t dj[] = {0, size_t(-1), 0, 1};

int main() {
  size_t H, W;
  scanf("%zu %zu", &H, &W);

  std::vector<std::string> s(H);
  for (auto& si: s) {
    char buf[64];
    scanf("%s", buf);
    si = buf;
  }

  std::queue<std::pair<size_t, size_t>> q;
  int INF = 1e9;
  std::vector<std::vector<int>> dp(H, std::vector<int>(W, INF));
  dp[0][0] = 1;
  q.emplace(0, 0);
  bool reachable = false;
  while (!q.empty()) {
    size_t i, j;
    std::tie(i, j) = q.front();
    q.pop();
    if (i+1 == H && j+1 == W) {
      reachable = true;
      break;
    }

    for (int k = 0; k < 4; ++k) {
      size_t ni = i + di[k];
      size_t nj = j + dj[k];
      if (!(ni < H && nj < W)) continue;
      if (s[ni][nj] == '#') continue;
      if (dp[ni][nj] <= dp[i][j] + 1) continue;
      dp[ni][nj] = dp[i][j] + 1;
      q.emplace(ni, nj);
    }
  }

  if (!reachable) return puts("-1"), 0;
  int res = H*W - dp[H-1][W-1];
  for (const auto& si: s)
    res -= std::count(si.begin(), si.end(), '#');

  printf("%d\n", res);
}