#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    res += r-l+1;
  }
  printf("%d\n", res);
}