#include <stdio.h>

char *answer(int n, int k)
{
  return ((k & ((1 << n) - 1)) == ((1 << n) - 1)) ? "ON" : "OFF";
}

int main()
{
  int i, t, n, k;

  scanf("%d", &t);
  for (i = 0; i < t; ++i) {
    scanf("%d %d", &n, &k);
    printf("Case #%d: %s\n", i + 1, answer(n, k));
  }
  return 0;
}
