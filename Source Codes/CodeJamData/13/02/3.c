#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

#define MAX 101

int lawn[MAX*MAX];

int maxN[MAX];
int maxM[MAX];

void reset() {
  memset(maxN,0,sizeof(int)*MAX);
  memset(maxM,0,sizeof(int)*MAX);
}

int main(void) {

  int T,t;
  int N,n;
  int M,m;
  int pos;
  int h;
  int valid;
  
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  
  fscanf(in,"%d\n",&T);

  for (t=1; t <= T; t++) {
    reset();
    fscanf(in,"%d\n",&N);
    fscanf(in,"%d\n",&M);
    for (n=0; n < N; n++) {
      for (m=0; m < M; m++) {
        pos = n*M+m;
        fscanf(in,"%d\n",&h);
        lawn[pos] = h;
        if (h > maxN[n]) {
          maxN[n] = h;
        }
        if (h > maxM[m]) {
          maxM[m] = h;
        }
      }
    }
    valid = 1;
    for (n=0; n < N; n++) {
      if (valid) {
        for (m=0; m < M; m++) {
          pos = n*M+m;
          h = lawn[pos];
          if ((maxN[n] != h)&&(maxM[m] != h)) {
            valid = 0;
            break;
          }
        }
      } else {
        break;
      }
    }
    if (valid) {
      fprintf(out,"Case #%d: YES\n", t);
    } else {
      fprintf(out,"Case #%d: NO\n", t);
    }
  }
  fclose(in);
  fclose(out);
}


