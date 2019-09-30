#include <stdio.h>

#define ABS(X) ((X>=0)?(X):(-1*(X)))

int main() {
  int c,n,m,a;
  int t;
  int xa,ya,xb,yb,xc,yc;
  int ar;
  int nf;

  scanf("%d", &c);
  for (t=1;t<=c;t++) {
    scanf("%d%d%d", &n, &m, &a);
    printf("Case #%d: ",t);
    if (a>n*m) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    nf=1;
    for (xa=0;xa<=n && nf;xa++) {
      for (xb=0;xb<=n && nf;xb++) {
	for (xc=0;xc<=n && nf;xc++) {
	  for (ya=0;ya<=m && nf;ya++) {
	    for (yb=0;yb<=m && nf;yb++) {
	      for (yc=0;yc<=m && nf;yc++) {
		ar = ABS((xb*ya-xa*yb)+(xc*yb-xb*yc)+(xa*yc-xc*ya));
		if (ar==a) {
		  printf("%d %d %d %d %d %d\n",xa,ya,xb,yb,xc,yc);
		  nf=0;
		}
	      }
	    }
	  }
	}
      }
    }
    if (nf) printf("IMPOSSIBLE\n");
  }

  return 0;
}
