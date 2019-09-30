#include <stdio.h>
#include <stdint.h>

char PS[] = "RYB", SS[] = "GVO";
uint64_t N, PC[3], SC[3];
int F, L;

int findMax() {
  int b = 0;
  for (int i = 1; i < 3; ++i) {
    if (PC[i] > PC[b]) {
      b = i;
    }
  }
  return b;
}

int findMax2() {
  int b = (L == 0) ? 1 : 0;
  for (int i = 1; i < 3; ++i) {
    if (i != L && (PC[i] > PC[b] || (PC[i] == PC[b] && i == F))) {
      b = i;
    }
  }
  return b;
}

int main(void) {
  uint64_t T, PN;
  scanf("%llu", &T);
  for (uint64_t t = 0; t++ < T; ) {
    scanf("%llu %llu %llu %llu %llu %llu %llu", &N, &PC[0], &SC[2], &PC[1], &SC[0], &PC[2], &SC[1]);
    printf("Case #%llu: ", t);
    PN = 0;
    for (int i = 0; i < 3; ++i) {
      if (PC[i] < SC[i]) { printf("Impossible\n"); goto next; }
      if (PC[i] == SC[i] && PC[i] + SC[i] == N) {
        for (int j = 0; j < PC[i]; ++j) {
          printf("%c%c", PS[i], SS[i]);
        }
        printf("\n"); goto next;
      }
      if (PC[i] == SC[i] && PC[i] > 0) { printf("Impossible\n"); goto next; }
      PC[i] -= SC[i];
      PN += PC[i];
    }
    for (int i = 0; i < 3; ++i) {
      if (2 * PC[i] > PN) { printf("Impossible\n"); goto next; }
    }

    F = L = findMax();
    printf("%c", PS[L]);
    --PC[L];
    while (SC[L] > 0) {
      printf("%c%c", SS[L], PS[L]);
      --SC[L];
    }
    for (int n = 1; n < PN; ++n) {
      L = findMax2();
      printf("%c", PS[L]);
      --PC[L];
      while (SC[L] > 0) {
        printf("%c%c", SS[L], PS[L]);
        --SC[L];
      }
    }
    printf("\n");
next: ;
  }
  return 0;
}
