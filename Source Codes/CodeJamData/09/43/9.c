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

int N,K;
int g[110][28];
int m[110][110];
int c[110];
int bs[110];
int maxc;

void compatible() {
  int i,j,k,t;
  Rep(i,N) Rep(j,N) m[i][j] = 0;
  Rep(i,N) {
    For(j,i+1,N-1) {
      if (g[i][0] > g[j][0]) t = 1;
      else if (g[i][0] < g[j][0]) t = 0;
      else { m[i][j] = m[j][i] = 1; continue; /* not compatible */ }
      Rep(k,K) {
        if ((g[i][k] == g[j][k]) ||
            (g[i][k] < g[j][k] && t == 1) ||
            (g[i][k] > g[j][k] && t == 0)) { 
          m[i][j] = m[j][i] = 1;
          break; 
        }
      }
    }
  }
}

int colorize(int i, int used) {
  int j,cc,bla,x;
  if (i>=N) return 1;
  x = (used+1 > maxc)? maxc:used+1;
  Rep(cc,x) {
    /* printf("%d,%d,%d,x=%d\n",i,cc,used,x); */
    bla = 1;
    Rep(j,N)
      if (m[i][j] && cc == c[j]) {
        bla = 0;
        break;
      }
    if (bla) {
      c[i] = cc;
      if (colorize(i+1, (cc+1>used)? cc+1 : used)) return 1;
    }
  }
  c[i] = -1;
  return 0;
}

int count() {
  int i, j, min, max;
  Rep(i,N) {
    min = 1;
    Rep(j,N) min += m[i][j];
    if (min > max) max = min;
  }
  min = 0;
  while (min < max) {
    maxc = (min + max + 1)/2;
    Rep(i,N) c[i] = -1;
    /* printf("(%d,%d): maxc = %d, ",min,max,maxc); */
    if (colorize(0,0)) {
      /* printf("1\n"); */
      max = maxc - 1;
    } else {
      /* printf("0\n"); */
      min = maxc;
    }
  }
  assert(min == max);
  maxc = min;
  assert(!colorize(0,0));
  maxc = min + 1;
  assert(colorize(0,0));
  return min+1;
  /* for(maxc = maxmax; maxc >=1; maxc--) {   */
  /*   Rep(i,N) c[i] = -1; */
  /*   ok = 1; */
  /*   Rep(i,N) */
  /*     if (!colorize(0)) { */
  /*       ok = 0; */
  /*       break; */
  /*     } */
  /*   if (ok) last = maxc; */
  /*   if (!ok && last) return last; */
  /* } */
  /* assert(0); */
}


void prt() {
  int i,j;
  Rep(i,N) Rep(j,N) printf(" %d%s",m[i][j],(j==N-1)?"\n":"");
}


int main() {
  int t,T,i,j;
  scanf("%d",&T);
  Rep(i,105) bs[i] = i;
  For(t,1,T) {
    SCAN(d,N);
    SCAN(d,K);
    Rep(i,N) Rep(j,K) SCAN(d,g[i][j]);
    compatible();
    /* prt(); */
    printf("Case #%d: %d\n",t,count());
  }
  return 0;
}
