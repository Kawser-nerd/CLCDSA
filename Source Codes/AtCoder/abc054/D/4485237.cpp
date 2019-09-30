#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF = 10000000;

int main() {
  int n, ma, mb;
  std::cin >> n >> ma >> mb;
  std::vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i] >> c[i];
  }
  std::vector<std::vector<std::vector<int>>> t(
      401, std::vector<std::vector<int>>(401, std::vector<int>(2, INF)));
  t[0][0][0] = 0;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 401; i++) {
      for (int j = 0; j < 401; j++) {
        int idx = k % 2;
        int idx2 = (k + 1) % 2;
        if (i - b[k] >= 0 && j - a[k] >= 0) {
          t[i][j][idx2] =
              std::min(t[i][j][idx], t[i - b[k]][j - a[k]][idx] + c[k]);
        } else {
          t[i][j][idx2] = t[i][j][idx];
        }
      }
    }
  }
  int ans = INF;
  for (int i = 1; i < 401; i++) {
    for (int j = 1; j < 401; j++) {
      if (i * ma == j * mb) {
        ans = std::min(ans, t[i][j][n % 2]);
      }
    }
  }
  std::cout << ((ans == INF) ? -1 : ans) << std::endl;
}