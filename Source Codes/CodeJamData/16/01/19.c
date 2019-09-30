#include <string.h>
#include <stdio.h>

int go(int N)
{
  if (!N) {
    return 0;
  }
  char seen[10];
  memset(seen, 0, 10);
  int n_seen = 0;

  for (int i = 1;; i++) {
    int n = i * N;
    while (n) {
      int d = n % 10;
      if (!seen[d]) {
        seen[d] = 1;
        n_seen++;
        if (n_seen == 10) {
          return i * N;
        }
      }
      n /= 10;
    }
  }
}

int main()
{
  int T, ret;
  ret = scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    int N;
    ret = scanf("%d", &N);
    ret = go(N);
    if (!ret) {
      printf("Case #%d: INSOMNIA\n", i + 1);
    }
    else {
      printf("Case #%d: %d\n", i + 1, ret);
    }
  }
}
