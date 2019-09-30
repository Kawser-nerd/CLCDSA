#include <iostream>
#include <vector>

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::vector<std::pair<unsigned, unsigned>>> cond(N + 1);
  for (unsigned i = 0; i < M; ++i) {
    unsigned l, r, x;
    std::cin >> l >> r >> x;
    cond[r].push_back(std::make_pair(l, x));
  }
  std::vector<std::vector<std::vector<unsigned long long>>>
      rgb(N + 1, std::vector<std::vector<unsigned long long>>(N + 1, std::vector<unsigned long long>(N + 1, 0)));
  rgb[0][0][0] = 1;
  for (unsigned i = 0; i < N; ++i) {
    // paint max(r,g,b) == i to max(r,g,b) == i+1
    // j == 0 && k == 0
    // i == 0???????????
    if (i) {
      rgb[i + 1][0][0] += rgb[i][0][0];
      rgb[i][i + 1][0] += rgb[i][0][0];
      rgb[i][0][i + 1] += rgb[i][0][0];
      rgb[i + 1][i][0] += rgb[0][i][0];
      rgb[0][i + 1][0] += rgb[0][i][0];
      rgb[0][i][i + 1] += rgb[0][i][0];
      rgb[i + 1][0][i] += rgb[0][0][i];
      rgb[0][i + 1][i] += rgb[0][0][i];
      rgb[0][0][i + 1] += rgb[0][0][i];
      rgb[i + 1][0][0] %= MOD;
      rgb[i][i + 1][0] %= MOD;
      rgb[i][0][i + 1] %= MOD;
      rgb[i + 1][i][0] %= MOD;
      rgb[0][i + 1][0] %= MOD;
      rgb[0][i][i + 1] %= MOD;
      rgb[i + 1][0][i] %= MOD;
      rgb[0][i + 1][i] %= MOD;
      rgb[0][0][i + 1] %= MOD;
    } else {
      rgb[i + 1][0][0] += rgb[i][0][0];
      rgb[0][i + 1][0] += rgb[0][i][0];
      rgb[0][0][i + 1] += rgb[0][0][i];
    }
    for (unsigned j = 0; j < i; ++j) {
      for (unsigned k = 0; k < i; ++k) {
        if (j == k) { continue; }
        //max(r,g,b) == r
        rgb[i + 1][j][k] += rgb[i][j][k];
        rgb[i + 1][j][k] %= MOD;
        rgb[i][i + 1][k] += rgb[i][j][k];
        rgb[i][i + 1][k] %= MOD;
        rgb[i][j][i + 1] += rgb[i][j][k];
        rgb[i][j][i + 1] %= MOD;
        //max(r,g,b) == g
        rgb[i + 1][i][k] += rgb[j][i][k];
        rgb[i + 1][i][k] %= MOD;
        rgb[j][i + 1][k] += rgb[j][i][k];
        rgb[j][i + 1][k] %= MOD;
        rgb[j][i][i + 1] += rgb[j][i][k];
        rgb[j][i][i + 1] %= MOD;
        //max(r,g,b) == b
        rgb[i + 1][j][i] += rgb[k][j][i];
        rgb[i + 1][j][i] %= MOD;
        rgb[k][i + 1][i] += rgb[k][j][i];
        rgb[k][i + 1][i] %= MOD;
        rgb[k][j][i + 1] += rgb[k][j][i];
        rgb[k][j][i + 1] %= MOD;
      }
    }
    // check cond
    for (auto &c : cond[i + 1]) {
      if (c.second == 1) {
        //if max(j,k) >= l then 0
        for (unsigned j = 0; j < i + 1; ++j) {
          for (unsigned k = 0; k < i + 1; ++k) {
            if (std::max(j, k) >= c.first) {
              rgb[i + 1][j][k] = 0;
              rgb[j][i + 1][k] = 0;
              rgb[k][j][i + 1] = 0;
            }
          }
        }
      } else if (c.second == 2) {
        //if min(j,k) >= l or max(j,k) < l then 0
        for (unsigned j = 0; j < i + 1; ++j) {
          for (unsigned k = 0; k < i + 1; ++k) {
            if (std::min(j, k) >= c.first || std::max(j, k) < c.first) {
              rgb[i + 1][j][k] = 0;
              rgb[j][i + 1][k] = 0;
              rgb[k][j][i + 1] = 0;
            }
          }
        }
      } else {
        //if min(j,k) < l then 0
        for (unsigned j = 0; j < i + 1; ++j) {
          for (unsigned k = 0; k < i + 1; ++k) {
            if (std::min(j, k) < c.first) {
              rgb[i + 1][j][k] = 0;
              rgb[j][i + 1][k] = 0;
              rgb[k][j][i + 1] = 0;
            }
          }
        }
      }
    }
  }
  unsigned long long ans = rgb[N][0][0] + rgb[0][N][0] + rgb[0][0][N];
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      if (i == j) { continue; }
      ans += rgb[N][i][j];
      ans %= MOD;
      ans += rgb[i][N][j];
      ans %= MOD;
      ans += rgb[i][j][N];
      ans %= MOD;
    }
  }
  std::cout << ans;
  return 0;
}