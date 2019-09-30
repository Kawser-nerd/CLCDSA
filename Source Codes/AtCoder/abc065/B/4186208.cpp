#include <cstdio>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<size_t> a(N+1);
  for (size_t i = 1; i <= N; ++i)
    scanf("%zu", &a[i]);

  int res = 0;
  size_t cur = 1;
  while (true) {
    if (a[cur] == 0) return puts("-1"), 0;
    ++res;
    size_t prev = cur;
    cur = a[cur];
    a[prev] = 0;
    if (cur == 2) break;
  }
  printf("%d\n", res);
}