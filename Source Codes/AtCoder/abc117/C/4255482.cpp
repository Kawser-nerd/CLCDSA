#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  if (N >= M)
    return puts("0"), 0;

  std::vector<int> X(M);
  for (auto& xi: X) scanf("%d", &xi);
  std::sort(X.begin(), X.end());

  std::vector<int> Y(M-1);
  for (size_t i = 1; i < M; ++i)
    Y[i-1] = X[i] - X[i-1];

  std::sort(Y.begin(), Y.end());
  for (size_t i = 0; i+1 < M; ++i)
    fprintf(stderr, "%d%c", Y[i], i+2<M? ' ':'\n');
  printf("%d\n", std::accumulate(Y.begin(), Y.begin()+(M-N), 0));
}