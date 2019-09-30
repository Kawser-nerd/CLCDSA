#include <cstdio>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> four(3);
  for (size_t i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    if (a % 4 == 0) {
      ++four[2];
    } else if (a % 4 == 2) {
      ++four[1];
    } else {
      ++four[0];
    }
  }

  if (four[0] > four[2]+1)
    return puts("No"), 0;

  if (four[0] == four[2]+1 && four[1])
    return puts("No"), 0;

  puts("Yes");
}