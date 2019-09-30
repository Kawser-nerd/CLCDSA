#include <iostream>
#include <vector>
#include <utility>

const int MAX_A = 300 * 300;

std::vector<int> costs(MAX_A + 1, 0);

int rec(const std::vector<std::pair<int ,int>>& positions, const int& D, int l) {
  if (positions.size() <= l + D) {
    return 0;
  }

  int x = positions[l].second, y = positions[l].first;
  int nx = positions[l + D].second, ny = positions[l + D].first;

  return costs[l] = std::abs(x - nx) + std::abs(y - ny) + rec(positions, D, l + D);
}

int main() {
  int H, W, D;
  std::cin >> H >> W >> D;

  std::vector<std::pair<int, int>> positions(H * W + 1);

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int A;
      std::cin >> A;

      positions[A] = std::make_pair(y, x);
    }
  }

  for (int i = 1; i <= H * W; i++) {
    if (costs[i] == 0) {
      rec(positions, D, i);
    }
  }

  int Q;
  std::cin >> Q;

  for (int i = 0; i < Q; i++) {
    int L, R;
    std::cin >> L >> R;

    std::cout << costs[L] - costs[R] << std::endl;
  }
}