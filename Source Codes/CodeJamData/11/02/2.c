#include <stdio.h>
#include <stdlib.h>

int ord(int c) {
  return c - 'A';
}

int chr(int o) {
  return o + 'A';
}

int next(void) {
  int c;
  do {
    c = getchar();
  } while (c < 'A' || c > 'Z');
  return ord(c);
}

enum {N_L = 26, N_MAX = 100};

int comb[N_L][N_L];
int opp[N_L][N_L];
int present[N_L];

int list[N_MAX];
int count;

int main(void) {
  int T, tt;
  scanf("%d", &T);
  for (tt = 1; tt <= T; tt++) {
    int i, j, C, D, N;
    count = 0;
    for (i = 0; i < N_L; i++) {
      present[i] = 0;
      for (j = 0; j < N_L; j++) {
        comb[i][j] = -1;
        opp[i][j] = 0;
      }
    }
    scanf("%d", &C);
    for (i = 0; i < C; i++) {
      int c1 = next();
      int c2 = next();
      int c3 = next();
      comb[c1][c2] = comb[c2][c1] = c3;
    }
    scanf("%d", &D);
    for (i = 0; i < D; i++) {
      int c1 = next();
      int c2 = next();
      opp[c1][c2] = opp[c2][c1] = 1;
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
      int c = next();
      int c2;
      int cleared = 0;
      if (count > 0 && (c2 = comb[list[count-1]][c]) != -1) {
        list[count-1] = c2;
      } else {
        for (j = 0; j < count; j++) {
          if (opp[list[j]][c]) {
            cleared = 1;
            count = 0;
            break;
          }
        }
        if (!cleared) {
          list[count] = c;
          count++;
        }
      }
    }
    printf("Case #%d: [", tt);
    for (i = 0; i < count; i++) {
      putchar(chr(list[i]));
      if (i < count - 1) {
        printf(", ");
      }
    }
    printf("]\n");
  }
  return 0;
}
