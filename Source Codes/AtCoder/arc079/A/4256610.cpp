#include <cstdio>
#include <set>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::set<size_t> one, en;
  for (size_t i = 0; i < M; ++i) {
    size_t a, b;
    scanf("%zu %zu", &a, &b);

    if (a == 1) one.insert(b);
    if (b == N) en.insert(a);
  }

  for (auto b: one)
    if (en.count(b))
      return puts("POSSIBLE"), 0;

  puts("IMPOSSIBLE");
}