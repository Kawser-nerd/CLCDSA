#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int sum = 0;
  int min = 110;
  for (int i = 0; i < N; ++i) {
    int s;
    scanf("%d", &s);
    sum += s;
    if (s % 10 > 0 && min > s)
      min = s;
  }
  if (sum % 10 == 0) sum -= min;
  if (sum % 10 == 0) sum = 0;
  printf("%d\n", sum);
}