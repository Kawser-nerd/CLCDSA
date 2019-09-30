#include <array>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

static std::array<int, 8> candidates{0};
static std::array<std::vector<int>, 10001> caches{};

const std::vector<int>* solve(int nn) {
  if (nn < 2) {
    return nullptr;
  }
  auto& cache = caches[nn];
  if (!cache.empty()) {
    return &cache;
  }
  if (nn <= 9 && candidates[nn] > 0) {
    cache.push_back(candidates[nn]);
    if (nn == 2) {
      return &cache;
    }
  }
  for (int i = 2; i <= 9; ++i) {
    int const candidate = candidates[i];
    if (candidate == 0) {
      continue;
    }
    auto previous = solve(nn - i);
    if (previous == nullptr) {
      continue;
    }
    if (previous->size() + 1 < cache.size()) {
      continue;
    }
    if (previous->size() + 1 == cache.size() &&
        previous->front() < cache.front() && candidate < cache.front()) {
      continue;
    }
    if (previous->size() + 1 > cache.size()) {
      if (!cache.empty()) {
        cache.clear();
      }
      cache.push_back(candidate);
      cache.insert(cache.end(), previous->begin(), previous->end());
      std::sort(cache.begin(), cache.end(), std::greater<int>());
    }
    std::vector<int> ccc(previous->begin(), previous->end());
    ccc.push_back(candidate);
    std::sort(ccc.begin(), ccc.end(), std::greater<int>());
    bool replace = false;
    for (int j = 0; j < cache.size(); j++) {
      if (ccc[j] < cache[j]) {
        replace = false;
        break;
      }
      if (ccc[j] > cache[j]) {
        replace = true;
        break;
      }
    }
    if (replace) {
      cache = ccc;
    }
  }
  if (!cache.empty()) {
    return &cache;
  }
  return nullptr;
}

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int n;
  int m;
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a;
    std::cin >> a;
    switch (a) {
      case 1:
        candidates[2] = std::max(a, candidates[2]);
        break;
      case 2:
        candidates[5] = std::max(a, candidates[5]);
        break;
      case 3:
        candidates[5] = std::max(a, candidates[5]);
        break;
      case 4:
        candidates[4] = std::max(a, candidates[4]);
        break;
      case 5:
        candidates[5] = std::max(a, candidates[5]);
        break;
      case 6:
        candidates[6] = std::max(a, candidates[6]);
        break;
      case 7:
        candidates[3] = std::max(a, candidates[3]);
        break;
      case 8:
        candidates[7] = std::max(a, candidates[7]);
        break;
      case 9:
        candidates[6] = std::max(a, candidates[6]);
        break;
      default:
        assert(false);
        break;
    }
  }
  for (auto& cache : caches) {
    cache.reserve(5000);
  }
  for (auto const v : *(solve(n))) {
    std::cout << "0123456789"[v];
  }
  std::cout << std::endl;
  return 0;
};