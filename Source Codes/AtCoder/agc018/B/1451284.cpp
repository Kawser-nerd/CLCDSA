#include <iostream>
#include <vector>
#include <set>

int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::vector<unsigned>> nm(N, std::vector<unsigned>(M));
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < M; ++j) {
      std::cin >> nm[i][j];
    }
  }
  unsigned min = N;
  std::vector<unsigned> cnt(M+1, 0);
  std::vector<unsigned> cur(N, 0);
  std::vector<bool> used(M, false);
  for (unsigned i = 0; i < M - 1; ++i) {
    std::fill(cnt.begin(), cnt.end(), 0);
    for (unsigned j = 0; j < N; ++j) {
      ++cnt[nm[j][cur[j]]];
    }
    unsigned max = 0;
    unsigned index = 0;
    for (unsigned j = 1; j <= M; ++j) {
      if (max < cnt[j]) {
        max = cnt[j];
        index = j;
      }
    }
    min = std::min(max, min);
    used[index] = true;
    for (unsigned j = 0; j < N; ++j) {
      while (used[nm[j][cur[j]]]) {
        ++cur[j];
      }
    }
  }
  std::cout << min << std::endl;
  return 0;
}