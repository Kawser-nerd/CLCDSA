#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::pair<int, int>> a(N);
  for (size_t i=0; i<N; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i+1;
  }

  std::sort(a.begin(), a.end());
  for (size_t i=N; i--;)
    printf("%d\n", a[i].second);
}