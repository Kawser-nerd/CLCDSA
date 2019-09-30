#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
#pragma warning(disable: 4267)


char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

int R[50];
int Q[50][50];
int Qlo[50][50];
int Qhi[50][50];
int pos[50];

int compare_ints(const void *a, const void *b) {
  const int *ia = a;
  const int *ib = b;
  if (*ia < *ib) { return -1; }
  if (*ia > *ib) { return 1; }
  return 0;
}

int main(void) {

  int t, T, n, N, p, P, i, amount, required, base, offset, lo, hi, count, alldone, next;

  char prev;

  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");

  fscanf(in, "%d", &T);
  
  for (t=1; t <= T; t++) {
    count = 0;
    fscanf(in, "%d", &N);
    fscanf(in, "%d", &P);
    for (n = 0; n < N; ++n) {
      fscanf(in, "%d", &R[n]);
    }
    for (n = 0; n < N; ++n) {
      for (p = 0; p < P; ++p) {
        fscanf(in, "%d", &Q[n][p]);
      }
      qsort(&Q[n], P, sizeof(int), compare_ints);
      for (p = 0; p < P; ++p) {
        Qlo[n][p] = 0;
        Qhi[n][p] = 0;
        amount = Q[n][p];
        required = R[n];
        hi = (amount * 100) / (required * 90);
        if (hi * required * 90 / 100 <= amount && amount <= hi * required * 110 / 100) {
          Qlo[n][p] = hi;
          Qhi[n][p] = hi;
          lo = hi - 1;
          while (lo * required * 90 / 100 <= amount && amount <= lo * required * 110 / 100) {
            Qlo[n][p] = lo;
            lo--;
          }
        }
      }
      //for (p = 0; p < P; ++p) {
      //  fprintf(out, "%d (%d-%d), ", Q[n][p], Qlo[n][p], Qhi[n][p]);
      //}
      //fprintf(out, "\n");
    }
    for (p = 0; p < P; ++p) {
      lo = Qlo[0][p];
      if (lo == 0) continue;
      hi = Qhi[0][p];
      for (; lo <= hi; ++lo) {
        next = 0;
        for (n = 1; n < N; ++n) {
          pos[n] = -1;
          for (i = 0; i < P; ++i) {
            if (Qlo[n][i] <= lo && lo <= Qhi[n][i]) {
              pos[n] = i;
              break;
            }
          }
          if (pos[n] == -1) {
            next = 1;
            break;
          }
        }
        if (next) continue;
        ++count;
        for (n = 1; n < N; ++n) {
          Qlo[n][pos[n]] = 0;
          Qhi[n][pos[n]] = 0;
        }
        lo = hi + 1;
      }
    }
    fprintf(out, "Case #%d: %d\n", t, count);
  }

  fclose(in);
  fclose(out);
}