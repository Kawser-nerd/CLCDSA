#include <stdio.h>
#include <string.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int P2(int * C) {
  return C[0] + (C[1] + 1) / 2;
}

int P3(int * C) {
  int x = min(C[1], C[2]);

  C[1] -= x;
  C[2] -= x;
  C[0] += x;

  return C[0] + (C[1] + C[2] + 2) / 3;
}

int P4(int * C) {
  int x = min(C[1], C[3]);
  C[1] -= x;
  C[3] -= x;
  C[0] += x;

  return C[0] + (C[1] + 2 * C[2] + C[3] + 3) / 4;
}

int main(void) {
  int T, P, N, G, C[4], t, n;
  scanf("%d", &T);
  for (t = 0; t++ < T; ) {

    scanf("%d %d", &N, &P);

    memset(C, 0, sizeof(C));
    for (n = 0; n < N; ++n) {
      scanf("%d", &G);
      ++C[G % P];
    }
    printf("Case #%d: %d\n", t, P == 2 ? P2(C) : P == 3 ? P3(C) : P4(C));
  }
}
