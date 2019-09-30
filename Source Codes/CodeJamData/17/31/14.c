#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x, y) (((x)>(y))?(x):(y))

typedef struct {
  int r;
  int h;
} pc;

static int cmp(const void *p1, const void *p2) {
//  return ((pc *) p1)->r == ((pc *) p2)->r ? ((pc *) p1)->h < ((pc *) p2)->h : ((pc *) p1)->r < ((pc *) p2)->r;
  return (long long) ((pc *) p1)->r * ((pc *) p1)->h < (long long) ((pc *) p2)->r * ((pc *) p2)->h;
}

pc A[1000];


int main(){
  int i, j, t;
  scanf("%d", &t);
  for(i=1;i<=t;i++){
    int n, k;
    long double max;
    scanf("%d%d\n", &n, &k);
    for(j=0;j<n;j++){
      scanf("%d%d\n", &(A[j].r), &(A[j].h));
    }
    qsort(A, n, sizeof(pc), cmp);

    max = 0;
    for(j=0;j<n;j++){
      int jj;
      int c = 1;
      int rmax = A[j].r;
      long double x = (long long) rmax * rmax + (long long) 2 * rmax * A[j].h;
      for(jj=0;jj<n && c < k;jj++){
        if(jj==j) continue;
        if(A[jj].r <= rmax){
          x += (long long) 2 * A[jj].r * A[jj].h;
          c++;
        }
      }
      max = MAX(max, x);
    }

    max *= M_PI;
    printf("Case #%d: %.10Lf\n", i, max);
  }
  return 0;
}
