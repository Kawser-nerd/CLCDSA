#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
#pragma warning(disable: 4267)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

char cake[26][26];

int main(void) {

  int t, T, r, R, c, C, pos, blankstart, curfill, back;

  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");

  fscanf(in,"%d",&T);
  
  for (t=1; t <= T; t++) {
    fprintf(out, "Case #%d:\n", t);
    fscanf(in, "%d", &R);
    fscanf(in, "%d", &C);
    for (r = 0; r < R; ++r) {
      fscanf(in, "%s", &cake[r][0]);
    }
    blankstart = 1;
    for (r = 0; r < R; ++r) {
      pos = -1;
      for (c = 0; c < C; ++c) {
        if (cake[r][c] != '?') {
          pos = c;
          break;
        }
      }
      if (pos > -1) {
        curfill = cake[r][pos];
        for (c = 0; c < C; ++c) {
          if (cake[r][c] == '?') {
            cake[r][c] = curfill;
          } else {
            curfill = cake[r][c];
          }
        }
        if (blankstart && r > 0) {
          for (back = 0; back < r; ++back) {
            for (c = 0; c < C; ++c) {
              cake[back][c] = cake[r][c];
            }
          }
        }
        blankstart = 0;
      } else {
        if (!blankstart) {
          for (c = 0; c < C; ++c) {
            cake[r][c] = cake[r-1][c];
          }
        }
      }
    }

    for (r = 0; r < R; ++r) {
      fprintf(out, "%s\n", &cake[r][0]);
    }
  }

  fclose(in);
  fclose(out);
}