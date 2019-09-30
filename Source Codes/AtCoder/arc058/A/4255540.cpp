#include <cstdio>
#include <set>

bool valid(int N, const std::set<int>& D) {
  for (int i = N; i; i /= 10)
    if (D.count(i % 10)) return false;

  return true;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  std::set<int> D;
  for (int i = 0; i < K; ++i) {
    int d;
    scanf("%d", &d);
    D.insert(d);
  }

  while (!valid(N, D)) ++N;
  printf("%d\n", N);
}