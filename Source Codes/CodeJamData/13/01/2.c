#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

char grid[18];

char *winX = "X won";
char *winO = "O won";
char *draw = "Draw";
char *inc = "Game has not completed";

char *outcome;

int check[10][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15},{0,4,8,12},{1,5,9,13},{2,6,10,14},{3,7,11,15},{0,5,10,15},{3,6,9,12}};

int main(void) {

  int N;
  int i,j,k,n;
  int good;
  char c;
  
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  
  fscanf(in,"%d\n",&N);

  for (n=1; n <= N; n++) {
    for (i=0; i < 4; i++) {
      fscanf(in,"%s",grid + i*4);
    }

    outcome = NULL;

    for (j=0; j < 10; j++) {
      good = 1;
      for (k=0; k < 4; k++) {
        c = grid[check[j][k]];
        if ((c=='O')||(c=='.')) {
          good = 0;
        }
      }
      if (good) {
        outcome = winX;
        break;
      }
    }
    if (!outcome) {
      for (j=0; j < 10; j++) {
        good = 1;
        for (k=0; k < 4; k++) {
          c = grid[check[j][k]];
          if ((c=='X')||(c=='.')) {
            good = 0;
          }
        }
        if (good) {
          outcome = winO;
          break;
        }
      }
    }
    if (!outcome) {
      outcome = draw;
      for (i=0; i < 16; i++) {
        if (grid[i] == '.') {
          outcome = inc;
          break;
        }
      }
    }
    fprintf(out,"Case #%d: %s\n", n, outcome);
  }
  fclose(in);
  fclose(out);
}
