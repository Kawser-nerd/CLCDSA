#include <iostream>
#include <vector>

constexpr int INF = 100000;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n, std::vector<int>(n, INF));
  std::vector<std::vector<int>> shortest(n, std::vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    g[a - 1][b - 1] = g[b - 1][a - 1] = c;
    shortest[a - 1][b - 1] = shortest[b - 1][a - 1] = c;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        shortest[i][j] =
            std::min(shortest[i][j], shortest[i][k] + shortest[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (g[i][j] != INF && shortest[i][j] < g[i][j]) ans++;
    }
  }
  std::cout << ans << std::endl;
}