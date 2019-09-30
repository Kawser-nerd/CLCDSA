#include <cstdio>
#include <vector>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<int> res(N+1);
  for (size_t i = 0; i < M+M; ++i) {
    int a;
    scanf("%d", &a);
    ++res[a];
  }

  for (size_t i = 1; i <= N; ++i)
    printf("%d\n", res[i]);
}