#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  std::map<int, size_t> f;
  for (size_t i = 0; i < N; ++i) {
    int ai;
    scanf("%d", &ai);
    ++f[ai];
  }

  std::vector<size_t> B;
  for (const auto& p: f)
    B.push_back(p.second);

  std::sort(B.begin(), B.end());
  if (B.size() <= K) {
    puts("0");
  } else {
    printf("%d\n", std::accumulate(B.begin(), B.begin()+(B.size()-K), 0));
  }
}