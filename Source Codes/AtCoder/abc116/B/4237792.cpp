#include <cstdio>

int seen[1000001];

int main() {
  int s;
  scanf("%d", &s);

  for (int i = 1; i <= 1000000; ++i) {
    if (seen[s] > 0)
      return !printf("%d\n", i);

    seen[s] = i;
    if (s % 2 == 0) {
      s /= 2;
    } else {
      s = 3*s + 1;
    }
  }
}