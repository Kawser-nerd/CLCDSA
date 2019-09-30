#include <cstdio>
#include <algorithm>

int main() {
  int N;
  scanf("%d", &N);

  int sum = 0;
  int max = 0;
  for (int i = 0; i < N; ++i) {
    int p;
    scanf("%d", &p);
    sum += p;
    max = std::max(max, p);
  }
  printf("%d\n", sum-max/2);
}