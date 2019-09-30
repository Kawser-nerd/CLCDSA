#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <strings.h>
#include <math.h>

double prob[1000][1000];
double tmpprob[1000];


int main() {
  int N, i, j, k;
  int T;
  char buf[10000];
  int perm[1000];

  N = 1000;


  bzero(prob,sizeof(prob));
  for (i = 0; i < N; ++i)
    prob[i][i] = 1.0;

  for (k = 0; k < N; ++k) {
    for (i = 0; i < N; ++i) tmpprob[i] = prob[k][i];
    for (i = 0; i < N; ++i) {
      for (j = 0; j < N; ++j) {
	prob[i][j] = (1.0 - 1.0/N) * prob[i][j] + tmpprob[j]/N;
      }
    }
    for (i = 0; i < N; ++i) prob[k][i] = 1.0/N;
  }


  // convert to natural logs
  for (i = 0; i < N; ++i) {
    for (j = 0; j < N; ++j) {
      prob[i][j] = log(N*prob[i][j]);
      //printf("  %lf", prob[i][j]);
    }
    //printf("\n");
  }


  fgets(buf, 10000, stdin);
  sscanf(buf, "%d", &T);
  for (i = 0; i < T; ++i) {
    double score = 0.0;
    char* bufp = buf;
    int nchars;

    fgets(buf, 10000, stdin);
    sscanf(buf, "%d", &N);
    
    fgets(buf, 10000, stdin);
    for (j = 0; j < N; ++j) {
      sscanf(bufp, "%d%n", &perm[j], &nchars);
      score += prob[j][perm[j]];
      bufp += nchars;
    }
    
    //printf("%lf\n", score);

    if (score > 2) printf("Case #%d: BAD\n", i+1);
    else           printf("Case #%d: GOOD\n", i+1);
  }


}

