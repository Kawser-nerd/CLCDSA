#include <cstdio>
#include <map>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::map<int, int> A;
  for (size_t i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    ++A[a];
  }

  size_t res = 0;
  for (const auto& p: A)
    res += p.second-1;

  printf("%zu\n", N-(res+1)/2*2);
}