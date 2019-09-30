#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a%b);
}

int main() {
  int N, caseN;
  int a, b, c, d;
  int div;
  int n, pd, pg;

  scanf("%d", &N);
  for (caseN = 1; caseN <= N; caseN++) {
    scanf("%d%d%d", &n, &pd, &pg);

    div = gcd(pd, 100);

    a = pd / div;
    b = 100 / div;

    if (b > n) {
      printf("Case #%d: Broken\n", caseN);
      continue;
    }

    div = gcd(pg, 100);

    c = pg / div;
    d = 100 / div;

    if (d == c && a != b) {
      printf("Case #%d: Broken\n", caseN);
      continue;
    }

    if (pg == 0 && pd != 0) {
      printf("Case #%d: Broken\n", caseN);
      continue;
    }

    printf("Case #%d: Possible\n", caseN);
  }
  return 0;
}
