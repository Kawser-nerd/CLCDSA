#include <cstdio>
#include <algorithm>

int main() {
  int N;
  scanf("%d", &N);

  int sum = 0;
  int max = 0;
  for (int i = 0; i < N; ++i) {
    int L;
    scanf("%d", &L);
    sum += L;
    max = std::max(max, L);
  }
  if (max < sum-max) {
    puts("Yes");
  } else {
    puts("No");
  }
}