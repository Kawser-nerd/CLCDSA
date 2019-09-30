#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

const size_t match[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

struct compare {
  bool operator ()(const std::string& s, const std::string& t) const {
    if (s.length() != t.length()) return s.length() < t.length();
    return s < t;
  }
} cmp;

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<int> A(M);
  for (auto& ai: A) scanf("%d", &ai);

  std::vector<std::string> dp(N+1);
  for (auto ai: A)
    if (match[ai] <= N)
      dp[match[ai]] = std::string(1, '0'+ai);

  for (size_t i = 1; i <= N; ++i) {
    for (auto ai: A) {
      size_t j = match[ai];
      if (i-j > N) continue;
      const std::string& prev = dp[i-j];
      if (prev.empty()) continue;
      char cur0 = '0'+ai;
      std::string cur = std::max(cur0+prev, prev+cur0, cmp);
      dp[i] = std::max(dp[i], cur, cmp);
    }
  }

  printf("%s\n", dp[N].c_str());
}