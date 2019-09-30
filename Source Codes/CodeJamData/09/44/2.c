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
int n;
int x[MAX], y[MAX], r[MAX];

#define INF 1e20
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) < (y) ? (y) : (x))

int main ()
{
  int tests;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input
    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
      scanf("%d %d %d\n", &(x[i]), &(y[i]), &(r[i]));
    // solve
    double answer = 0.0;
    double minR = INF;
    switch (n) {
    case 1:
      answer = r[0];
      break;
    case 2:
      answer = max(r[0], r[1]);
      break;
    case 3:
      for (int i=0; i<n; i++) {
        answer = max(answer, r[i]);
        for (int j=i+1; j<n; j++) {
          double dx = x[i]-x[j];
          double dy = y[i]-y[j];
          double dist = sqrt(dx*dx+dy*dy);
          double R = (dist+r[i]+r[j]) / 2;
          minR = min(minR, R);
        }
      }
      answer = max(answer, minR);
      break;
    default:
      // can't solve n>3 right now !!!
      break;
    }
    // print
    printf("Case #%d: %.6lf\n", test, answer);
  }

  return 0;
}
