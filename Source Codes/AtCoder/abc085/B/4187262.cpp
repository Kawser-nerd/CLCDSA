#include <cstdio>
#include <set>

int main() {
  int N;
  scanf("%d", &N);

  std::set<int> s;
  for (int i = 0; i < N; ++i) {
    int d;
    scanf("%d", &d);
    s.insert(d);
  }
  printf("%zu\n", s.size());
}