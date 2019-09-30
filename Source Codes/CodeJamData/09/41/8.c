#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define For(i,a,b) for (i = (a); i <= (b); i++)
#define Ford(i,a,b) for (i = (a); i >= (b); --i)
#define Rep(i,n) for (i = (0); i < (n); ++i)
#define Repd(i,n) for (i = ((n)-1); i >= 0; --i)

#define SCAN(t,x) scanf("%" #t,&(x))

#define Fill(a,c) memset(&a, c, sizeof(a))

#define MAX 42
int N;
char m[MAX][MAX];
int x[3*MAX];

void prt() {
  int i;
  printf("x:\n");
  Rep(i,N)
    printf("- %d\n",x[i]);
  printf("\n");
}

int solve(int i) {
  int j, t, k, tt;
  if (i>=N) return 0;
  if (x[i] <= i) return solve(i+1);
  for (j=i+1; j<N; j++)
    if (x[j] <= i) break;
  assert(x[j] <= i);
  /* prt(); */
  /* printf("i = %d, j = %d\n",i,j); */
  t = x[k = j];
  /* memmove(x+i+1,x+i,j-i); */
  for (j--;j>=i;j--)
    x[j+1] = x[j];
  x[i] = t;
  /* prt(); */
  return k-i+solve(i+1);
}

int main() {
  int t,T,i,j,p;
  scanf("%d",&T);
  For(t,1,T) {
    SCAN(d,N);
    Rep(i,N) scanf("%s",m[i]);
    Rep(i,N) {
      p = 0;
      Rep(j,N) {
        if (m[i][j]=='1') p = j;
      }
      x[i] = p;
    }
    printf("Case #%d: %d\n",t,solve(0));
  }
  return 0;
}
