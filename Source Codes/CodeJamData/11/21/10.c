#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
int N;
char matrix[MAX][MAX+1];
int games[MAX], wins[MAX];
double owp[MAX], oowp[MAX];

int main ()
{
  int tests;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input
    scanf("%d\n", &N);
    for (int i=0; i<N; i++) {
      scanf("%s\n", matrix[i]);
      debug("(%s)\n", matrix[i]);
      games[i] = wins[i] = 0;
      for (int j=0; j<N; j++) {
        if (matrix[i][j] != '.') games[i]++;
        if (matrix[i][j] == '1') wins[i]++;
      }
    }
    // calculate owp's
    for (int i=0; i<N; i++) {
      double sum = 0.0;
      int num = 0;
      for (int j=0; j<N; j++)
        if (matrix[i][j] != '.') {
          int w = wins[j];
          if (matrix[i][j] == '0') w--;
          sum += (double) w / (games[j]-1);
          num ++;
        }
      owp[i] = sum / num;
    }
    // calculate oowp's
    for (int i=0; i<N; i++) {
      double sum = 0.0;
      int num = 0;
      for (int j=0; j<N; j++)
        if (matrix[i][j] != '.') {
          sum += owp[j];
          num++;
        }
      oowp[i] = sum / num;
    }
    // print
    printf("Case #%d:\n", test);
    for (int i=0; i<N; i++) {
      double wp = (double) wins[i] / games[i];
      debug("%d %d %0.3lf %0.3lf %0.3lf\n",
            wins[i], games[i], wp, owp[i], oowp[i]);
      double rpi = 0.25 * wp + 0.5 * owp[i] + 0.25 * oowp[i];
      printf("%0.8lf\n", rpi);
    }
  }

  return 0;
}
