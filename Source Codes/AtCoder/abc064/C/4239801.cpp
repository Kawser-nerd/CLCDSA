#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> color(9);
  for (size_t i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    ++color[std::min(a/400, 8)];
  }

  int min = 0;
  for (size_t i = 0; i < 8; ++i)
    min += (color[i]? 1:0);
    
  int max = min;
  min = std::max(min, 1);
  max += color[8];

  printf("%d %d\n", min, max);
}