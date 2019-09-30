#include <cstdio>

int main() {
  int D, N;
  scanf("%d %d", &D, &N);

  int res;
  for (res = 1; true; ++res) {
    int count = 0;
    for (int j = res; j % 100 == 0; j /= 100) ++count;
    if (count == D) --N;
    if (N == 0) break;
  }
  printf("%d\n", res);
}